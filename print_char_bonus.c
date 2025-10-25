/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:55:33 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/25 17:29:42 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_case(t_print *tab, char c)
{
	if (tab->dash && tab->width)
	{
		write(1, &c, 1);
		putnchar( " ", tab->width);
	}
	else if (tab->width)
	{
		putnchar(' ', tab->width);
		write(1, &c, 1);
	}
	return (tab->width + 1);
}
