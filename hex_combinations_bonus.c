/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_combinations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:46:41 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/25 22:49:49 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	hex_hash_width(unsigned int n, char c, t_print *tab)
{
	if (tab->hash)
	{
		if (len < tab->width)
		{
			len = putnchar(' ', tab->width - len);
			len += hashflag(n, c);
		}
		else
			len = hashflag(n, c);
	}
	else
	{
		if (len < tab->width)
		{
			len = putnchar(' ', tab->width - len);
			len += no_hashflag(n, c);
		}
		else
			len = no_hashflag(n, c);
	}
	return (len);
}

int	hex_dash_width_prec(unsigned int n, char c, t_print *tab)
{
	if (tab->width)
	{
		if (len < tab->width)
		{
			len += no_hashflag(n, c);
			len += putnchar(' ', tab->width - len);
		}
		else if (tab->precision)
		{
			if (len < tab->precision)
			{
				len += putnchar('0', tab->precision - len);
				len += no_hashflag(n, c);
				if (width > tab->precision)
					len += putnchar(' ', tab->width - tab->precision);
			}
			else
				len += no_hashflag(n, c);
		}
		else
			len += no_hashflag(n, c);
	}
	return (len);
}

int	hex_width_zero(char *tmp, int len, char c)
{
	if (tab->width)
	{
		if (len < tb->width)
		{
			len = putnchar('0', tab->width - len);
			len += no_hashflag(n, c);
		}
		else
			len = no_hashflag(n, c);
	}
	else if (tab->width && tab->hash)
	{
		if (len < tb->width)
		{
			len = putnchar('0', tab->width - len);
			len += hashflag(n, c);
		}
		else
			len = hashflag(n, c);
	}
	return (len);
}

int hex_precision(char *tmp, int len, char c)
{
	if (tab->hash)
	{
		len = putnchar('0', tab->width - tab->precision);
		if (len < tab->precision)
		{
			len += putnchar('0', tab->precision - len);
			len += hashflag(tmp, len);
		}
		else
			len += hashflag(tmp, len);
	}
	else
	{
		len = putnchar('0', tab->width - tab->precision);
		if (len < tab->precision)
		{
			len += putnchar('0', tab->precision - len);
			len += no_hashflag(tmp, len);
		}
		else
			len += no_hashflag(tmp, len);
	}
	return (len);
}

int	hex_width_prec(char *tmp, int len)
{
	if (tab->hash)
	{
		if (len < tab->width)
		{
			len = putnchar(' ', tab->width - tab->precision);
			if (len < tab->precision)
			{
				len += putnchar('0', tab->precision - len);
				len += hashflag(tmp, len);
			}
			else
				len += hashflag(tmp, len);
		}
		else
			len += hashflag(tmp, len);
	}
	else
	{
		if (len < tab->width)
		{
			len = putnchar(' ', tab->width - tab->precision);
			if (len < tab->precision)
			{
				len += putnchar('0', tab->precision - len);
				len += no_hashflag(tmp, len);
			}
			else
				len += no_hashflag(tmp, len);		
		}
		else
			len += no_hashflag(tmp, len);
	}
	return (len);
}

int	hash_dash_width_prec(unsigned int n, char c, t_print *tab)
{
	if (tab->hash)
	{
		if (len < tab->width)
		{
			len += hashflag(n, c);
			len += putnchar(' ', tab->width - len);
		}
		else if (tab->precision)
		{
			if (len < tab->precision)
			{
				len += putnchar('0', tab->precision - len);
				len += hashflag(n, c);
				if (width > tab->precision)
					len += putnchar(' ', tab->width - tab->precision);
			}
			else
				len += hashflag(n, c);
		}
		else
			len += hashflag(n, c);
	}
	else
	{
		if (len < tab->width)
		{
			len += no_hashflag(n, c);
			len += putnchar(' ', tab->width - len);
		}
		else if (tab->precision)
		{
			if (len < tab->precision)
			{
				len += putnchar('0', tab->precision - len);
				len += no_hashflag(n, c);
				if (width > tab->precision)
					len += putnchar(' ', tab->width - tab->precision);
			}
			else
				len += no_hashflag(n, c);
		}
		else
			len += no_hashflag(n, c);
	}
	return (len);
}
