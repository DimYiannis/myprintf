/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:41 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/24 14:31:09 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

unsigned long	ft_hexputnbr(unsigned long n, int upper)
{
	char	*digits;
	int		len;

	len = 0;
	if (upper)
		digits = "0123456789ABCDEF";
	if (!upper)
		digits = "0123456789abcdef";
	if (n >= 16)
		len += ft_hexputnbr(n / 16, upper);
	len += write(1, &digits[n % 16], 1);
	return (len);
}

unsigned long	hex_case(va_list *args, const char *c)
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
