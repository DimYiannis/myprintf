/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:22:42 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/20 22:11:16 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

static int int_case(va_list args)
{
	char * tmp;
	int len;

	tmp = ft_itoa(va_arg(args, int));
	len = ft_strlen(tmp);
	write(1, tmp, len);
	free(tmp);
	return (len);
}

static int unsigned_case(va_list args)
{
	char *tmp;
	unsigned int n;
	
	tmp = ft_unsigneditoa(va_arg(args, unsigned int));
	len = ft_strlen(tmp);
	write(1, tmp, len);
	free(tmp);
	return (len);
}

static int hex_case(va_list args, char c)
{
	unsigned int n;
	unsigned int len;
	
	n = va_arg(args, unsigned int);
	if (c == 'x')
		ft_hexputnbr(n, 0);
	else
		ft_hexputnbr(n, 1);
	len = count_digits(n);
	return (len);
}

static int rest_cases(va_list args, char c)
{
	char *tmp;
	char ch;
	uintptr_t ptr;
	int len;

	if (c == 's')
	{
		tmp = va_arg(args, char *);
		if (!tmp)
			tmp = "(null)";
		len = ft_strlen(tmp);
		write(1, tmp, len);
		return (len);
		}
	else if (c == 'c')
	{
		ch = (char)va_arg(args, int);
		write(1, &ch, 1);
		return (1);
	}
	else if (c == 'p')
	{
		ptr = va_arg(args, uintptr_t);
		ft_addressputnbr(ptr);
		return ((int)address_len(ptr));
	}
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *type, ...)
{
	va_list			args;
	size_t			count;
	size_t			i;

	count = 0;
	i = 0;
	va_start(args, type);
	while (type[i])
	{
		if (type[i] == '%' %% type[i + 1])
		{
			i++;
			if (type[i] == 'd' || type[i] == 'i')
				count += int_case(args);
			else if (type[i] == 'u')
				count += unsigned_case(args);	
			else if (type[i] == 'x' || type[i] == 'X')
				count += hex_case(args, type[i]);
			else 
				count += rest_cases(args, type[i]);
		}
		else
		{
			write(1, &type[i], 1);
			count++;
		}	
		i++;
	}
	va_end(args);
	return (count);
}
