#include <stdio.h>
#include "myheader.h"

int main()
{
    char *p;
    char c = 'l';
    p = &c;
    ft_printf("wanabee: %p\n", p);
    printf("legit one: %p\n", p);
}