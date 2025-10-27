#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char	c = '%';
	char	*s = "Hello, world!";
	void	*p = s;
	int		d = -42;
	int		i = 12345;
	unsigned int	u = 4294967295;
	int		x = 3735928559; // 0xDEADBEEF
	unsigned int n = 42;

	ft_printf("ft_printf: |%d|\n", n);
	ft_printf("ft_printf: |%5d|\n", n);
	ft_printf("ft_printf: |%-5d|\n", n);
	ft_printf("ft_printf: |%05d|\n", n);
	ft_printf("ft_printf: |%.3d|\n", n);
	ft_printf("ft_printf: |%8.5d|\n", n);
	ft_printf("ft_printf: |%-8.5d|\n", n);
	ft_printf("ft_printf: |%8.0d|\n", 0);

    int n1 = printf("printf:    |%.2d|\n", d);
    int n2 = ft_printf("ft_printf: |%.2d|\n", d);
    printf("printf: %d, ft_printf: %d\n", n1, n2);

    ft_printf("Char test: |%c|\n", 'A');
    ft_printf("String test: |%s|\n", "Hello");
    ft_printf("Pointer test: |%p|\n", (void *)0x12345);
    ft_printf("Unsigned: |%u|\n", 3000000000u);
    ft_printf("Hex lower: |%x|\n", 3735928559u);
    ft_printf("Hex upper: |%X|\n", 3735928559u);
    ft_printf("Percent: |%%|\n");
    
	printf("========= BASIC TESTS =========\n");
	printf("1. Char:\n");
	printf("   printf:    |%c|\n", c);
	ft_printf("   ft_printf: |%c|\n", c);

	printf("\n2. String:\n");
	printf("   printf:    |%s|\n", s);
	ft_printf("   ft_printf: |%s|\n", s);

	printf("\n3. Pointer:\n");
	printf("   printf:    |%p|\n", p);
	ft_printf("   ft_printf: |%p|\n", p);

	printf("\n4. Decimal (%%d):\n");
	printf("   printf:    |%d|\n", d);
	ft_printf("   ft_printf: |%d|\n", d);

	printf("\n5. Integer (%%i):\n");
	printf("   printf:    |%i|\n", i);
	ft_printf("   ft_printf: |%i|\n", i);

	printf("\n6. Unsigned:\n");
	printf("   printf:    |%u|\n", u);
	ft_printf("   ft_printf: |%u|\n", u);

	printf("\n7. Hex lowercase:\n");
	printf("   printf:    |%x|\n", x);
	ft_printf("   ft_printf: |%x|\n", x);

	printf("\n8. Hex uppercase:\n");
	printf("   printf:    |%X|\n", x);
	ft_printf("   ft_printf: |%X|\n", x);

	printf("\n9. Percent:\n");
	printf("   printf:    |%%|\n");
	ft_printf("   ft_printf: |%%|\n");

	printf("\n========= WIDTH & FLAGS TESTS =========\n");

	printf("\n1. Width and Zero flag:\n");
	printf("   printf:    |%010d|\n", d);
	ft_printf("   ft_printf: |%010d|\n", d);

	printf("\n2. Width and Minus flag:\n");
	printf("   printf:    |%-10d|\n", d);
	ft_printf("   ft_printf: |%-10d|\n", d);

	printf("\n3. Precision with integers:\n");
	printf("   printf:    |%.5d|\n", d);
	ft_printf("   ft_printf: |%.5d|\n", d);

	printf("\n4. Width + Precision:\n");
	printf("   printf:    |%10.5d|\n", d);
	ft_printf("   ft_printf: |%10.5d|\n", d);

	printf("\n5. Space flag:\n");
	printf("   printf:    |% d|\n", d);
	ft_printf("   ft_printf: |% d|\n", d);

	printf("\n6. Plus flag:\n");
	printf("   printf:    |%+d|\n", d);
	ft_printf("   ft_printf: |%+d|\n", d);

	printf("\n7. Hash flag (hex):\n");
	printf("   printf:    |%#x| %#X|\n", x, x);
	ft_printf("   ft_printf: |%#x| %#X|\n", x, x);

	printf("\n8. Combination: space + plus (should prioritize plus):\n");
	printf("   printf:    |% +d|\n", i);
	ft_printf("   ft_printf: |% +d|\n", i);

	printf("\n9. Combination: zero + minus + width:\n");
	printf("   printf:    |%-010d|\n", i);
	ft_printf("   ft_printf: |%-010d|\n", i);

	printf("\n10. Hex with width, precision, and hash:\n");
	printf("   printf:    |%#12.8x|\n", x);
	ft_printf("   ft_printf: |%#12.8x|\n", x);

	printf("\n========= EDGE CASES =========\n");

	printf("\n1. Null string:\n");
	printf("   printf:    |%s|\n", (char *)NULL);
	ft_printf("   ft_printf: |%s|\n", (char *)NULL);

	printf("\n2. Zero precision with zero value:\n");
	printf("   printf:    |%.0d|\n", 0);
	ft_printf("   ft_printf: |%.0d|\n", 0);

	printf("\n3. Width + precision with 0 value:\n");
	printf("   printf:    |%8.0d|\n", 0);
	ft_printf("   ft_printf: |%8.0d|\n", 0);

	printf("\n4. Pointer NULL:\n");
	printf("   printf:    |%p|\n", NULL);
	ft_printf("   ft_printf: |%p|\n", NULL);

	printf("\n========= END =========\n");
	return (0);
}
