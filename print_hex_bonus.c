/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:41 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/27 23:11:40 by ydimitra         ###   ########.fr       */
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
	int	i;

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

static void	print_hex_padding_and_prefix(t_print *tab, int padding,
		int upper, unsigned int num)
{
	if (!tab->dash && padding > 0 && (tab->precision >= 0 || !tab->zero))
		putchar_n(' ', padding);
	if (tab->hash && num != 0)
	{
		if (upper)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
	if (!tab->dash && padding > 0 && tab->zero && tab->precision < 0)
		putchar_n('0', padding);
}

static int	calculate_hex_values(t_print *tab, char *tmp, unsigned int num,
		int *zeros, int *padding)
{
	int	len;
	int	prefix_len;

	len = ft_strlen(tmp);
	if (tab->precision == 0 && num == 0)
	{
		len = 0;
		tmp[0] = '\0';
	}
	*zeros = 0;
	if (tab->precision > len)
		*zeros = tab->precision - len;
	prefix_len = 0;
	if (tab->hash && num != 0)
		prefix_len = 2;
	*padding = tab->width - (len + *zeros + prefix_len);
	if (*padding < 0)
		*padding = 0;
	return (len);
}

int	hex_case(t_print *tab, const char *c)
{
	char			*tmp;
	unsigned int	num;
	int				len;
	int				zeros;
	int				padding;
	int				written;
	int				upper;

	written = 0;
	upper = (*c == 'X');
	num = va_arg(tab->args, unsigned int);
	tmp = ft_hextoa(num, upper);
	if (!tmp)
		return (0);
	len = calculate_hex_values(tab, tmp, num, &zeros, &padding);
	print_hex_padding_and_prefix(tab, padding, upper, num);
	written = padding + (tab->hash && num != 0 ? 2 : 0);
	if (zeros > 0)
		written += putchar_n('0', zeros);
	written += putstring_n(tmp, len);
	if (tab->dash && padding > 0)
		written += putchar_n(' ', padding);
	free(tmp);
	tab->total_length += written;
	return (written);
}