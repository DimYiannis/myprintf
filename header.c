/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:54:26 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/23 15:14:32 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

unsigned int	count_digits(unsigned int n)
{
	unsigned int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_unsigneditoa(unsigned int n)
{
	char			*s;
	unsigned int	len;

	len = count_digits(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (len-- > 0)
	{
		s[len] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}

int	ft_hexputnbr(unsigned long long n, int upper)
{
	char	*digits;
	int		len;

	len = 0;
	if (upper)
		digits = "0123456789ABCDEF";
	if (!upper)
		digits = "0123456789abcdef";
	if (n >= 16)
		len += ft_hexputnbr(n / 16, upper);
	len += write(1, &digits[n % 16], 1);
	return (len);
}

int	ft_addressputnbr(void *p)
{
	uintptr_t	addr;
	int			len;

	addr = (uintptr_t)p;
	if (!addr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	len = ft_hexputnbr(addr, 0);
	return (len + 2);
}

int	skip_char(const char *c)
{
	const char	*first_arg;
	int			i;
	int			len;
	int			count;

	first_arg = c;
	i = 0;
	count = 0;
	if (ft_isalpha(first_arg[i]))
	{
		len = len_conv(first_arg);
		while (len-- > 0)
			first_arg--;
		if (*first_arg == '%')
			i = len + 1;
		else
			count += write(1, &first_arg[i], 1);
	}
	else
		count += write(1, &first_arg[i], 1);
	return (count);
}

int len_conv( const char *c)
{
	const char	*first_arg;
	int			i;
	const char	*index;
	const char *ptr;
	
	ptr = c - 1;
	index = NULL;
	first_arg = c;
	i = 0;
	if (first_arg[i] == '%')
	{
		while (first_arg[i] && !ft_isalpha(first_arg[i]))
			i++;
	}
	else if (first_arg[i] != '%')
	{
		while (*ptr != '%' && ptr <= first_arg)
		{
			if (ft_isalpha(*ptr))
				index = ptr;
			ptr--;
		}
		if (index && index < c)
				return (0);
		i = c - ptr;
	}
	return (i);
}
