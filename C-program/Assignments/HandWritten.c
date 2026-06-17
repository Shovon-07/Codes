#include <stdio.h>
#include <string.h>

int main()
{
    //=>>> Problem 1
    int stdLength, passOrFailFlag = 0;
    double sum = 0.00, avg = 0.00;
    char passOrFail[5], grade;

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
        for (int j = 0; j < std[i].markLength; j++)
        {
            sum += std[i].marks[j];
            if (std[i].marks[j] < 40)
            {
                passOrFailFlag = 1;
            }
        }
        avg = sum / std[i].markLength;
        passOrFailFlag == 1 ? strcpy(passOrFail, "Fail") : strcpy(passOrFail, "Pass");

        if (80 <= avg)
        {
            grade = 'A';
        }
        else if (70 <= avg && avg < 80)
        {
            grade = 'B';
        }
        else if (60 <= avg && avg < 70)
        {
            grade = 'C';
        }
        else if (50 <= avg && avg < 60)
        {
            grade = 'D';
        }
        else if (50 > avg)
        {
            grade = 'F';
        }

        printf("%s %.2lf %c %s\n", std[i].id, avg, grade, passOrFail);

        sum = 0;
        avg = 0;
        passOrFailFlag = 0;
    }

    //=>>> Problem 2

    return 0;
}