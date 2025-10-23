/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:22:42 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/23 18:56:31 by ydimitra         ###   ########.fr       */
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
	if (num >= 0)
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

	len = 0;
	if (*c == '#' && (*(c + 1) == 'x' || *(c + 1) == 'X'))
	{
		u = va_arg(*args, unsigned int);
		if (*(c + 1) == 'x')
		{
			len = write(1, "0x", 2);
			return (len + ft_hexputnbr(u, 0));
		}	
		else
		{
			len = write(1, "0x", 2);
			return (len + ft_hexputnbr(u, 1));
		}
	}
	if ((*c == ' ' || *c == '+') && (*(c + 1) == 'd' || *(c + 1) == 'i'))
	{
		n = va_arg(*args, int);
		return (printing_int(' ', n));
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
			if (type[i] == ' ' || type[i] == '+' || type[i] == '#')
				{
					count += check_convertion(&args, &type[i]);
					i++;
				}
			else if (type[i] == 'u')
				count += unsigned_case(&args, type[i]);
			else
				count += rest_cases(&args, type[i]);
		}
		else
			count += skip_char(&type[i]);
		i++;
	}
	va_end(args);
	return (count);
}
