/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:22:42 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/23 20:33:03 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

static int	printing_int(char c, int num)
{
	int		len;
	char	*tmp;

	len = 0;
	if (num >= 0 && (c == ' ' || c == '+'))
		len += write(1, &c, 1);
	tmp = ft_itoa(num);
	if (!tmp)
		return (len);
	len += write(1, tmp, ft_strlen(tmp));
	free(tmp);
	return (len);
}

static int	check_convertion(va_list *args, const char *c)
{
	int	len;
	int	n;
	unsigned int	u;
	char flag;

	flag = 0;
	if (*c == ' ' || *c == '+')
	{
		flag = *c;
		c++;
	}
	if (*c == '#')
	{
		flag = '#';
		c++;
	}	
	len = 0;
	if  (*c == 'd' || *c == 'i')
	{
		n = va_arg(*args, int);
		if (flag == '+' && n >= 0)
			return (printing_int('+', n));
		else if (flag == ' ' && n >= 0)
			return (printing_int(' ', n));
		return (printing_int(0, n));
	}
	if (*c == 'x' || *c == 'X')
	{
		u = va_arg(*args, unsigned int);
		if (flag == '#' &&u != 0)
		{
			if (*c == 'x')
			{
				len += write(1, "0x", 2);
				return (len + ft_hexputnbr(u, 0));
			}
				
			else
			{
				len += write(1, "0X", 2);
				return (len + ft_hexputnbr(u, 1));
			}	
		}	
		return (len + ft_hexputnbr(u, (*c == 'X')));
	}
	return (0);
}

static int	unsigned_case(va_list *args, char c)
{
	char	*tmp;
	int		len;

	if (c == 'u')
	{
		tmp = ft_unsigneditoa(va_arg(*args, unsigned int));
		len = ft_strlen(tmp);
		write(1, tmp, len);
		free(tmp);
		return (len);
	}
	return (0);
}

static int	rest_cases(va_list *args, char c)
{
	char	*tmp;
	void	*ptr;
	char	ch;

	if (c == 'c')
	{
		ch = (char)va_arg(*args, int);
		return (write(1, &ch, 1));
	}
	else if (c == 's')
	{
		tmp = va_arg(*args, char *);
		if (!tmp)
			tmp = "(null)";
		return (write(1, tmp, ft_strlen(tmp)));
	}
	else if (c == 'p')
	{
		ptr = va_arg(*args, void *);
		return (ft_addressputnbr(ptr));
	}
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *type, ...)
{
	va_list	args;
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	va_start(args, type);
	while (type[i])
	{
		if (type[i] == '%' && type[i + 1])
		{
			i++;
			while (type[i] == ' ')
				i++;
			if (type[i] == ' ' || type[i] == '+' || type[i] == '#' || type[i] == 'd' || type[i] == 'i'|| type[i] == 'x' || type[i] == 'X')
					count += check_convertion(&args, &type[i]);
			else if (type[i] == 'u')
				count += unsigned_case(&args, type[i]);
			else
				count += rest_cases(&args, type[i]);
		}
		else
			count += write(1, &type[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
