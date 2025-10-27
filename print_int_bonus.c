/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:44 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/26 22:35:59 by ydimitra         ###   ########.fr       */
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
	if (tab->width > len && tab->dash == 0)
	{
		if (tab->zero && !tab->pnt)
			tab->total_length += putchar_n('0', tab->width - len);
		else
			tab->total_length += putchar_n(' ', tab->width - len);
	}
	if (tab->sign && num > 0)
		tab->total_length += write(1, "+", 1);
	else if (tab->sp && num >= 0)
		tab->total_length += write(1," ", 1);
	
	tab->total_length += putstring_n(tmp, len);
	if (tab->width > len && tab->dash == 1)
		tab->total_length += putchar_n(' ', tab->width - len);
	free(tmp);
	return (tab->total_length);
}
