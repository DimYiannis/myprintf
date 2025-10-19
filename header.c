/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:54:26 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/19 13:47:09 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static int	count_digits(int n)
{
	int	count;

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
	char	*s;
	unsigned int		len;
	unsigned int	num;
	int		sign;

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