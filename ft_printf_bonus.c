/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:16:10 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/27 11:13:35 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_print	*tab_initialise(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->dash = 0;
	tab->total_length = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->perc = 0;
	tab->sp = 0;
	tab->hash = 0;
	return (tab);
}
int	ft_printf(const char *type, ...)
{
	t_print	*tab;
	int		i;

	tab = malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	tab_initialise(tab);
	i = 0;
	va_start(tab->args, type);
	while (type[i])
	{
		if (type[i] == '%' && type[i + 1])
		{
			i += eval_format(&type[i + 1], tab);
			i++;
		}	
		else
		{
			tab->total_length += write(1, &type[i], 1);
			i++;
		}
	}
	va_end(tab->args);
	free(tab);
	return (tab->total_length);
}

unsigned int putchar_n(char c, unsigned int n)
{
    unsigned int i = 0;
    while (i < n)
    {
        write(1, &c, 1);
        i++;
    }
    return i;
}

unsigned int putstring_n(char *s, unsigned int n)
{
    unsigned int i = 0;
    if (!s)
        s = "(null)";
    while (s[i] && i < n)
    {
        write(1, &s[i], 1);
        i++;
    }
    return i;
}
