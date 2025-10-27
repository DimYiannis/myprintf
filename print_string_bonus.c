/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:49 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/26 22:08:42 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	string_case(t_print *tab)
{
	int len;
	char *s;

	s = va_arg(tab->args, char *);
	if (!s)
		return (write(1, "(null)", 6));
	len = ft_strlen(s);
	if (tab->dash && tab->width)
	{
		if (tab->precision)
			len = putstring_n(s, tab->precision);
		else
			len = putstring_n(s, len);
		len += putchar_n(' ', tab->width - len);
	}
	else if (tab->width)
	{
		if (len < tab->width)
		{
			if (tab->precision)
			{
				len = putchar_n(' ', tab->width - tab->precision);
				len += putstring_n(s, tab->precision);
			}
			else
			{
				len = putchar_n(' ',tab->width - len);
				len += putstring_n(s, len);
			}	
			return (len);
		}
		else
			putstring_n(s, len);
	}
	return (len);
}
