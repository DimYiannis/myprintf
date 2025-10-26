/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 12:57:02 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/26 16:55:32 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf_bonus.h"

int main(void)
{
    unsigned int n = 3735928559; // 0xDEADBEEF
    unsigned int small = 42;
    unsigned int zero = 0;

    printf("=== BASIC TESTS ===\n");
    ft_printf_bonus("ft: %x\n", n);
    printf("og: %x\n", n);

    ft_printf_bonus("ft: %X\n", n);
    printf("og: %X\n", n);

    printf("\n=== HASH FLAG (#) ===\n");
    ft_printf_bonus("ft: %#x\n", n);
    printf("og: %#x\n", n);

    ft_printf_bonus("ft: %#X\n", small);
    printf("og: %#X\n", small);

    ft_printf_bonus("ft: %#x\n", zero);
    printf("og: %#x\n", zero);

    printf("\n=== WIDTH ===\n");
    ft_printf_bonus("ft: |%10x|\n", small);
    printf("og: |%10x|\n", small);

    ft_printf_bonus("ft: |%10X|\n", small);
    printf("og: |%10X|\n", small);

    printf("\n=== ZERO FLAG ===\n");
    ft_printf_bonus("ft: |%010x|\n", small);
    printf("og: |%010x|\n", small);

    ft_printf_bonus("ft: |%#010x|\n", small);
    printf("og: |%#010x|\n", small);

    printf("\n=== LEFT ALIGN (-) ===\n");
    ft_printf_bonus("ft: |%-10x|\n", small);
    printf("og: |%-10x|\n", small);

    ft_printf_bonus("ft: |%-#10x|\n", small);
    printf("og: |%-#10x|\n", small);

    printf("\n=== PRECISION ===\n");
    ft_printf_bonus("ft: |%.5x|\n", small);
    printf("og: |%.5x|\n", small);

    ft_printf_bonus("ft: |%10.5x|\n", small);
    printf("og: |%10.5x|\n", small);

    ft_printf_bonus("ft: |%-10.5x|\n", small);
    printf("og: |%-10.5x|\n", small);

    printf("\n=== COMBINED FLAGS ===\n");
    ft_printf_bonus("ft: |%#-10.5x|\n", small);
    printf("og: |%#-10.5x|\n", small);

    ft_printf_bonus("ft: |%#010.5x|\n", small);
    printf("og: |%#010.5x|\n", small);

    return (0);
}
