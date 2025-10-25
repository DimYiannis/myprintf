/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:55:33 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/25 23:48:02 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_case(t_print *tab, char c)
{
	int padding;
	
	padding = 0;
	if (tab->width > 1)
		padding = tab->width - 1;
	if (tab->dash)
	{
		write(1, &c, 1);
		putnchar(' ', padding);
	}
	else
	{
		putnchar(' ', padding);
		write(1, &c, 1);
	}
	if (tab->witdh > 1)
		return (tab->width + 1);
	return (1);
}
