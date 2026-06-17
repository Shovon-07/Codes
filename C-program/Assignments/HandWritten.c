#include <stdio.h>
#include <string.h>

int main()
{
    //=>>> Problem 1
    // int n, passOrFailFlag = 0;
    // double sum = 0.00, avg = 0.00;
    // char passOrFail[5], grade;

    // struct Students
    // {
    //     char id[100];
    //     int m;
    //     int marks[20];
    // };

    // printf("Enter the length of students : ");
    // scanf("%d", &n);

    // struct Students std[n];

    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter the id of students %d : ", i + 1);
    //     scanf("%s", std[i].id);
    //     printf("Enter the length of marks : ");
    //     scanf("%d", &std[i].m);
    //     for (int j = 0; j < std[i].m; j++)
    //     {
    //         scanf("%d", &std[i].marks[j]);
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("\n");
    //     for (int j = 0; j < std[i].m; j++)
    //     {
    //         sum += std[i].marks[j];
    //         if (std[i].marks[j] < 40)
    //         {
    //             passOrFailFlag = 1;
    //         }
    //     }
    //     avg = sum / std[i].m;
    //     passOrFailFlag == 1 ? strcpy(passOrFail, "Fail") : strcpy(passOrFail, "Pass");

    //     if (80 <= avg)
    //         grade = 'A';
    //     else if (70 <= avg && avg < 80)
    //         grade = 'B';
    //     else if (60 <= avg && avg < 70)
    //         grade = 'C';
    //     else if (50 <= avg && avg < 60)
    //         grade = 'D';
    //     else if (50 > avg)
    //         grade = 'F';

    //     printf("%s %.2lf %c %s\n", std[i].id, avg, grade, passOrFail);

    //     sum = 0, avg = 0, passOrFailFlag = 0;
    // }

    //=>>> Problem 2
    int t, n;
    int price, qty;
    printf("Enter number of Customers: ");
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        printf("Number of items of customer %d : ", i + 1);
        scanf("%d", &n);

        double total = 0;

        for (int j = 0; j < n; j++)
        {
            printf("Enter Price and Quantity : ");
            scanf("%d %d", &price, &qty);
            total += price * qty;
        }

        if (total >= 5000)
            total -= total * 0.10;
        else if (total >= 2000 && total < 5000)
            total -= total * 0.05;

        printf("%.0f\n", total);
    }

    return 0;
}