/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:14:46 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/25 15:28:43 by ydimitra         ###   ########.fr       */
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
				len = write(1, " ", tab->width - tab->precision);
				if (len < tab->precision)
				{
					len += write(1, "0", tab->precision - len);
					len += write(1, tmp, len);
				}
				else
					len += write(1, tmp, len);
			}
			else
			{
				len = write(1, " ", tab->width - len);
				len += write(1, tmp, len);
			}
		}
		else
			len = write(1, &tmp, len);
	}
}

int	dash_width_prec(char *tmp, int len)
{
	if (tab->dash)
	{
		if (tab->width)
		{
			if (len < tab->width)
			{
				write(1, s, len);
				len += write(1, " ", tab->width - len);
			}
			else if (tab->precision)
			{
				if (len < tab->precision)
				{
					len += write(1, "0", tab->precision - len);
					len += write(1, tmp, len);
					if (width > tab->precision)
						len += write(1, " ", width - tab->precision);
				}
				else
					len += write(1, tmp, len);
			}
			else
				write(1, s, len);
		}
	}
}

int	prec(char *tmp, int len)
{
	if (tab->precision)
	{
		len = write(1, "0", tab->width - tab->precision);
		if (len < tab->precision)
		{
			len += write(1, "0", tab->precision - len);
			len += write(1, tmp, len);
		}
		else
			len += write(1, tmp, len);
	}
}

int	width_zero(char *tmp, int len)
{
	if (tab->width && tab->zero)
	{
		if (len < tb->width)
		{
			len = write(1, "0", tab->width - len);
			len += write(1, tmp, len);
		}
		else
			write(1, tmp, len);
	}
}
int	dash_prec(char *tmp, int len)
{
	if (tab->dash)
	{
		if (tab->precision)
		{
			if (len < tab->precision)
			{
				len += write(1, "0", tab->precision - len);
				len += write(1, tmp, len);
			}
			else
				len += write(1, tmp, len);
		}
		else
			write(1, s, len);
	}
}