/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myheader.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:06:46 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/19 21:29:12 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MYHEADER_H
# define FT_MYHEADER_H
# include <stdio.h>
# include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

unsigned int	count_digits(unsigned int n);
char			*ft_unsigneditoa(unsigned int n);
void			ft_hexputnbr(int n, int upper);

#endif