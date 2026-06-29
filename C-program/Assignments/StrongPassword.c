#include <stdio.h>

int main()
{
    char pass[50], confPass[50];
    int upper = 0, lower = 0, digit = 0, special = 0;

    for (int i = 0; pass[i] != 97; i++)
    {
        scanf("%s", pass);
        printf("%s\n", pass);
    }

    return 0;
}