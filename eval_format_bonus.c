/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_format_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:14:29 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/26 16:36:45 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int				check_width_precision(t_print *tab, const char *c);
unsigned long	decide_conv(const char *c, t_print *tab);

unsigned int	eval_format(const char *c, t_print *tab)
{
	unsigned int	i;

	i = 0;
	while (!ft_isalpha(c[i]))
	{
		i += check_width_precision(tab, c);
		if (c[i] == '-')
		{
			tab->dash = 1;
			i++;
		}
		if (c[i] == '0')
		{
			tab->zero = 1;
			i++;
		}
		if (ft_isalpha(c[i]) || c[i] == '%')
		{
			i += decide_conv(&c[i], tab);
			break ;
		}
	}
	return (i);
}

unsigned long	decide_conv(const char *c, t_print *tab)
{
	unsigned long	i;

	i = 0;
	if (*c == 'd' || *c == 'i')
		i += int_case(tab, *c);
	else if (*c == 'c')
		i += char_case(tab, *c);
	else if (*c == 's')
		i += string_case(tab);
	else if (*c == 'x' || *c == 'X')
		i += hex_case(tab, c);
	else if (*c == 'p')
		i += pointer_case(tab);
	else if (*c == 'u')
		i += unsigned_case(tab);
	else if (*c == '%')
		i += percent_case(tab, *c);
	return (i);
}

int	check_width_precision(t_print *tab, const char *c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (ft_isdigit(c[i]))
	{
		n = n * 10 + (c[i] - '0');
		tab->width = n;
		i++;
	}
	n = 0;
	if (c[i] == '.')
	{
		tab->pnt = 1;
		i++;
		while (ft_isdigit(c[i]))
		{
			n = n * 10 + (c[i] - '0');
			tab->precision = n;
			i++;
		}
	}
	return (i);
}

int	check_form(t_print *tab, char c)
{
	int	i;

	i = 0;
	if (c == ' ')
	{
		tab->sp = 1;
		i++;
	}
	if (c == '+')
	{
		tab->sign = 1;
		i++;
	}
	if (c == '#')
	{
		tab->hash = 1;
		i++;
	}
	if (ft_isdigit(c) && c != '0')
	{
		tab->width = (c - '0');
		i++;
	}
	return (i);
}
