/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_combinations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:46:41 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/27 10:08:16 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	hex_hash_width(t_print *tab, unsigned int n, char c)
{
	int len;

	len = hex_len(n);
	if (tab->hash)
	{
		if (len < tab->width)
		{
			len = putchar_n(' ', tab->width - len);
			len += hashflag(tab, n, c);
		}
		else
			len = hashflag(tab, n, c);
	}
	else
	{
		if (len < tab->width)
		{
			len = putchar_n(' ', tab->width - len);
			len += no_hashflag(tab, n, c);
		}
		else
			len = no_hashflag(tab, n, c);
	}
	return (len);
}

int	hex_dash_width_prec(t_print *tab, unsigned int n, char c)
{
	int len;
	
	len = hex_len(n);
	if (tab->width)
	{
		if (len < tab->width)
		{
			len = no_hashflag(tab, n, c);
			len += putchar_n(' ', tab->width - len);
		}
		else if (tab->precision)
		{
			if (len < tab->precision)
			{
				len = putchar_n('0', tab->precision - len);
				len += no_hashflag(tab, n, c);
				if (tab->width > tab->precision)
					len += putchar_n(' ', tab->width - tab->precision);
			}
			else
				len = no_hashflag(tab, n, c);
		}
		else
			len = no_hashflag(tab, n, c);
	}
	return (len);
}

int	hex_width_zero(t_print *tab, unsigned int n, char c)
{
	int len;
	
	len = hex_len(n);
	if (tab->width)
	{
		if (len < tab->width)
		{
			len = putchar_n('0', tab->width - len);
			len += no_hashflag(tab, n, c);
		}
		else
			len = no_hashflag(tab, n, c);
	}
	else if (tab->width && tab->hash)
	{
		if (len < tab->width)
		{
			len = putchar_n('0', tab->width - len);
			len += hashflag(tab, n, c);
		}
		else
			len = hashflag(tab, n, c);
	}
	return (len);
}

int hex_precision(t_print *tab,  unsigned int n, char c)
{
	int len; 
	
	hex_len(n);
	if (tab->hash)
	{
		len = putchar_n('0', tab->width - tab->precision);
		if (len < tab->precision)
		{
			len += putchar_n('0', tab->precision - len);
			len += hashflag(tab, len, c);
		}
		else
			len += hashflag(tab, len, c);
	}
	else
	{
		len = putchar_n('0', tab->width - tab->precision);
		if (len < tab->precision)
		{
			len += putchar_n('0', tab->precision - len);
			len += no_hashflag(tab, len, c);
		}
		else
			len += no_hashflag(tab, len, c);
	}
	return (len);
}

int	hex_width_prec(t_print *tab,  unsigned int n, const char c)
{
	int len;

	len = hex_len(n);
	if (tab->hash)
	{
		if (len < tab->width)
		{
			len = putchar_n(' ', tab->width - tab->precision);
			if (len < tab->precision)
			{
				len += putchar_n('0', tab->precision - len);
				len += hashflag(tab, n, c);
			}
			else
				len += hashflag(tab, n, c);
		}
		else
			len = hashflag(tab, n, c);
	}
	else
	{
		if (len < tab->width)
		{
			len = putchar_n(' ', tab->width - tab->precision);
			if (len < tab->precision)
			{
				len += putchar_n('0', tab->precision - len);
				len += no_hashflag(tab, n, c);
			}
			else
				len += no_hashflag(tab, n, c);		
		}
		else
			len = no_hashflag(tab, n, c);
	}
	return (len);
}

int	hash_dash_width_prec(t_print *tab, unsigned int n, char c)
{
	int len;
	
	len = hex_len(n);
	if (tab->hash)
	{
		if (len < tab->width)
		{
			len = hashflag(tab, n, c);
			len += putchar_n(' ', tab->width - len);
		}
		else if (tab->precision)
		{
			if (len < tab->precision)
			{
				len = putchar_n('0', tab->precision - len);
				len += hashflag(tab, n, c);
				if (tab->width > tab->precision)
					len += putchar_n(' ', tab->width - tab->precision);
			}
			else
				len = hashflag(tab, n, c);
		}
		else
			len = hashflag(tab, n, c);
	}
	else
	{
		if (len < tab->width)
		{
			len += no_hashflag(tab, n, c);
			len += putchar_n(' ', tab->width - len);
		}
		else if (tab->precision)
		{
			if (len < tab->precision)
			{
				len += putchar_n('0', tab->precision - len);
				len += no_hashflag(tab, n, c);
				if (tab->width > tab->precision)
					len += putchar_n(' ', tab->width - tab->precision);
			}
			else
				len += no_hashflag(tab, n, c);
		}
		else
			len += no_hashflag(tab, n, c);
	}
	return (len);
}
