/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:44 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/25 13:21:17 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_case(t_print *tab, char c)
{
	char	*tmp;
	int		len;
	char	ch;
	int		num;

    if (c == "i" || c == "d")
	{
		num = va_arg(tab->args, int);
		tmp = ft_itoa(num);
		if (!tmp)
			return (0);
		len = ft_strlen(tmp);
		if (tab->width)
		{
			if (len < tab->width)
			{
				len = write(1, " ", tab->width - len);
				len += write(1, &tmp, len);
			}
			else
				len = write(1, &tmp, len);
		}
		else if (tab->width && tab->sign)
		{
			if (num <= 0)
			{
				if (len < tab->width)
				{
					len = write(1, " ", tab->width - len);
					len += write(1, &tmp, len);
				}
				else
					len = write(1, &tmp, len);
			}
			else
			{
				if (len < tab->width)
				{
					len = write(1, " ", tab->width - len - 1);
					len += write(1, "+", 1);
					len += write(1, &tmp, len);
				}
				else
					len = write(1, &tmp, len);
			}
		}
		else if (tab->sp)
		{
			len = write(1, " ", 1);
			len += write(1, &tmp, len);
			if (tab->width)
			{
				if (len > tab->width)
					len = write(1, tmp, len);
				else
				{
					len = write(1, " ", tab->width - len);
					len += write(1, &tmp, len)
				}
			}
		}
		else if (tab->width && tab->zero)
    	{
        	write(1, "0", tab->width - len);
			write(1, tmp, len);
    	}
		else if (tab->width)
		{
			if (len < tab->width)
			{
				if (tab->precision)
				{
					len = write(1, " ", tab->width - tab->precision);
					if (len < tab->precision)
					{
						len += write(1, "0", tab->precision - len);
						len += write(1, s, len);
					}
					else
						len += write(1, s, len);
				}
				else
				{
					len = write(1," " ,tab->width - len)
					len += write(1, s, len);
				}	
				return (len);
			}
		}
		else if (tab->dash)
		{
			if (tab->width)
			{
				if (len < tab->width)
				{
					write(1, s, len);
					len += write(1, " ", tab->width - len);
				}
				else
					write(1, s, len);
			}
			else
				write(1, s, len);
		}
		write(1, tmp, len);
		free(tmp);
		return (len);
	}
}
