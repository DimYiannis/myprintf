/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:14:36 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/26 13:15:12 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:55:33 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/24 22:11:18 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	percent_case(t_print *tab, char c)
{
	if (tab->dash && tab->width)
	{
		write(1, &c, 1);
		putnchar(1, ' ', tab->width - 1);
	}
	else if (tab->width && tab->zero)
    {
        putnchar(1, '0', tab->width - 1);
		write(1, &c, 1);
    }
	else if (tab->width)
	{
		putnchar(1, ' ', tab->width - 1);
		write(1, &c, 1);
	}
	else
		write(1, &c, 1);
	return (tab->width + 1);
}
