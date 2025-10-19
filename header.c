/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:54:26 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/19 16:13:54 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned char	*ft_unsigneditoa(unsigned int n)
{
	unsigned char	*s;
	unsigned int	len;
	unsigned int	num;
	int				sign;

	sign = 0;
	num = n;
	if (n < 0)
	{
		num = -num;
		sign = 1;
	}
	len = count_digits(n) + sign;
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (len-- > 0)
	{
		s[len] = num % 10 + '0';
		num /= 10;
		if (sign == 1 && len == 0)
			s[0] = '-';
	}
	return (s);
}

void	ft_hexputnbr(int n, int upper)
{
	char	*digits;

	if (upper)
		digits = "0123456789ABCDEF";
	if (!upper)
		digits = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		ft_hexputnbr(-n, 1);
	}
	else if (n >= 16)
	{
		ft_hexputnbr(n / 16, 1);
		write(1, &digits[n % 16], 1);
	}
	else
	{
		write(1, "0x", 2);
		write(1, &digits[n % 16], 1);
	}
}
