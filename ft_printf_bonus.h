/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:17:48 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/26 16:29:35 by ydimitra         ###   ########.fr       */
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

int				char_case(t_print *tab, char c);
int				string_case(t_print *tab);
int				pointer_case(t_print *tab);
unsigned long	hex_case(t_print *tab, const char *c);
int				int_case(t_print *tab, char c);
int				unsigned_case(t_print *tab);
int	percent_case(t_print *tab, char c);
int				ft_printf_bonus(const char *type, ...);
unsigned int	eval_format(const char *c, t_print *tab);
int				width_zero(t_print *tab, char *tmp, int len);
int				prec(t_print *tab, char *tmp, int len);
int				dash_prec(t_print *tab, char *tmp, int len);
int				width_prec(t_print *tab, char *tmp, int len);
int				dash_prec(t_print *tab, char *tmp, int len);
int				hex_hash_width(t_print *tab, unsigned int n, char c);
unsigned int	hashflag(t_print *tab, unsigned int n, char c);
unsigned int	putnchar(char c, unsigned int n);
int				hex_dash_width_prec(t_print *tab, unsigned int n, char c);
int				hex_width_zero(t_print *tab, unsigned int n, char c);
unsigned int	no_hashflag(t_print *tab, unsigned int n, char c);
int				hash_dash_width_prec(t_print *tab, unsigned int n, char c);
int				hex_width_prec(t_print *tab, unsigned int n, const char c);
int				hex_precision(t_print *tab, unsigned int n, char c);
int				hex_len(unsigned int n);
int				count_digits(uintptr_t n);
int				dash_width_prec(t_print *tab, char *tmp, int len);

#endif