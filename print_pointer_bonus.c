/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:46 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/26 13:24:19 by ydimitra         ###   ########.fr       */
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

static int	count_digits(uintptr_t n)
{
	int count;
	
	count = 1;
    while (n >= 16)
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
	
	ptr = va_arg(tab->args, void *);
	addr = (uintptr_t)ptr;
	padding = 0;
	if (!addr)
			return (write(1, "(nil)", 5));
	len = 2 + count_digits(addr);
	if (len < tab->width)
		padding = tab->width - len;
	if (tab->dash)
	{
		len = write(1, "0x", 2);
		len += ft_ptrputnbr(addr);
		return (len + putnchar(' ', padding));
	}
	else
	{
		len =putnchar(' ', padding);
		len += write(1, "0x", 2);
		return (len + ft_ptrputnbr(addr));
	}
}
