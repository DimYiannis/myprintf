/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_combinations_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:14:46 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/27 10:13:32 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	width_prec(t_print *tab, char *tmp, int len)
{
	if (tab->width)
	{
		if (len < tab->width)
		{
			if (tab->precision)
			{
				len = putchar_n(' ', tab->width - tab->precision);
				if (len < tab->precision)
				{
					len += putchar_n('0', tab->precision - len);
					len += putstring_n(tmp, len);
				}
				else
					len += putstring_n(tmp, len);
			}
			else
			{
				len = putchar_n(' ', tab->width - len);
				len += putstring_n(tmp, len);
			}
		}
		else
			len += putstring_n(tmp, len);
	}
	return (len);
}

int	dash_width_prec(t_print *tab, char *tmp, int len)
{
	if (tab->dash)
	{
		if (tab->width)
		{
			if (len < tab->width)
			{
				putstring_n(tmp, len);
				len += putchar_n(' ', tab->width - len);
			}
			else if (tab->precision)
			{
				if (len < tab->precision)
				{
					len += putchar_n('0', tab->precision - len);
					len += putstring_n(tmp, len);
					if (tab->width > tab->precision)
						len += putchar_n(' ', tab->width - tab->precision);
				}
				else
					len += putstring_n(tmp, len);
			}
			else
				len = putstring_n(tmp, len);
		}
	}
	return (len);
}

int	prec(t_print *tab, char *tmp, int len)
{
	if (tab->precision)
	{
		len = putchar_n('0', tab->width - tab->precision);
		if (len < tab->precision)
		{
			len += putchar_n('0', tab->precision - len);
			len += putstring_n(tmp, len);
		}
		else
			len += putstring_n(tmp, len);
	}
	return (len);
}

int	width_zero(t_print *tab, char *tmp, int len)
{
	if (tab->width && tab->zero)
	{
		if (len < tab->width)
		{
			len = putchar_n('0', tab->width - len);
			len += putstring_n(tmp, len);
		}
		else
			len = putstring_n(tmp, len);
	}
	return (len);
}
int	dash_prec(t_print *tab, char *tmp, int len)
{
	if (tab->dash)
	{
		if (tab->precision)
		{
			if (len < tab->precision)
			{
				len += putchar_n('0', tab->precision - len);
				len += putstring_n(tmp, len);
			}
			else
				len += putstring_n(tmp, len);
		}
		else
			len = putstring_n(tmp, len);
	}
	return (len);
}
