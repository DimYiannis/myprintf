/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_format_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:14:29 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/24 14:14:14 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

unsigned int	eval_format(char *c, t_print *tab)
{
	unsigned int	i;

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
	return (i);
}

void decide_conv(char *c, t_print *tab)
{
	unsigned int i

	i == 0;
	if (*c == 'd' || *c == 'i')
		i += int_case(args, *c);
	else if (*c == 'c')
		i += char_case(args, *c)
	else if (*c == 's')
		i += string_case(args, *c);
	else if (*c == 'x' || *c == 'X')
		i += hex_case(args, *c);
	else if (*c == 'p')
		i += pointer_case(va_list *args, char c);
	else if (*c == 'u')
		i += unsigned_case(va_list *args, char c);
	return (i);
}
