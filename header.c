/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:54:26 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/21 21:20:43 by ydimitra         ###   ########.fr       */
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

int	ft_hexputnbr(unsigned int n, int upper)
{
	char	*digits;
	int len;

	if (upper)
		digits = "0123456789ABCDEF";
	if (!upper)
		digits = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_hexputnbr(n / 16, upper);
	write(1, &digits[n % 16], 1);
	return (len + 1);
}

int	ft_addressputnbr(void *p)
{
	uintptr_t	addr;
	int len;

	addr = (uintptr_t)p;
	
	if (addr == 0)
		return (write(1, "0x0", 3));
	write(1, "0x", 2);	
	len = 	ft_hexputnbr(addr, 0);
	return (len + 2);
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
	return (count + 2);
}
