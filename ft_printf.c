/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:22:42 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/19 13:49:24 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>

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
					write(1, va_arg(args, char *)[j], 1);
					j++;
				}
				i++;
			}
			else if (type[i] == 'u')
			{
				len = ft_strlen(ft_unsigneditoa(va_arg(args, size_t)));
				count += len;
				while (j < len)
				{
					write(1, va_arg(args, char *)[j], 1);
					j++;
				}
				i++;
			}
			else if (type[i] == 'x' || type[i] == 'X')
			{
			}
			else if (type[i] == 's')
			{
				len = ft_strlen(va_arg(args, char *));
				count += len;
				while (j < len)
				{
					write(1, va_arg(args, char *)[j], 1);
					j++;
				}
				i++;
			}
			else if (type[i] == 'c')
			{
				write(1, va_arg(args, char));
				count++;
				i++;
			}
			else if (type[i] == 'p')
			{
			}
			else if (type[i] == '%')
			{
				write(1, '%', 1);
				count++;
			}
		}
		write(1, type[i], 1);
		i++;
		count++;
	}
	va_end(args);
	return (count);
}