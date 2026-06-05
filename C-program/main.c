// A
// #include <stdio.h>
// #include <stdlib.h>

// int sixseven(const void *a, const void *b)
// {
//     long long x = *(const int *)a;
//     long long y = *(const int *)b;
//     return (x > y) - (x < y);
// }

// int main()
// {
//     int T;
//     scanf("%d", &T);

//     while (T--)
//     {
//         int n;
//         scanf("%d", &n);

//         int a[105];
//         for (int i = 0; i < n; i++)
//             scanf("%d", &a[i]);

//         qsort(a, n, sizeof(int), sixseven);

//         int ans = n;

//         for (int i = 0; i < n;)
//         {
//             int j = i;
//             while (j < n && a[j] == a[i])
//                 j++;

//             int L = i;
//             int R = n - j;

//             int cur = (L > R) ? L : R;
//             if (cur < ans)
//                 ans = cur;

//             i = j;
//         }

//         printf("%d\n", ans);
//     }

//     return 0;
// }

// D
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id, from, to;
} Op;

int a[25];
Op *ops;
int cnt;

void generate(int m, int from, int to)
{
    if (m == 0)
        return;

    int k = a[m];
    int aux = 6 - from - to; // because pegs are 1,2,3

    generate(m - 1 - k, from, aux);

    ops[cnt++] = (Op){m, from, to};

    generate(m - 1 - k, aux, to);

    generate(k, from, to);
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n;
        scanf("%d", &n);

        int possible = 1;

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] > i - 1)
                possible = 0;
        }

        if (!possible)
        {
            printf("NO\n");
            continue;
        }

        int maxOps = (1 << n) - 1;
        ops = (Op *)malloc((size_t)maxOps * sizeof(Op));
        cnt = 0;

        generate(n, 1, 3);

        printf("YES\n");
        printf("%d\n", cnt);

        for (int i = 0; i < cnt; i++)
        {
            printf("%d %d %d\n",
                   ops[i].id,
                   ops[i].from,
                   ops[i].to);
        }

        free(ops);
    }

    return 0;
}