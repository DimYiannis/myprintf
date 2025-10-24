/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:41 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/24 10:05:57 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_case(va_list *args, const char *c, size_t *tranversed)
{
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
