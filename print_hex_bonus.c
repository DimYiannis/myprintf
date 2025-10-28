/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:41 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/28 18:52:56 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	count_hex_digits(unsigned int n)
{
	int count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static void	fill_hex_string(char *s, unsigned int n, char *digits, int len)
{
	int i;

	i = len;
	while (i > 0)
	{
		i--;
		s[i] = digits[n % 16];
		n /= 16;
	}
}

static char	*ft_hextoa(unsigned int n, int upper)
{
	char	*digits;
	char	*s;
	int		len;

	if (upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len = count_hex_digits(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n == 0)
		s[0] = '0';
	else
		fill_hex_string(s, n, digits, len);
	return (s);
}

static t_hexinfo	compute_hexinfo(t_print *tab, unsigned int num, int upper)
{
	t_hexinfo info;

	info.upper = upper;
	info.len = ft_strlen(ft_hextoa(num, upper));
	if (tab->precision == 0 && num == 0)
		info.len = 0;
	info.zeros = 0;
	if (tab->precision > info.len)
		info.zeros = tab->precision - info.len;
	info.prefix = 0;
	if (tab->hash && num != 0)
		info.prefix = 2;
	info.padding = tab->width - (info.len + info.zeros + info.prefix);
	if (info.padding < 0)
		info.padding = 0;
	return (info);
}

int	hex_case(t_print *tab, const char *c)
{
	char			*tmp;
	unsigned int	num;
	t_hexinfo		info;
	int				written;

	num = va_arg(tab->args, unsigned int);
	info.upper = (*c == 'X');
	tmp = ft_hextoa(num, info.upper);
	if (!tmp)
		return (0);
	if (tab->precision == 0 && num == 0)
		tmp[0] = '\0';
	info = compute_hexinfo(tab, num, info.upper);
	if (tab->dash)
		written = print_hex_left(tmp, num, info);
	else
		written = print_hex_right(tab, tmp, num, info);
	free(tmp);
	tab->total_length += written;
	return (written);
}

// static int	count_hex_digits(unsigned int n)
// {
// 	int count;
	
// 	if (n == 0)
// 		return (1);
// 	count = 0;
// 	while (n > 0)
// 	{
// 		n /= 16;
// 		count++;
// 	}
// 	return (count);
// }

// static void	fill_hex_string(char *s, unsigned int n, char *digits, int len)
// {
// 	int	i;

// 	i = len;
// 	while (i > 0)
// 	{
// 		i--;
// 		s[i] = digits[n % 16];
// 		n /= 16;
// 	}
// }

// static char	*ft_hextoa(unsigned int n, int upper)
// {
// 	char	*digits;
// 	char	*s;
// 	int		len;

// 	if (upper)
// 		digits = "0123456789ABCDEF";
// 	else
// 		digits = "0123456789abcdef";
// 	len = count_hex_digits(n);
// 	s = malloc(len + 1);
// 	if (!s)
// 		return (NULL);
// 	s[len] = '\0';
// 	if (n == 0)
// 		s[0] = '0';
// 	else
// 		fill_hex_string(s, n, digits, len);
// 	return (s);
// }

// static int	get_padding(t_print *tab, int len, int zeros, int prefix)
// {
// 	int	padding;

// 	padding = tab->width - (len + zeros + prefix);
// 	if (padding < 0)
// 		padding = 0;
// 	return (padding);
// }

// static int	print_prefix(t_print *tab, int upper, unsigned long num)
// {
// 	if (!tab->hash || num == 0)
// 		return (0);
// 	if (upper)
// 		return (write(1, "0X", 2));
// 	return (write(1, "0x", 2));
// }

// static int	print_main_part(char *tmp, int len, int zeros)
// {
// 	int	written;

// 	written = 0;
// 	if (zeros > 0)
// 		written += putchar_n('0', zeros);
// 	if (len > 0)
// 		written += putstring_n(tmp, len);
// 	return (written);
// }

// int	hex_case(t_print *tab, const char *c)
// {
// 	char			*tmp;
// 	unsigned int	num;
// 	int				len;
// 	int				zeros;
// 	int				padding;
// 	int				written;
// 	int				upper;
// 	int prefix;

// 	written = 0;
// 	upper = (*c == 'X');
// 	num = (unsigned long)va_arg(tab->args, unsigned int);
// 	tmp = ft_hextoa(num, upper);
// 	if (!tmp)
// 		return (0);
// 	len = ft_strlen(tmp);
// 	if (tab->precision == 0 && num == 0)
// 		tmp[0] = '\0';
// 	zeros = 0;
// 	if (tab->precision > len)
// 		zeros = tab->precision - len;
// 	prefix = 0;
// 	if (tab->hash && num != 0)
// 		prefix = 2;
// 	padding = get_padding(tab, len, zeros, prefix);
// 	written = 0;
// 	if (!tab->dash && (!tab->zero || tab->precision >= 0))
// 		written += putchar_n(' ', padding);
// 	if (!tab->dash && tab->zero && tab->precision < 0)
// 		written += putchar_n('0', padding);
// 	written += print_prefix(tab, upper, num);
// 	written += print_main_part(tmp, len, zeros);
// 	if (tab->dash)
// 		written += putchar_n(' ', padding);
// 	free(tmp);
// 	tab->total_length += written;
// 	return (written);
// }
