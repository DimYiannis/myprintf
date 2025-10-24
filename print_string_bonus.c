/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:49 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/24 22:54:30 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			len = write(1, s, tab->precision);
		else
			len = write(1, s, len);
		len += write(1, " ", tab->width - len);
	}
	else if (tab->width)
	{
		if (len < tab->width)
		{
			if (tab->precision)
			{
				len = write(1, " ", tab->width - tab->precision);
				len += write(1, s, tab->precision);
			}
			else
			{
				len = write(1," ",tab->width - len)
				len += write(1, s, len);
			}	
			return (len);
		}
		else
			write(1, s, len);
	}
	return (len);
}
