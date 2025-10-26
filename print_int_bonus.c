/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:44 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/26 14:16:16 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	int_case(t_print *tab, char c)
{
	char	*tmp;
	int		len;
	int		num;

	num = va_arg(tab->args, int);
	tmp = ft_itoa(num);
	if (!tmp)
		return (0);
	len = ft_strlen(tmp);
	if (c == 'i' || c == 'd')
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
						len += putnchar(' ', tab->precision - len);
						len += putnchar(*tmp, len);
					}
					else
						len += putnchar(*tmp, len);
				}
				else
				{
					len = putnchar(' ', tab->width - len);
					len += putnchar(*tmp, len);
				}
			}
			else
				len = putnchar(*tmp, len);
		}
		else if (tab->width && tab->sign)
		{
			if (num <= 0)
			{
				if (len < tab->width)
				{
					len = putnchar(' ', tab->width - len);
					len += putnchar(*tmp, len);
				}
				else
					len = putnchar(*tmp, len);
			}
			else
			{
				if (len < tab->width)
				{
					len = putnchar(' ', tab->width - len - 1);
					len += write(1, "+", 1);
					len += putnchar(*tmp, len);
				}
				else
					len = putnchar(*tmp, len);
			}
		}
		else if (tab->sp)
		{
			len = write(1, " ", 1);
			len += putnchar(*tmp, len);
			if (tab->width)
			{
				if (len > tab->width)
					len = putnchar(*tmp, len);
				else
				{
					len = putnchar(' ', tab->width - len);
					len += putnchar(*tmp, len);
				}
			}
		}
		else if (tab->width && tab->zero)
		{
			len = putnchar('0', tab->width - len);
			len += putnchar(*tmp, len);
		}
		else if (tab->dash)
		{
			if (tab->width)
			{
				if (len < tab->width)
				{
					putnchar(*tmp, len);
					len += putnchar(' ', tab->width - len);
				}
				else
					putnchar(*tmp, len);
			}
			else
				putnchar(*tmp, len);
		}
	}
	putnchar(*tmp, len);
	free(tmp);
	return (len);
}
