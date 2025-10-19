/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:22:42 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/19 21:45:56 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include "myheader.h"

int	ft_printf(const char *type, ...)
{
	va_list args;
	size_t count;
	size_t i;
	size_t len;
	size_t j;

	count = 0;
	i = 0;
	j = 0;
	va_start(args, type);
	len = 0;
	while (type[i])
	{
		if (type[i] == '%')
		{
			i++;
			if (type[i] == 'd' || type[i] == 'i')
			{
				len = ft_strlen(ft_itoa(va_arg(args, int)));
				count += len;
				while (j < len)
				{
					write(1, &va_arg(args, char *)[j], 1);
					j++;
				}
				i++;
                j = 0;
			}
			else if (type[i] == 'u')
			{
                unsigned int n = va_arg(args, unsigned int);
                char *tmp = ft_unsigneditoa(n);
				len = ft_strlen(tmp);
				count += len;
				while (j < len)
				{
					write(1, &tmp[j], 1);
					j++;
				}
				i++;
                j = 0;
			}
			else if (type[i] == 'x' || type[i] == 'X')
			{
                if (type[i] == 'x')
                    ft_hexputnbr(va_arg(args, int), 0);
                else
                    ft_hexputnbr(va_arg(args, int), 1);
                len = count_digits(va_arg(args, int));
                count += len;
			}
			else if (type[i] == 's')
			{
				len = ft_strlen(va_arg(args, char *));
				count += len;
				while (j < len)
				{
					write(1, &va_arg(args, char *)[j], 1);
					j++;
				}
				i++;
                j = 0;
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
                len = ft_strlen(va_arg(args, char *));
				count += len;
				while (j < len)
				{
					write(1, &va_arg(args, char *)[j], 1);
					j++;
				}
				i++;
                j = 0;
			}
			else if (type[i] == '%')
			{
                char c = '%';
				write(1, &c, 1);
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
