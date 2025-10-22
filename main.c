/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:47:01 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/22 15:14:31 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>

void	test_ft_printf(void)
{
	assert(ft_printf("Hello %s!\n", "world") == printf("Hello %s!\n", "world"));
	assert(ft_printf("Char: %c\n", 'A') == printf("Char: %c\n", 'A'));
	assert(ft_printf("Int: %d, %i\n", -42, 42) == printf("Int: %d, %i\n", -42, 42));
	assert(ft_printf("Unsigned: %u\n", 3000000000u) == printf("Unsigned: %u\n", 3000000000u));
	assert(ft_printf("Hex lower: %x\n", 3735928559u) == printf("Hex lower: %x\n", 3735928559u));
	assert(ft_printf("Hex upper: %X\n", 3735928559u) == printf("Hex upper: %X\n", 3735928559u));
	assert(ft_printf("Pointer: %p\n", (void *)0) == printf("Pointer: %p\n", (void *)0));
	assert(ft_printf("Pointer: %p\n", (void *)0x7ffee4f6dafc) == printf("Pointer: %p\n", (void *)0x7ffee4f6dafc));
	assert(ft_printf("Percent: %%\n") == printf("Percent: %%\n"));
	assert(ft_printf(":%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX) == printf(":%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX));
	assert(ft_printf("Limits: %d, %d\n", INT_MIN, INT_MAX) == printf("Limits: %d, %d\n", INT_MIN, INT_MAX));
	assert(ft_printf("UINT_MAX: %u\n", UINT_MAX) == printf("UINT_MAX: %u\n", UINT_MAX));
	assert(ft_printf("Zeros: %d %u %x %X\n", 0, 0u, 0u, 0u) == printf("Zeros: %d %u %x %X\n", 0, 0u, 0u, 0u));
	assert(ft_printf("Hex: %x %X\n", 0, 0) == printf("Hex: %x %X\n", 0, 0));
	assert(ft_printf("Empty: %s\n", "") == printf("Empty: %s\n", ""));
	assert(ft_printf("Mix: %c %s %p %d %i %u %x %X %%\n", 'A', "test", (void *)0x42, -42, 42, 42u, 42u, 42u) == printf("Mix: %c %s %p %d %i %u %x %X %%\n", 'A', "test", (void *)0x42, -42, 42, 42u, 42u, 42u));
	assert(ft_printf("No format\n") == printf("No format\n"));
	assert(ft_printf("%p %p\n", (void *)0, (void *)0) == printf("%p %p\n", (void *)0, (void *)0));
	assert(ft_printf("%p\n", (void *)ULONG_MAX) == printf("%p\n", (void *)ULONG_MAX));
	assert(ft_printf("%x %X\n", UINT_MAX, UINT_MAX) == printf("%x %X\n", UINT_MAX, UINT_MAX));
	assert(ft_printf("%x %X\n", 1, 1) == printf("%x %X\n", 1, 1));
	assert(ft_printf("%x %X\n", 15, 15) == printf("%x %X\n", 15, 15));
	assert(ft_printf("%x %X\n", 16, 16) == printf("%x %X\n", 16, 16));
    assert(ft_printf("% d \n", 16) == printf("% d\n", 16));

	printf("\n test passed \n");
}

int	main(void)
{
	unsigned int c = 0x101;
	// char c = '%';
	// unsigned int c = 200000;
	// int c = 200;
	// char s[] = "helooo";
	// char *p = &c;
    ft_printf("% d \n", 16);
	ft_printf(":%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
	printf(":%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
	assert(ft_printf(":%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX) == printf(":%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX));
	ft_printf("Hello %s!\n", "world");
	test_ft_printf();
}