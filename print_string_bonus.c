/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:49 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/26 14:21:38 by ydimitra         ###   ########.fr       */
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
			len = putnchar(*s, tab->precision);
		else
			len = putnchar(*s, len);
		len += putnchar(' ', tab->width - len);
	}
	else if (tab->width)
	{
		if (len < tab->width)
		{
			if (tab->precision)
			{
				len = putnchar(' ', tab->width - tab->precision);
				len += putnchar(*s, tab->precision);
			}
			else
			{
				len = putnchar(' ',tab->width - len);
				len += putnchar(*s, len);
			}	
			return (len);
		}
		else
			putnchar(*s, len);
	}
	return (len);
}
