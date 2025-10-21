/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:54:26 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/21 15:12:14 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

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
	unsigned int	num;

	num = n;
	len = count_digits(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (len-- > 0)
	{
		s[len] = num % 10 + '0';
		num /= 10;
	}
	return (s);
}

void	ft_hexputnbr(unsigned long n, int upper)
{
	char	*digits;

	if (upper)
		digits = "0123456789ABCDEF";
	if (!upper)
		digits = "0123456789abcdef";
	if (n >= 16)
		ft_hexputnbr(n / 16, upper);
	write(1, &digits[n % 16], 1);
}

void	ft_addressputnbr(uintptr_t n)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (n == 0)
	{
		write(1, "0x0", 3);
		return ;
	}		
	if (n >= 16)
		ft_addressputnbr(n / 16);
	if (n < 16)
		write(1, "0x", 2);
	write(1, &digits[n % 16], 1);
}

uintptr_t	address_len(uintptr_t n)
{
	uintptr_t	count;

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
