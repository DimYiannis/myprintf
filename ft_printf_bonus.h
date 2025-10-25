/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:17:48 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/25 18:31:59 by ydimitra         ###   ########.fr       */
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
	va_list		args;
	int			width;
	int			precision;
	int			zero;
	int			pnt;
	int			dash;
	int			total_length;
	int			sign;
	int			is_zero;
	int			perc;
	int			sp;
	int			hash;
}				t_print;

int				char_case(char c);
int				string_case(va_list *args, char c);
int				pointer_case(va_list *args, char c);
int				hex_case(va_list *args, const char *c);
int				int_case(va_list *args, char c);
static int		unsigned_case(va_list *args, char c);
int				ft_printf_bonus(const char *type, ...);
int				width_zero(char *tmp, int len);
int				prec(char *tmp, int len);
int				dash_width_prec(char *tmp, int len);
int				width_prec(char *tmp, int len);
int				dash_prec(char *tmp, int len);
int				hex_hash_width(unsigned int n, char c);
int				hex_width(unsigned int n, char c);
unsigned int	hashflag(unsigned int n, char c);
unsigned int	putnchar(char c, unsigned int n);
int				hex_dash_width_prec(unsigned int n, char c, t_print *tab);
int				hex_width_zero(char *tmp, int len);
unsigned int	no_hashflag(unsigned int n, char c, t_print *tab);

#endif