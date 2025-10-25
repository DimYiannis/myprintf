/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_combinations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:46:41 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/25 16:27:06 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

unsigned int	hashflag(unsigned int n, char c)
{
	unsigned int	len;

	len = 0;
	if (tab->hash && n != 0)
	{
		if (c == 'x')
		{
			len += write(1, "0x", 2);
			return (len + ft_hexputnbr(n, 0));
		}
		else
		{
			len += write(1, "0X", 2);
			return (len + ft_hexputnbr(n, 1));
		}
	}
}

int	hex_width(unsigned int n, char c)
{
	if (tab->width)
	{
		if (len < tab->width)
		{
			len = write(1, " ", tab->width - len);
			if (c == 'x')
				len = ft_hexputnbr(n, 0);
			else
				len = ft_hexputnbr(n, 1);
		}
		else
		{
			if (c == 'x')
				len = ft_hexputnbr(n, 0);
			else
				len = ft_hexputnbr(n, 1);
		}
	}
}

int	hex_hash_width(unsigned int n, char c)
{
	if (tab->width)
	{
		if (len < tab->width)
		{
			len = write(1, " ", tab->width - len);
			len += hashflag(n, c);
		}
		else
			len = hashflag(n, c);
	}
}
