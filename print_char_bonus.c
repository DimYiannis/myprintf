/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:55:33 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/26 22:04:12 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	char_case(t_print *tab, char c)
{
	int padding;
	
	padding = 0;
	if (tab->width > 1)
		padding = tab->width - 1;
	if (tab->dash)
	{
		write(1, &c, 1);
		putchar_n(' ', padding);
	}
	else
	{
		putchar_n(' ', padding);
		write(1, &c, 1);
	}
	if (tab->width > 1)
		return (tab->width + 1);
	return (1);
}
