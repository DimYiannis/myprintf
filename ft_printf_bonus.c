/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:16:10 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/24 13:56:14 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_print	*tab_initialise(t_print tab)
{
	tab->width;
	tab->percision;
	tab->zero;
	tab->pnt;
	tab->dash;
	tab->total_length;
	tab->sign;
	tab->is_zero;
	tab->perc;
	tb->sp;
	return (tab);
}
int	ft_printf_bonus(const char *type, ...)
{
	t_print	*tab;
	int		count;
	int		i;

	tab = malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	tab_initialise(tab);
	count = 0;
	i = 0;
	va_start(tab->args, type);
	while (type[i])
	{
		if (type[i] == '%' && type[i + 1])
			i = eval_format(type[i], tab);
		else
			count += write(&type[i], 1);
	}
	va_end(tab->args);
	count += tab->total_length;
	free(tab);
	return (count);
}
