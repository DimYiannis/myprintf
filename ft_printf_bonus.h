/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:17:48 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/28 18:59:10 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <limits.h>

typedef struct s_print
{
	va_list		args;
	int			width;
	int			precision;
	int			zero;
	int			dash;
	int			total_length;
	int			sign;
	int			sp;
	int			hash;
	int			is_zero;
}				t_print;

typedef struct s_hexinfo
{
	int len;
	int zeros;
	int padding;
	int prefix;
	int upper;
}	t_hexinfo;

int				char_case(t_print *tab);
int				string_case(t_print *tab);
int				pointer_case(t_print *tab);
int	hex_case(t_print *tab, const char *c);
int				int_case(t_print *tab);
int				unsigned_case(t_print *tab);
int				percent_case(t_print *tab, char c);
int				ft_printf(const char *type, ...);
unsigned int	eval_format(const char *c, t_print *tab);
int				width_zero(t_print *tab, char *tmp, int len);
int				prec(t_print *tab, char *tmp, int len);
int				dash_prec(t_print *tab, char *tmp, int len);
int				width_prec(t_print *tab, char *tmp, int len);
int				dash_prec(t_print *tab, char *tmp, int len);
unsigned int	hashflag(t_print *tab, unsigned int n, char c);
unsigned int	putchar_n(char c, unsigned int n);
unsigned int	putstring_n(char *s, unsigned int n);
unsigned int	no_hashflag(t_print *tab, unsigned int n, char c);
int				hash_dash_width_prec(t_print *tab, unsigned int n, char c);
int				dash_width_prec(t_print *tab, char *tmp, int len);
char			*ft_unsigneditoa(unsigned int n);
int	count_decimal_digits(unsigned int n);
int	print_hex_right(t_print *tab, char *tmp, unsigned int num, t_hexinfo info);
int	print_hex_left(char *tmp, unsigned int num, t_hexinfo info);
int	print_main(char *tmp, int len, int zeros);
int	print_prefix(unsigned int num, int upper, int hash);




#endif