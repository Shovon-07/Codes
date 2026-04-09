#include <stdio.h>
#include <time.h>

void main()
{
    clock_t starting = clock();

    //=>>> Left pyramid
    // int n;
    // printf("Enter a number : ");
    // scanf("%d", &n);

    // for (int row = 1; row <= n; row++)
    // {
    //     for (int col = 1; col <= row; col++)
    //     {
    //         printf(". ");
    //     }
    //     printf("\n");
    // }

    //=>>> Left pyramid joind
    // int n;
    // printf("Enter a number : ");
    // scanf("%d", &n);

    // for (int row = 1; row <= n; row++)
    // {
    //     for (int col = 1; col <= row; col++)
    //     {
    //         printf(". ");
    //     }
    //     printf("\n");
    // }
    // for (int row = n - 1; row >= 1; row--)
    // {
    //     for (int col = 1; col <= row; col++)
    //     {
    //         printf(". ");
    //     }
    //     printf("\n");
    // }

    //=>>> Left pyramid joind (middle will be empty)
    // int n;
    // printf("Enter a number : ");
    // scanf("%d", &n);

    // for (int row = 1; row <= n; row++)
    // {
    //     for (int col = 1; col <= row; col++)
    //     {
    //         if (col == 1 || row == n || row == col)
    //         {
    //             printf(".");
    //         }
    //         else
    //         {
    //             printf(" ");
    //         }
    //     }
    //     printf("\n");
    // }

    //=>>> Right pyramid
    // int n;
    // printf("Enter a number : ");
    // scanf("%d", &n);

    // for (int row = 1; row <= n; row++)
    // {
    //     for (int space = 1; space <= n - row; space++)
    //     {
    //         printf(" ");
    //     }
    //     for (int col = 1; col <= row; col++)
    //     {
    //         printf(".");
    //     }
    //     printf("\n");
    // }

    //=>>> Full pyramid
    // int n;
    // printf("Enter a number : ");
    // scanf("%d", &n);

    // for (int row = 1; row <= n; row++)
    // {
    //     for (int space = 1; space <= n - row; space++)
    //     {
    //         printf(" ");
    //     }
    //     for (int col = 1; col <= row * 2 - 1; col++)
    //     {
    //         printf(".");
    //     }
    //     printf("\n");
    // }

    //=>>> Full pyramid (middle will be empty)
    // int n;
    // printf("Enter a number : ");
    // scanf("%d", &n);

    // for (int row = 1; row <= n; row++)
    // {
    //     for (int space = 1; space <= n - row; space++)
    //     {
    //         printf(" ");
    //     }
    //     for (int col = 1; col <= row * 2 - 1; col++)
    //     {
    //         if (col == 1 || row == n || col == row * 2 - 1)
    //         {
    //             printf(".");
    //         }
    //         else
    //         {
    //             printf(" ");
    //         }
    //     }
    //     printf("\n");
    // }

    //=>>>Rectangle
    // int n;
    // printf("Enter a number : ");
    // scanf("%d", &n);

    // for (int row = 1; row <= n; row++)
    // {
    //     for (int col = 1; col <= n; col++)
    //     {
    //         printf(". ");
    //     }
    //     printf("\n");
    // }

    //=>>>Rectangle (middle will be empty)
    // int n;
    // printf("Enter a number : ");
    // scanf("%d", &n);

    // for (int row = 1; row <= n / 2; row++)
    // {
    //     for (int col = 1; col <= n * 2; col++)
    //     {
    //         if (col == 1 || col == n * 2 || row == 1 || row == n / 2)
    //         {
    //             printf(".");
    //         }
    //         else
    //         {
    //             printf(" ");
    //         }
    //     }
    //     printf("\n");
    // }

    //=>>> Butterfly Pattern
    // int n;
    // printf("Enter a number : ");
    // scanf("%d", &n);

    // for (int row = 1; row <= n; row++)
    // {
    //     // Left pyramid
    //     for (int col = 1; col <= row; col++)
    //     {
    //         printf(".");
    //     }
    //     // Left pyramid

    //     // Right pyramid
    //     for (int space = 1; space <= 2 * (n - row); space++)
    //     {
    //         printf(" ");
    //     }
    //     for (int col = 1; col <= row; col++)
    //     {
    //         printf(".");
    //     }
    //     // Right pyramid
    //     printf("\n");
    // }
    // // Reverse pyramid
    // for (int row = n - 1; row >= 1; row--)
    // {
    //     // Left pyramid
    //     for (int col = 1; col <= row; col++)
    //     {
    //         printf(".");
    //     }
    //     // Left pyramid

    //     // Right pyramid
    //     for (int space = 1; space <= 2 * (n - row); space++)
    //     {
    //         printf(" ");
    //     }
    //     for (int col = 1; col <= row; col++)
    //     {
    //         printf(".");
    //     }
    //     // Right pyramid
    //     printf("\n");
    // }

    //=>>> Kite
    // int n = 10;
    // for (int row = 1; row <= n; row++)
    // {
    //     for (int space = 1; space <= n - row; space++)
    //     {
    //         printf(" ");
    //     }
    //     for (int col = 1; col <= row * 2 - 1; col++)
    //     {
    //         if (col == 1 || row == n || col == row * 2 - 1 || col == row * 2 / 2)
    //         {
    //             printf(".");
    //         }
    //         else
    //         {
    //             printf(" ");
    //         }
    //     }

    //     printf("\n");
    // }

    // for (int row = n - 1; row >= 1; row--)
    // {
    //     for (int space = 1; space <= n - row; space++)
    //     {
    //         printf(" ");
    //     }
    //     for (int col = 1; col <= row * 2 - 1; col++)
    //     {
    //         if (col == 1 || row == n || col == row * 2 - 1 || col == row * 2 / 2)
    //         {
    //             printf(".");
    //         }
    //         else
    //         {
    //             printf(" ");
    //         }
    //     }

    //     printf("\n");
    // }
    /**
     * Pattern
     * 1
     * 0 1
     * 1 0 1
     * 0 1 0 1
     **/
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    printf("0");
                }
                else
                {
                    printf("1");
                }
            }
        }
        printf("\n");
    }

    //=>>> Calculate execution time
    clock_t ending = clock();
    float executionTime = ((float)(ending - starting)) / CLOCKS_PER_SEC;
    printf("\n\n\n\t\t\tExection time : %f second \n\n", executionTime);
}
