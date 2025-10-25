/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:41 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/25 16:30:08 by ydimitra         ###   ########.fr       */
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

unsigned long	hex_case(args, const char *c)
{
	unsigned long	len;

	len = 0;
	if (*c == 'x' || *c == 'X')
	{
		u = va_arg(*args, unsigned int);
		if (tab->hash && u != 0)
			hashflag(u, *c);
		else if (tab->width && tab->hash)
			hex_hash_width(u, *c)
	}
	return (len);
}
