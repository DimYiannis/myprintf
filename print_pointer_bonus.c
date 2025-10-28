/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:46 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/28 13:12:27 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_ptrputnbr(unsigned long n)
{
	char	*digits;
	int		len;

	len = 0;
	digits = "0123456789ABCDEF";
	if (n >= 16)
		len += ft_ptrputnbr(n / 16);
	len += write(1, &digits[n % 16], 1);
	return (len);
}

static int	count_hex_digits(uintptr_t n)
{
	int count;
	
	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	pointer_case(t_print *tab)
{
	void *ptr;
	int len;
	uintptr_t addr;
	int padding;
	int written;
	
	ptr = va_arg(tab->args, void *);
	addr = (uintptr_t)ptr;
	padding = 0;
	written = 0;
	if (!addr)
			return (write(1, "(nil)", 5));
	len = 2 + count_hex_digits(addr);
	if (len < tab->width)
		padding = tab->width - len;
	if (!tab->dash)
		written += putchar_n(' ', padding);
	
	written += write(1, "0x", 2);
	written += ft_ptrputnbr(addr);
	if (tab->dash)
		written += putchar_n(' ', padding);
	tab->total_length += written;
	return (written);
}
