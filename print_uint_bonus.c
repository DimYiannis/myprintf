/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:52 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/26 14:40:56 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_unsigneditoa(unsigned int n)
{
	char			*s;
	unsigned int	len;

	len = count_digits(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (len-- > 0)
	{
		s[len] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}

int	unsigned_case(t_print *tab)
{
	char	*tmp;
	int		len;

	tmp = ft_unsigneditoa(va_arg(tab->args, unsigned int));
	len = ft_strlen(tmp);
	if (tab->width)
		len = width_prec(tab, tmp, len);
	else if (tab->width && tab->zero)
		len = width_zero(tab, tmp, len);
	else if (tab->dash)
		len = dash_width_prec(tab, tmp, len);
	else if (tab->dash && tab->precision)
		len += dash_prec(tab, tmp, len);
	write(1, tmp, len);
	free(tmp);
	return (len);
}
