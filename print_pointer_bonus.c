/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:46 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/24 12:11:36 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrputnbr(unsigned long n)
{
	char	*digits;
	int		len;

	len = 0;
	digits = "0123456789ABCDEF";

	if (n >= 16)
		len += ft_ptrputnbr(n / 16, upper);
	len += write(1, &digits[n % 16], 1);
	return (len);
}

int	pointer_case(va_list *args, char c)
{
	void *ptr;
	char *digits;
	int len;
	uintptr_t addr;

	if (c == 'p')
	{
		ptr = va_arg(*args, void *);
		int ft_addressputnbr(void *p)
		{
			addr = (uintptr_t)p;
			if (!addr)
				return (write(1, "(nil)", 5));
			write(1, "0x", 2);
			len = ft_ptrputnbr(addr, 0);
			return (len + 2);
		}
	}
}