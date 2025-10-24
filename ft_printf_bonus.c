/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:16:10 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/24 11:20:59 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_bonus(const char *type, ...)
{
	va_list	args;
	size_t	count;
	size_t	i;
	size_t tranversed;

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
					{
						count += check_convertion(&args, &type[i], &tranversed);
						i += tranversed;
						break;
					}
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