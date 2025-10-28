/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:44 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/28 12:58:31 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int handle_neg(int *num)
{
    int neg;

    neg = 0;
    if (*num < 0)
    {
        *num = -*num;
        neg = 1;
    }
    return (neg);
}

static int get_padding(t_print *tab, int len, int leading_zeros, int neg)
{
    int padding;

    padding = tab->width - (len + leading_zeros);
    if (neg || tab->sign || tab->sp)
        padding--;
    if (padding < 0)
        padding = 0;
    return (padding);
}

static int print_padd_sign(t_print *tab, int padding, int neg)
{
    int written;

    written = 0;
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
    return (written);
}

static int print_num_space(t_print *tab, char *tmp, int len, int leading_zeros, int padding)
{
    int written;

    written = 0;
    written += putchar_n('0', leading_zeros);
    written += putstring_n(tmp, len);
    if (tab->dash)
        written += putchar_n(' ', padding);
    return (written);
}

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
    neg = handle_neg(&num);
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
    padding = get_padding(tab, len, leading_zeros, neg);
    written = print_padd_sign(tab, padding, neg);
    written += print_num_space(tab, tmp, len, leading_zeros, padding);
    free(tmp);
    tab->total_length += written;
    return (written);
}
