#include <stdio.h>

//=>>> Problems link-> https://lightoj.com/problems/category/dimik
void Problem1()
{
    int T, N;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        scanf("%d", &N);
        if (N % 2 == 0)
        {
            printf("even\n");
        }
        else
        {
            printf("odd\n");
        }
    }
}

void Problem2()
{
    int T, N;
    scanf("%d", &T);

    for (int i = 1; i <= T; i += 1)
    {
        scanf("%d", &N);
        if (N % 2 == 0)
        {
            printf("even\n");
        }
        else
        {
            printf("odd\n");
        }
    }
}

int main()
{
    Problem2();
    return 0;
}