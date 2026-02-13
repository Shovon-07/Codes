#include <stdio.h>

int main()
{
    int number = 64;
    if ((number % 3 == 0) && (number % 7 == 0))
    {
        printf("Divisible\n");
    }
    else
    {
        printf("Not Divisible\n");
    }
    return 0;
}