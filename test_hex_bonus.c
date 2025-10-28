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

    int	ft_len;
    int real_len;
	int	std_len;

	printf("=== BASIC TESTS (no formatting) ===\n\n");

	// %c
	printf("Test %%c:\n");
	ft_len = ft_printf("ft_printf: %c\n", 'A');
	std_len = printf("printf   : %c\n", 'A');
	printf("ft_len = %d | std_len = %d\n\n", ft_len, std_len);

	// %s
	printf("Test %%s:\n");
	ft_len = ft_printf("ft_printf: %s\n", "Hello, world!");
	std_len = printf("printf   : %s\n", "Hello, world!");
	printf("ft_len = %d | std_len = %d\n\n", ft_len, std_len);

	// %p
	printf("Test %%p:\n");
	void *ptr = (void *)0x1234abcd;
	ft_len = ft_printf("ft_printf: %p\n", ptr);
	std_len = printf("printf   : %p\n", ptr);
	printf("ft_len = %d | std_len = %d\n\n", ft_len, std_len);

	// %d
	printf("Test %%d:\n");
	ft_len = ft_printf("ft_printf: %d\n", -12345);
	std_len = printf("printf   : %d\n", -12345);
	printf("ft_len = %d | std_len = %d\n\n", ft_len, std_len);

	// %i
	printf("Test %%i:\n");
	ft_len = ft_printf("ft_printf: %i\n", 42);
	std_len = printf("printf   : %i\n", 42);
	printf("ft_len = %d | std_len = %d\n\n", ft_len, std_len);

	// %u
	printf("Test %%u:\n");
	ft_len = ft_printf("ft_printf: %u\n", 4294967295u);
	std_len = printf("printf   : %u\n", 4294967295u);
	printf("ft_len = %d | std_len = %d\n\n", ft_len, std_len);

	// %x
	printf("Test %%x:\n");
	ft_len = ft_printf("ft_printf: %x\n", 305441741);
	std_len = printf("printf   : %x\n", 305441741);
	printf("ft_len = %d | std_len = %d\n\n", ft_len, std_len);

	// %X
	printf("Test %%X:\n");
	ft_len = ft_printf("ft_printf: %X\n", 305441741);
	std_len = printf("printf   : %X\n", 305441741);
	printf("ft_len = %d | std_len = %d\n\n", ft_len, std_len);

	// %%
	printf("Test %%%%:\n");
	ft_len = ft_printf("ft_printf: %%\n");
	std_len = printf("printf   : %%\n");
	printf("ft_len = %d | std_len = %d\n\n", ft_len, std_len);

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
