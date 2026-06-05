#include <stdio.h>

int main()
{
    //=>>> Problem 1
    int stdLength, sum = 0, avg = 0;

    struct Students
    {
        char id[100];
        int markLength;
        int marks[20];
    };

    printf("Enter the length of students : ");
    scanf("%d", &stdLength);

    struct Students std[stdLength];

    for (int i = 0; i < stdLength; i++)
    {
        printf("Enter the id of students %d : ", i + 1);
        scanf("%s", std[i].id);
        printf("Enter the length of marks : ");
        scanf("%d", &std[i].markLength);
        for (int j = 0; j < std[i].markLength; j++)
        {
            scanf("%d", &std[i].marks[j]);
        }
    }

    for (int i = 0; i < stdLength; i++)
    {
        printf("\n");
        printf("%s\n", std[i].id);
        for (int j = 0; j < std[i].markLength; j++)
        {
            sum += std[i].marks[j];
            // printf("%d\n", std[i].marks[j]);
        }
        avg = sum / std[i].markLength;
        printf("Sum = %d\n", sum);
        printf("Avg = %d\n", avg);
    }

    return 0;
}