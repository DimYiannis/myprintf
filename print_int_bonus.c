/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:44 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/27 16:03:14 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_sign(t_print *tab, int neg)
{
	if (neg)
		return write(1, "-", 1);
	if (tab->sign)
		return write(1, "+", 1);
	if (tab->sp)
		return write(1, " ", 1);
	return 0;
}

void	calc_width_precision(int len, t_print *tab, int neg, int *padding, int *zeros)
{
	*zeros = 0;
	if (tab->precision > len)
		*zeros = tab->precision - len;

	*padding = 0;
	if (tab->width > len + *zeros)
		*padding = tab->width - (len + *zeros);

	if (neg && tab->dash == 0 && tab->zero && tab->precision == 0)
		*padding -= 1;
}

int	int_case(t_print *tab)
{
	char	*tmp;
	int		num;
	int		len;
	int		padding;
	int		zeros;
	int		neg;

	num = va_arg(tab->args, int);
	neg = 0;
	if (num < 0)
	{
		num = -num;
		neg = 1;
	}

	tmp = ft_itoa(num);
	if (!tmp)
		return 0;

	len = ft_strlen(tmp);
	calc_width_precision(len, tab, neg, &padding, &zeros);

	if (!tab->dash && !tab->zero)
		tab->total_length += putchar_n(padding, ' ');

	tab->total_length += print_sign(tab, neg);

	if (!tab->dash && tab->zero && tab->precision == 0)
		tab->total_length += putchar_n(padding, '0');

	tab->total_length += putchar_n(zeros, '0');
	tab->total_length += putstring_n(tmp, len);

	if (tab->dash)
		tab->total_length += putchar_n(padding, ' ');

	free(tmp);
	return tab->total_length;
}

