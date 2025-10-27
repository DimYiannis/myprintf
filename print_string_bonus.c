/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:49 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/27 14:41:24 by ydimitra         ###   ########.fr       */
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
		return (write(1, "(null)", 6));
	len = ft_strlen(s);
	if (tab->precision && tab->precision < len)
		len = tab->precision;
	if (tab->width > len)
		padding = tab->width - len;
	if (!tab->dash)
		tab->total_length += putchar_n(' ', padding);
	tab->total_length += putstring_n(s, len);
	if (tab->dash)
		tab->total_length += putchar_n(' ', padding);
	return (tab->total_length);
}
