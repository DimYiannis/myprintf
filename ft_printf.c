/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:22:42 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/21 22:16:44 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

static int	intandc_case(va_list *args, char c)
{
	char	*tmp;
	int		len;
	char	ch;
	int num;

	if (c == 'c')
	{
		ch = (char)va_arg(*args, int);
		return (write(1, &ch, 1));
	}
	else
	{
		num = va_arg(*args, int);
		tmp = ft_itoa(num);
		if (!tmp)
			return (0);
		len = ft_strlen(tmp);
		write(1, tmp, len);
		free(tmp);
		return (len);
	}
	return (0);
}

static int	unsignedandhex_case(va_list *args, char c)
{
	char			*tmp;
	int				len;
	unsigned int	n;

	if (c == 'u')
	{
		tmp = ft_unsigneditoa(va_arg(*args, unsigned int));
		len = ft_strlen(tmp);
		write(1, tmp, len);
		free(tmp);
		return (len);
	}
	else if (c == 'x' || c == 'X')
	{
		n = va_arg(*args, unsigned int);
		if (c == 'x')
			return (ft_hexputnbr(n, 0));
		else
			return (ft_hexputnbr(n, 1));
	}
	return (0);
}

static int	rest_cases(va_list *args, char c)
{
	char	*tmp;
	void	*ptr;
	int		len;

	if (c == 's')
	{
		tmp = va_arg(*args, char *);
		if (!tmp)
			tmp = "(null)";
		len = ft_strlen(tmp);
		return (write(1, tmp, len));
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
			if (type[i] == 'd' || type[i] == 'i' || type[i] == 'c')
				count += intandc_case(&args, type[i]);
			else if (type[i] == 'u' || type[i] == 'x' || type[i] == 'X')
				count += unsignedandhex_case(&args, type[i]);
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
