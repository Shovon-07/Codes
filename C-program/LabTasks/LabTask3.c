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
    printf("Enter a number : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i += 1)
    {
        printf("\n%d", i);
    }
    */

    //=>>> Task 6
    /*
    int n, sum = 0;
    printf("Enter a number : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i += 1)
    {
        sum += i;
    }
    printf("%d\n", sum);
    */

    //=>>> Task 7
    /*
    for (int i = 1; i <= 10; i += 1)
    {
        // printf("%.1f\n", pow(i, 2)); // for task 7
    }
    */

    //=>>> Task 8
    /*
    for (int i = 1; i <= 10; i += 1)
    {
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

    //=>>> Task 10
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
    printf("Enter a number : ");
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
    /*
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
    */

    //=>>> Task 14

    //=>>> Task 15
    /*
    int n, sum = 0;
    printf("Enter a number : ");
    scanf("%d", &n);

    for (int x = 1; x <= n; x += 1)
    {
        if (x % 2 != 0)
        {
            continue;
        }
        sum += x;
    }
    printf("%d\n", sum);
    */

    //=>>> Task 16
    /*
    int n, product = 1;
    printf("Enter a number : ");
    scanf("%d", &n);

    for (int x = 1; x <= n; x += 1)
    {
        if (x % 2 == 0)
        {
            continue;
        }
        product *= x;
    }
    printf("%d\n", product);
    */

    //=>>> Task 17
    /*
    int number, digit, sum = 0;
    printf("Enter a number : ");
    scanf("%d", &number);
    while (number != 0)
    {
        digit = number % 10;
        number /= 10;
        sum += digit;
        }
    printf("%d\n", sum);
    */

    //=>>> Task 18
    /*
    long long int number, reverse = 0;
    printf("Enter a number : ");
    scanf("%lld", &number);

    while (number != 0)
    {
        reverse = reverse * 10 + number % 10;
        number /= 10;
    }
    printf("Reverse = %lld\n", reverse);
    */

    //=>>> Task 19
    /*
    int number, counted = 0;
    printf("Enter a number : ");
    scanf("%d", &number);
    while (number != 0)
    {
        number /= 10;
        counted += 1;
    }
    printf("%d\n", counted);
    */

    //=>>> Task 28
    /*
    for (int x = 1; x <= 5; x++)
    {
        for (int y = 1; y <= x; y++)
        {
            printf("*");
        }
        printf("\n");
    }
    */

    //=>>> Task 20
    /*
    int number, storage, reverse = 0;
    printf("Enter a number : ");
    scanf("%d", &number);
    storage = number;

    while (number > 0)
    {
        reverse = reverse * 10 + number % 10;
        number /= 10;
    }

    if (storage == reverse)
    {
        printf("Palindrome number.\n");
    }
    else
    {
        printf("Not palindrome number.\n");
    }
    */

    //=>>> Task 21
    /*
    long long int n;
    int flag = 0;
    printf("Enter a number : ");
    scanf("%lld", &n);
    n = fabs(n);

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            flag += 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Prime number.\n");
    }
    else
    {
        printf("Not prime number.\n");
    }
    */

    //=>>> Task 22
    // int n;
    // scanf("%d", &n);
    // for (int i = 2; i <= n; i++)
    // {
    //     int flag = 0;
    //     for (int j = 2; j <= i / 2; j++)
    //     {
    //         if (i % j == 0)
    //         {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (flag == 0)
    //         printf("%d ", i);
    // }
}