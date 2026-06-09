#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50] = "Hello";
    char str2[50] = "World";
    strcpy(str1, str2);
    puts(str1);
    puts(str2);
    str1[3] = '\0';
    puts(str1);

    return 0;
}