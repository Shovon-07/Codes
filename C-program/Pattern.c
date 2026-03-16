#include <stdio.h>

void main()
{
    //=>>> Left pyramid
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);

    for (int row = 1; row <= n; row += 1)
    {
        for (int col = 1; col <= row; col += 1)
        {
            printf("%d ", col);
        }
        printf("\n");
    }
}