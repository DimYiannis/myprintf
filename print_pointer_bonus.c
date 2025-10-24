/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:46 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/24 11:19:39 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer_case(va_list *args, char c)
{
	void	*ptr;

 if (c == 'p')
	{
		ptr = va_arg(*args, void *);
		return (ft_addressputnbr(ptr));
	}
}