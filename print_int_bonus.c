/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:44 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/27 23:48:29 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int int_case(t_print *tab)
{
    char	*tmp;
    int		num;
	int		len;
    int		padding;
	int		leading_zeros;
	int		neg;
	int		written;

	written = 0;
    num = va_arg(tab->args, int);
    neg = 0;
    if (num < 0)
    {
        num = -num;
        neg = 1;
    }
    tmp = ft_itoa(num);
    if (!tmp)
        return (0);
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
        written += putchar_n(' ', padding);
    if (neg)
        written += write(1, "-", 1);
    else if (tab->sign)
        written += write(1, "+", 1);
    else if (tab->sp)
        written += write(1, " ", 1);
    if (!tab->dash && tab->zero && tab->precision < 0)
        written += putchar_n('0', padding);
    written += putchar_n('0', leading_zeros);
    written += putstring_n(tmp, len);
    if (tab->dash)
        written += putchar_n(' ', padding);
    free(tmp);
    tab->total_length += written;
    return (written);
}