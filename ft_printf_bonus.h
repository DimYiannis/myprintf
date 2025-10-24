/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:17:48 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/24 15:17:32 by ydimitra         ###   ########.fr       */
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
    int hash;
}   t_print;

int				char_case(char c);
int				string_case(va_list *args, char c);
int				pointer_case(va_list *args, char c);
int				hex_case(va_list *args, const char *c);
int				int_case(va_list *args, char c);
static int		unsigned_case(va_list *args, char c);
int				ft_printf_bonus(const char *type, ...);

#endif