/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:49 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/27 22:24:40 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	string_case(t_print *tab)
{
	int len;
	char *s;
	int padding;

	s = va_arg(tab->args, char *);
	if (!s)
	{
    	if (tab->precision >= 0 && tab->precision < 6)
    	{
        	len = 0;
        	s = "";
    	}
    	else
        s = "(null)";
	}	
	len = ft_strlen(s);
	if (tab->precision >= 0 && tab->precision < len)
		len = tab->precision;
	padding = 0;
	 if (tab->width > len)
        padding = tab->width - len;
	if (!tab->dash && padding > 0)
		tab->total_length += putchar_n(' ', padding);
	tab->total_length += putstring_n(s, len);
	if (tab->dash && padding > 0)
		tab->total_length += putchar_n(' ', padding);
	return (tab->total_length);
}
