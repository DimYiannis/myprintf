/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_format_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:14:29 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/24 20:32:02 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

unsigned int	eval_format(char *c, t_print *tab)
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
		i += decide_conv(tab, c[i]);
	}
	return (i);
}

unsigned long	decide_conv(char *c, t_print *tab)
{
	unsigned long	count;

	count == 0;
	if (*c == 'd' || *c == 'i')
		i += int_case(args, *c);
	else if (*c == 'c')
		i += char_case(args, *c) else if (*c == 's') i += string_case(args, *c);
	else if (*c == 'x' || *c == 'X')
		i += hex_case(args, *c);
	else if (*c == 'p')
		i += pointer_case(va_list * args, char c);
	else if (*c == 'u')
		i += unsigned_case(va_list * args, char c);
	else if (*c == '%')
		i += write(1, "%", 1);
	return (i);
}

int	check_width_precision(t_print *tab, char *c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (ft_isdigit(c[i]))
	{
		n = n * 10 + c[i];
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
				n = n * 10 + c[i];
				tab->precision = n;
				i++;
			}
		}
	return (i);
}

int	check_form(t_print *struct, char c)
{
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
	if (ft_isdigit(c))
	{
		tab->width = c;
		i++;
	}
	return i;
}
