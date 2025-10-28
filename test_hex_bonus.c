#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

#define TEST(fmt, val) do { \
    int n1 = printf("printf:    |" fmt "|\n", val); \
    int n2 = ft_printf("ft_printf: |" fmt "|\n", val); \
    printf("Return: printf=%d, ft_printf=%d\n\n", n1, n2); \
} while (0)


int main(void)
{
    int d = -42;
    unsigned int n = 42;
    unsigned int u = 3000000000u;
    unsigned int x = 3735928559u;
    char *s = "Hello";

    TEST("%d", n);
    TEST("%5d", n);
    TEST("%-5d", n);
    TEST("%05d", n);
    TEST("%.3d", n);
    TEST("%8.5d", n);
    TEST("%-8.5d", n);
    TEST("%8.0d", 0);
    TEST("%.2d", d);
    TEST("%c", 'A');
    TEST("%s", s);
    TEST("%p", (void *)0x12345);
    TEST("%u", u);
    TEST("%x", x);
    TEST("%X", x);
    TEST("%%", 0);
    TEST("%+d", d);
    TEST("% d", d);
    TEST("%#x", x);
    TEST("%#X", x);
    TEST("%10.5d", d);
    TEST("%-010d", d);
    TEST("%#12.8x", x);
    TEST("%.0d", 0);
    TEST("%8.0d", 0);
    return (0);
}
