/***
 *
 * Problem set: Conditional Statements (Lab task 2)
 *
 ***/

#include <stdio.h>
#include <math.h>

int main()
{
    //=>>> Task 1
    /*
    int number;
    printf("Enter a number : ");
    scanf("%d", &number);

    if (number > 0)
    {
        printf("%d is positive\n", number);
    }
    else if (number < 0)
    {
        printf("%d is negetive\n", number);
    }
    else
    {
        printf("%d is zero\n", number);
    }
     */

    //=>>> Task 2
    /*
    int num1, num2, num3, result;
    printf("Enter three number : ");
    scanf("%d%d%d", &num1, &num2, &num3);

    // Process 1
    result = fmax(num1, num2);
    result = fmax(result, num3);
    printf("The largest number is %d\n", result);

    // Process 2
    // if (num1 > num2 && num1 > num3)
    // {
    //     printf("Number 1 is the largest number -> %d\n", num1);
    // }
    // else if (num2 > num1 && num2 > num3)
    // {
    //     printf("Number 2 is the largest number -> %d\n", num2);
    // }
    // else
    // {
    //     printf("Number 3 is the largest number -> %d\n", num3);
    // }
    */

    //=>>> Task 3
    /*
    int year;
    printf("Enter the year : ");
    scanf("%d", &year);

    if (year % 2 == 0)
    {
        printf("%d -> This is leep year\n", year);
    }
    else
    {
        printf("%d -> This is not leep year\n", year);
    }
    */

    //=>>> Task 4
    /*
    int number;
    printf("Enter the number : ");
    scanf("%d", &number);

    if (number % 2 == 0)
    {
        printf("%d -> The number is even\n", number);
    }
    else
    {
        printf("%d -> The number is odd\n", number);
    }
    */

    //=>>> Task 5
    /*
    float math = 70.5, eee = 90.4, cse = 76.7, discMath = 85.3, ban = 70.0, obtained, percentage;
    obtained = math + eee + cse + discMath + ban;
    percentage = (obtained / 500) * 100;
    printf("Obtained mark = %.2f\n", obtained);
    printf("Percentage = %.2f%% \n", percentage);
    if (percentage >= 80 && percentage <= 100)
    {
        printf("Grade = A\n");
    }
    else if (percentage >= 70 && percentage <= 79.9)
    {
        printf("Grade = B\n");
    }
    else if (percentage >= 50 && percentage <= 69.9)
    {
        printf("Grade = C\n");
    }
    else if (percentage >= 30 && percentage <= 49.9)
    {
        printf("Grade = D\n");
    }
    else if (percentage >= 0 && percentage <= 29.9)
    {
        printf("Grade = F\n");
    }
    else
    {
        printf("Invalid mark\n");
    }
    */

    //=>>> Task 6
    /*
    int number;
    printf("Enter a number : ");
    scanf("%d", &number);

    switch (number)
    {
    case 1:
        printf("Sunday\n");
        break;
    case 2:
        printf("Monday\n");
        break;
    case 3:
        printf("Tuesday\n");
        break;
    case 4:
        printf("Wednesday\n");
        break;
    case 5:
        printf("Thursday\n");
        break;
    case 6:
        printf("Friday\n");
        break;
    case 7:
        printf("Saturday\n");
        break;
    default:
        printf("Nothing else\n");
    }
    */

    return 0;
}