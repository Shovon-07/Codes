#include <stdio.h>

void func(int *x, int y)
{
    // printf("Value of x = %d\n", *x);
    printf("Address of x = %p\n", x);
    int sum = *x + y;
    printf("Sum = %d\n", sum);
}

int main()
{
    int a = 3, b = 2;
    func(&a, b);
    // printf("Value of p = %d\n", *p);
    // printf("Address of p = %p\n", p);

    return 0;
}