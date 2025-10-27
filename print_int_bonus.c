/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:44 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/27 22:37:59 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int int_case(t_print *tab)
{
    char *tmp;
    int num, len;
    int padding, leading_zeros, neg;

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
    if (tab->precision == 0 && num == 0)
	{
		len = 0;
		tmp[0] = '\0';
	}
    leading_zeros = 0;
    if (tab->precision > len)
        leading_zeros = tab->precision - len;

    padding = tab->width - (len + leading_zeros);
    if (neg || tab->sign || tab->sp)
        padding--;
    if (padding < 0)
        padding = 0;

    if (!tab->dash && (!tab->zero || tab->precision > 0))
        tab->total_length += putchar_n(' ', padding);

    if (neg)
        tab->total_length += write(1, "-", 1);
    else if (tab->sign)
        tab->total_length += write(1, "+", 1);
    else if (tab->sp)
        tab->total_length += write(1, " ", 1);

    if (!tab->dash && tab->zero && tab->precision <= 0)
        tab->total_length += putchar_n('0', padding);
    tab->total_length += putchar_n('0', leading_zeros);

    tab->total_length += putstring_n(tmp, len);

    if (tab->dash)
        tab->total_length += putchar_n(' ', padding);

    free(tmp);
    return tab->total_length;
}
