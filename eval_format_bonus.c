/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_format_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:14:29 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/24 12:25:07 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	eval_format(char *c, t_print *tab)
{
	int	i;

	i = 0;
	while (!ft_isalpha(c[i]))
	{
		if (c[i] == '.')
		{
			tab->pnt = 1;
			i++;
		}
		if (c[i] == '-')
		{
			tab->dash = 1;
			i++;
		}
		if (c(i) == '0')
		{
			tab->zero = 1;
			i++;
		}
	}
}
