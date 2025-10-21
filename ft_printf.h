/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:06:46 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/21 20:43:10 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYHEADER_H
# define MYHEADER_H
# include "libft/libft.h"
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

unsigned int	count_digits(unsigned int n);
char			*ft_unsigneditoa(unsigned int n);
int             ft_hexputnbr(unsigned int n, int upper);
int	            ft_addressputnbr(void *p);
uintptr_t		address_len(uintptr_t n);
int				ft_printf(const char *type, ...);

#endif