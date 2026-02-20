#include <stdio.h>
#include <math.h>

void main()
{
    //=>>> Task 1
    /*
    for (int i = 1; i <= 20; i += 1)
    {
        printf("%d\n", i);
    }
        */

    //=>>> Task 2
    /*
    for (int i = 20; i >= 1; i -= 1)
    {
        printf("%d\n", i);
    }
        */

    //=>>> Task 3
    /*
        for (int i = 2; i <= 50; i += 2)
        {
            printf("%d\n", i);
        }
            */

    //=>>> Task 4
    /*
    for (int i = 1; i <= 50; i += 2)
    {
        printf("%d\n", i);
    }
    */

    //=>>> Task 5
    /*
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i += 1)
    {
        printf("\n%d", i);
    }
    */

    //=>>> Task 6
    /*
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i += 1)
    {
        sum += i;
    }
    printf("%d\n", sum);
    */

    //=>>> Task 7 & 8
    /*
    for (int i = 1; i <= 10; i += 1)
    {
        // printf("%.1f\n", pow(i, 2)); // for task 7
        // printf("%.1f\n", pow(i, 3)); // for task 8
    }
    */

    //=>>> Task 9
    /*
    for (int i = 1; i <= 100; i += 1)
    {
        if (i % 3 != 0)
        {
            continue;
        }
        printf("%d\n", i);
    }
    */

    //=>>> Task 10 (lack)
    /*
    for (int i = 1; i <= 100; i += 1)
    {
        if ((i % 3 != 0) || (i % 5 != 0))
        {
            continue;
        }
        printf("%d\n", i);
    }
    */

    //=>>> Task 11
    /*
    int nth, factorial = 1;
    scanf("%d", &nth);

    for (int i = 1; i <= nth; i += 1)
    {
        factorial *= i;
    }
    printf("%d\n", factorial);
    */

    //=>>> Task 12
    /*
    int x, givenNumber, multiple;
    printf("Enter a number : ");
    scanf("%d", &givenNumber);

    for (x = 1; x <= 10; x += 1)
    {
        multiple = x * givenNumber;
        printf("%d * %d = %d\n", givenNumber, x, multiple);
    }
    */

    //=>>> Task 13
    int multiple;

    for (int x = 1; x <= 10; x += 1)
    {
        for (int y = 1; y <= 10; y += 1)
        {
            multiple = x * y;
            printf("%d * %d = %d\n", x, y, multiple);
            if (y == 10)
            {
                printf("\n--------------\n");
            }
        }
    }
}