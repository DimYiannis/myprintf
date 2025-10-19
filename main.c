#include <stdio.h>

int main()
{
    char *p;
    char c = 'l';
    p = &c;
    ft_printf("%p", p);
    printf("%p", p);
}