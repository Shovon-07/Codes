#include <stdio.h>
#include <math.h>

int main()
{
    //=>>> Problem 1
    // int n, total = 0, avg = 0;
    // printf("Enter the number of element : ");
    // scanf("%d", &n);
    // int marks[n];

    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &marks[i]);
    // }

    // int highest = marks[0], lowest = marks[0];

    // for (int i = 0; i < n; i++)
    // {
    //     total += marks[i];
    //     if (marks[i] > highest)
    //     {
    //         highest = marks[i];
    //     }
    //     if (marks[i] < lowest)
    //     {
    //         lowest = marks[i];
    //     }
    // }

    // avg = total / n;
    // printf("Avg = %d\n", avg);
    // printf("Highest = %d\n", highest);
    // printf("Lowest = %d\n", lowest);

    //=>>> Problem 2
    // int n, even = 0, odd = 0;
    // printf("Enter the number of element : ");
    // scanf("%d", &n);
    // int numbers[n];

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
    // printf("Even = %d\n", even);
    // printf("Odd = %d\n", odd);

    //=>>> Problem 3
    // int n;
    // printf("Enter the number of element : ");
    // scanf("%d", &n);
    // int arr[n];

    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     printf("%d ", arr[i]);
    // }

    //=>>> Problem 4
    // int n;
    // printf("Enter the number of element : ");
    // scanf("%d", &n);
    // int score[n];

    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &score[i]);
    // }

    // int fLarge = score[0], sLarge = -1000000000;

    // for (int i = 0; i < n; i++)
    // {
    //     if (fLarge < score[i])
    //     {
    //         fLarge = score[i];
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     if (fLarge > score[i] && sLarge < score[i])
    //     {
    //         sLarge = score[i];
    //     }
    // }
    // printf("First largest = %d\n", fLarge);
    // printf("Second largest = %d\n", sLarge);

    //=>>> Problem 5
    // int n, maxValue = 0;
    // printf("Enter the number of element : ");
    // scanf("%d", &n);
    // int numbers[n];

    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &numbers[i]);
    //     if (numbers[i] > maxValue)
    //     {
    //         maxValue = numbers[i];
    //     }
    // }

    // int freqArr[maxValue + 1], range = maxValue + 1;

    // for (int i = 0; i < range; i++)
    // {
    //     freqArr[i] = 0;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     int x = numbers[i];
    //     freqArr[x]++;
    // }

    // for (int i = 0; i < range; i++)
    // {
    //     if (freqArr[i] != 0)
    //     {
    //         printf("%d occurs %d times\n", i, freqArr[i]);
    //     }
    // }

    //=>>> Problem 6
    // int x, y, i, j;
    // printf("Enter the row size : ");
    // scanf("%d", &x);
    // printf("Enter the column size : ");
    // scanf("%d", &y);

    // int a[x][y], b[x][y], result[x][y];

    // printf("Enter the element of first matrix : \n");
    // for (i = 0; i < x; i++)
    // {
    //     for (j = 0; j < y; j++)
    //     {
    //         scanf("%d", &a[i][j]);
    //     }
    // }
    // printf("Enter the element of second matrix : \n");
    // for (i = 0; i < x; i++)
    // {
    //     for (j = 0; j < y; j++)
    //     {
    //         scanf("%d", &b[i][j]);
    //     }
    // }

    // for (i = 0; i < x; i++)
    // {
    //     for (j = 0; j < y; j++)
    //     {
    //         result[i][j] = a[i][j] + b[i][j];
    //     }
    // }
    // printf("Result of matrix addition : \n");
    // for (i = 0; i < x; i++)
    // {
    //     for (j = 0; j < y; j++)
    //     {
    //         printf("%d ", result[i][j]);
    //     }
    //     printf("\n");
    // }

    //=>>> Problem 7
    // int row, col, i, j;
    // printf("Enter the row size : ");
    // scanf("%d", &row);
    // printf("Enter the column size : ");
    // scanf("%d", &col);

    // int arr[row][col];

    // printf("Enter the element of array : \n");
    // for (i = 0; i < row; i++)
    // {
    //     for (j = 0; j < col; j++)
    //     {
    //         scanf("%d", &arr[i][j]);
    //     }
    // }
    // for (i = 0; i < row; i++)
    // {
    //     int sum = 0;
    //     for (j = 0; j < col; j++)
    //     {
    //         sum += arr[i][j];
    //     }
    //     printf("Row %d Sum = %d\n", i + 1, sum);
    // }

    //=>>> Problem 8
    // int row, col, i, j;
    // printf("Enter the row size : ");
    // scanf("%d", &row);
    // printf("Enter the column size : ");
    // scanf("%d", &col);

    // int arr[row][col];

    // printf("Enter the element of array : \n");
    // for (i = 0; i < row; i++)
    // {
    //     for (j = 0; j < col; j++)
    //     {
    //         scanf("%d", &arr[i][j]);
    //     }
    // }
    // int arr2[col][row];
    // for (i = 0; i < row; i++)
    // {
    //     for (j = 0; j < col; j++)
    //     {
    //         arr2[j][i] = arr[i][j];
    //     }
    // }
    // for (i = 0; i < col; i++)
    // {
    //     for (j = 0; j < row; j++)
    //     {
    //         printf("%d ", arr2[i][j]);
    //     }
    //     printf("\n");
    // }

    //=>>> Problem 9
    int row, col, i, j;
    printf("Enter the row size : ");
    scanf("%d", &row);
    printf("Enter the column size : ");
    scanf("%d", &col);

    int arr[row][col];

    printf("Enter the element of array : \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (i == j)
                printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}