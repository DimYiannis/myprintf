/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:41 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/26 00:07:36 by ydimitra         ###   ########.fr       */
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

int hex_len(unsigned int n)
{
	int len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return len;
}

unsigned int	hashflag(unsigned int n, char c, t_print *tab)
{
	unsigned int	len;

	len = 0;
	if (tab->hash && n != 0)
	{
		if (c == 'x')
		{
			len += write(1, "0x", 2);
			return (len + ft_hexputnbr(n, 0));
		}
		else
		{
			len += write(1, "0X", 2);
			return (len + ft_hexputnbr(n, 1));
		}
	}
}

unsigned int	no_hashflag(unsigned int n, char c, t_print *tab)
{
	if (tab->hash && n != 0)
	{
		if (c == 'x')
			return (ft_hexputnbr(n, 0));
		else
			return (ft_hexputnbr(n, 1));
	}
}

unsigned long	hex_case(t_print *tab, const char *c)
{
	unsigned long	len;

	len = 0;
	if (*c == 'x' || *c == 'X')
	{
		u = va_arg(tab->args, unsigned int);
		if (tab->hash && u != 0)
			len = hashflag(u, *c, tab);
		else if ((tab->width && tab->hash) || tab->width)
			len = hex_hash_width(u, *c, tab);
		else if (tab->dash)
			len = hex_dash_width_prec(u, *c, tab);
		else if (tab->zero)
			len = hex_width_zero(u, *c, tab);
		else if (tab->precision)
			len = hex_precision(u, *c, tab);
		else if (tab->precision && tab->width)
			len = hex_width_prec(u, *c, tab);
		else if (tab->dash && tab->prec && tab->width)
			len = hash_dash_width_prec(u, *c, tab);
	}
	return (len);
}
