/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:17:48 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/24 11:36:16 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "libft/libft.h"
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_print
{
    va_list args;
    int width;
    int percision;
    int zero;
    int pnt;
    int dash;
    int total_length;
    int sign;
    int is_zero;
    int perc:
    int sp;
}   t_print;

unsigned int	count_digits(unsigned int n);
char			*ft_unsigneditoa(unsigned int n);
int				ft_hexputnbr(unsigned int n, int upper);
int				ft_addressputnbr(void *p);
uintptr_t		address_len(uintptr_t n);
int				ft_printf(const char *type, ...);
int				rest_cases(char c);
int				string_case(va_list *args, char c);
int				pointer_case(va_list *args, char c);
int				hex_case(va_list *args, const char *c, size_t *tranversed);
int				int_case(va_list *args, char c);
static int		unsigned_case(va_list *args, char c);
int				ft_printf_bonus(const char *type, ...);

#endif