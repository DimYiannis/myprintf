/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_combinations_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:14:46 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/25 18:23:07 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	width_prec(char *tmp, int len)
{
	if (tab->width)
	{
		if (len < tab->width)
		{
			if (tab->precision)
			{
				len = putnchar(' ', tab->width - tab->precision);
				if (len < tab->precision)
				{
					len += putnchar('0', tab->precision - len);
					len += putnchar(tmp, len);
				}
				else
					len += putnchar(tmp, len);
			}
			else
			{
				len = putnchar(' ', tab->width - len);
				len += putnchar(tmp, len);
			}
		}
		else
			len += putnchar(tmp, len);
	}
	return (len);
}

int	dash_width_prec(char *tmp, int len)
{
	if (tab->dash)
	{
		if (tab->width)
		{
			if (len < tab->width)
			{
				putnchar(s, len);
				len += putnchar(' ', tab->width - len);
			}
			else if (tab->precision)
			{
				if (len < tab->precision)
				{
					len += putnchar('0', tab->precision - len);
					len += putnchar(tmp, len);
					if (width > tab->precision)
						len += putnchar(' ', width - tab->precision);
				}
				else
					len += putnchar(tmp, len);
			}
			else
				len = putnchar(s, len);
		}
	}
	return (len);
}

int	prec(char *tmp, int len)
{
	if (tab->precision)
	{
		len = putnchar('0', tab->width - tab->precision);
		if (len < tab->precision)
		{
			len += putnchar('0', tab->precision - len);
			len += putnchar(tmp, len);
		}
		else
			len += putnchar(tmp, len);
	}
	return (len);
}

int	width_zero(char *tmp, int len)
{
	if (tab->width && tab->zero)
	{
		if (len < tb->width)
		{
			len = putnchar('0', tab->width - len);
			len += putnchar(tmp, len);
		}
		else
			len = putnchar(tmp, len);
	}
	return (len);
}
int	dash_prec(char *tmp, int len)
{
	if (tab->dash)
	{
		if (tab->precision)
		{
			if (len < tab->precision)
			{
				len += putnchar('0', tab->precision - len);
				len += putnchar(tmp, len);
			}
			else
				len += putnchar(tmp, len);
		}
		else
			len = putnchar(tmp, len);
	}
	return (len);
}
