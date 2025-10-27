/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:44 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/27 16:33:23 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	int_case(t_print *tab)
{
	char	*tmp;
	int		len;
	int		num;
	int		padding;
	int		neg;

	neg = 0;
	num = va_arg(tab->args, int);
	if (num < 0)
	{
		num = -num;
		neg = 1;
		padding = -1;
	}
	tmp = ft_itoa(num);
	if (!tmp)
		return (0);
	len = ft_strlen(tmp);
	if (tab->precision && tab->precision < len)
		len = tab->precision;
	if (tab->width > len)
		padding = tab->width - len;
	if (!neg)
	{
		if (tab->sign)
			tab->total_length += write(1, "+", 1);
		else if (tab->sp)
			tab->total_length += write(1, " ", 1);
	}
	if (tab->precision > len)
	{
		tab->total_length += putchar_n('0', tab->precision - len);
		padding = padding - (tab->precision - len);
	}
	if (!tab->dash)
		tab->total_length += putchar_n(' ', padding);
	if (neg)
	{
		tab->total_length += write(1, "-", 1);
		padding--;
	}
	tab->total_length += putstring_n(tmp++, len);
	if (tab->dash)
		tab->total_length += putchar_n(' ', padding);
	return (tab->total_length);
}
