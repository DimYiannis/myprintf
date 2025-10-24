/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:55:33 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/24 20:33:53 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	char_case(va_list *args, char c)
{
	char	*tmp;
	void	*ptr;
	char	ch;

	if (c == 'c')
	{
		ch = (char)va_arg(*args, int);
		if (tab->dash && tab->width)
		{
			write(1, &ch, 1);
			write(1, " ", tab->width);
		}
		else if (tab->width)
		{
			write(1, " ", tab->width);
			write(1, &ch, 1);
		}
		return (tab->width + 1);
	}
	return (0);
}
