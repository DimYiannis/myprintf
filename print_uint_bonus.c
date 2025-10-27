/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:52 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/27 23:05:01 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	count_decimal_digits(unsigned int n)
{
	int count;
	
	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 10;  // Divide by 10 for DECIMAL digits
		count++;
	}
	return (count);
}

char	*ft_unsigneditoa(unsigned int n)
{
	char			*s;
	unsigned int	len;

	len = count_decimal_digits(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	
	if (n == 0)
	{
		s[0] = '0';
		return (s);
	}
	
	while (len > 0)
	{
		len--;
		s[len] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

int	unsigned_case(t_print *tab)
{
	char			*tmp;
	unsigned int	num;
	int				len;
	int				zeros;
	int				padding;
	int				written;

	written = 0;
	num = va_arg(tab->args, unsigned int);
	tmp = ft_unsigneditoa(num);
	if (!tmp)
		return (0);
	len = ft_strlen(tmp);
	
	// Special case: precision 0 and value 0 -> print nothing
	if (tab->precision == 0 && num == 0)
	{
		len = 0;
		tmp[0] = '\0';
	}
	
	// Calculate zeros needed from precision
	zeros = 0;
	if (tab->precision > len)
		zeros = tab->precision - len;
	
	// Calculate padding
	padding = tab->width - (len + zeros);
	if (padding < 0)
		padding = 0;
	
	// If not left-justified and not zero-padded: print padding spaces first
	// Note: precision overrides zero flag
	if (!tab->dash && padding > 0 && (tab->precision >= 0 || !tab->zero))
		written += putchar_n(' ', padding);
	// If zero flag and no precision: print zeros
	else if (!tab->dash && padding > 0 && tab->zero && tab->precision < 0)
		written += putchar_n('0', padding);
	
	// Print leading zeros (from precision)
	if (zeros > 0)
		written += putchar_n('0', zeros);
	
	// Print number digits
	written += putstring_n(tmp, len);
	
	// If left-justified: print padding spaces at the end
	if (tab->dash && padding > 0)
		written += putchar_n(' ', padding);
	
	free(tmp);
	tab->total_length += written;
	return (written);
}