/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:52 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/25 15:33:31 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_case(va_list *args, char c)
{
	char	*tmp;
	int		len;

	if (c == 'u')
	{
		tmp = ft_unsigneditoa(va_arg(*args, unsigned int));
		len = ft_strlen(tmp);
		if (tab->width)
			len = width_prec(tmp, len);
		else if (tab->width && tab->zero)
			len = width_zero(tmp, len);
		else if (tab->dash)
			len = dash_width_prec(tmp, len);
		else if (tab->dash && tab->precision)
			len += dash_prec(tmp, len);
		write(1, tmp, len);
		free(tmp);	
	}
	return (len);
}
