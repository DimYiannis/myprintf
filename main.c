/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:47:01 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/21 16:52:33 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <assert.h>

int	main(void)
{
	unsigned int c = 0x101;
	// char c = '%';
	// unsigned int c = 200000;
	// int c = 200;
	// char s[] = "helooo";
	// char *p = &c;
	ft_printf(":%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
	printf(":%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
    assert(ft_printf(":%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX) == printf(":%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX));
}