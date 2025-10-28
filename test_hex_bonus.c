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

int ft_len;
    int real_len;

    // 1️⃣ Test 1: "%5%"
    printf("=== Test 1: \"%%5%%\" ===\n");
    ft_len = ft_printf("%5%\n");
    real_len = printf("%5%\n");
    printf("ft_printf len = %d | printf len = %d\n\n", ft_len, real_len);

    // 2️⃣ Test 2: "%-5%"
    printf("=== Test 2: \"%%-5%%\" ===\n");
    ft_len = ft_printf("%-5%\n");
    real_len = printf("%-5%\n");
    printf("ft_printf len = %d | printf len = %d\n\n", ft_len, real_len);

    // 3️⃣ Test 3: "%-05%"
    printf("=== Test 3: \"%%-05%%\" ===\n");
    ft_len = ft_printf("%-05%\n");
    real_len = printf("%-05%\n");
    printf("ft_printf len = %d | printf len = %d\n\n", ft_len, real_len);

    // 4️⃣ Test 4: "%12%"
    printf("=== Test 4: \"%%12%%\" ===\n");
    ft_len = ft_printf("%12%\n");
    real_len = printf("%12%\n");
    printf("ft_printf len = %d | printf len = %d\n\n", ft_len, real_len);

    // 5️⃣ Test 5: "%-12%"
    printf("=== Test 5: \"%%-12%%\" ===\n");
    ft_len = ft_printf("%-12%\n");
    real_len = printf("%-12%\n");
    printf("ft_printf len = %d | printf len = %d\n\n", ft_len, real_len);



    // TEST("%d", n);
    // TEST("%5d", n);
    // TEST("%-5d", n);
    // TEST("%05d", n);
    // TEST("%.3d", n);
    // TEST("%8.5d", n);
    // TEST("%-8.5d", n);
    // TEST("%8.0d", 0);
    // TEST("%.2d", d);
    // TEST("%c", 'A');
    // TEST("%s", s);
    // TEST("%p", (void *)0x12345);
    // TEST("%u", u);
    // TEST("%x", x);
    // TEST("%X", x);
    // TEST("%%", 0);
    // TEST("%+d", d);
    // TEST("% d", d);
    // TEST("%#x", x);
    // TEST("%#X", x);
    // TEST("%10.5d", d);
    // TEST("%-010d", d);
    // TEST("%#12.8x", x);
    // TEST("%.0d", 0);
    // TEST("%8.0d", 0);
    // return (0);
}
