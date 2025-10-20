/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:22:42 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/20 17:05:25 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int	ft_printf(const char *type, ...)
{
	va_list			args;
	size_t			count;
	size_t			i;
	size_t			len;
	unsigned int	n;
	char			*tmp;

	count = 0;
	i = 0;
	va_start(args, type);
	len = 0;
	while (type[i])
	{
		if (type[i] == '%')
		{
			i++;
			if (type[i] == 'd' || type[i] == 'i')
			{
				tmp = ft_itoa(va_arg(args, int));
				len = ft_strlen(tmp);
				count += len;
				write(1, tmp, len);
				i++;
			}
			else if (type[i] == 'u')
			{
				tmp = ft_unsigneditoa(va_arg(args, unsigned int));
				len = ft_strlen(tmp);
				count += len;
				write(1, tmp, len);
				i++;
			}
			else if (type[i] == 'x' || type[i] == 'X')
			{
				n = va_arg(args, unsigned int);
				if (type[i] == 'x')
					ft_hexputnbr(n, 0);
				else
					ft_hexputnbr(n, 1);
				len = count_digits(n);
				count += len;
				i++;
			}
			else if (type[i] == 's')
			{
				tmp = va_arg(args, char *);
				len = ft_strlen(tmp);
				count += len;
				write(1, tmp, len);
				i++;
			}
			else if (type[i] == 'c')
			{
				char c = (char)va_arg(args, int);
				write(1, &c, 1);
				count++;
				i++;
			}
			else if (type[i] == 'p')
			{
				ft_addressputnbr(va_arg(args, uintptr_t));
				len = address_len(va_arg(args, uintptr_t));
				count += len;
				i++;
			}
			else if (type[i] == '%')
			{
				write(1, &type[i], 1);
				count++;
				i++;
			}
		}
		write(1, &type[i], 1);
		i++;
		count++;
	}
	va_end(args);
	return (count);
}
