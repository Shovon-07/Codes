#include <stdio.h>
#include <math.h>

int main()
{
    //=>>> Problem 1
    // int n, sum = 0;
    // float average;

    // printf("Enter the number of students : ");
    // scanf("%d", &n);
    // int marks[n];

    // printf("Enter marks : ");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &marks[i]);
    // }

    // int highest = marks[0], lowest = marks[0];

    // for (int i = 0; i < n; i++)
    // {
    //     sum += marks[i];
    //     highest = fmax(highest, marks[i]);
    //     lowest = fmin(lowest, marks[i]);
    // }
    // average = sum / n;
    // printf("Agerage = %.2f\n", average);
    // printf("Highest = %d\n", highest);
    // printf("Lowest = %d\n", lowest);

    //=>>> Problem 2
    // int n, even = 0, odd = 0;
    // printf("Enter the number of element : ");
    // scanf("%d", &n);

    // int numbers[n];
    // printf("Enter the numbers : ");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &numbers[i]);
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     if (numbers[i] % 2 == 0)
    //     {
    //         even++;
    //     }
    //     else
    //     {
    //         odd++;
    //     }
    // }
    // printf("Even : %d\n", even);
    // printf("Odd : %d\n", odd);

    //=>>> Problem 3
    // int n;
    // printf("Enter the number of element : ");
    // scanf("%d", &n);

    // int numbers[n];
    // printf("Enter values : \n");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &numbers[i]);
    // }

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     printf("%d ", numbers[i]);
    // }

    //=>>> Problem 4
    int n;
    printf("Enter the number of element : ");
    scanf("%d", &n);

    int numbers[n], secondMax = numbers[0];
    printf("Enter values : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < n; i++)
    {
        secondMax = fmax(secondMax, numbers[i]);
    }
    printf("Second largest = %d\n", secondMax);

    return 0;
}