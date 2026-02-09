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
    if (num1 > num2 && num1 > num3)
    {
        printf("Number 1 is the largest number -> %d\n", num1);
    }
    else if (num2 > num1 && num2 > num3)
    {
        printf("Number 2 is the largest number -> %d\n", num2);
    }
    else
    {
        printf("Number 3 is the largest number -> %d\n", num3);
    }
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

    //=>>> Task 7
    /*
    int age;
    printf("Enter age : ");
    scanf("%d", &age);
    if (age >= 18)
    {
        printf("Eligible to vote\n");
    }
    else
    {
        printf("Not eligible to vote\n");
    }
    */

    //=>>> Task 8
    /*
    char charecter;
    printf("Type something : ");
    scanf("%c", &charecter);

    if ((charecter >= 'A' && charecter <= 'Z') || (charecter >= 'a' && charecter <= 'z'))
    {
        printf("This is charecter\n");
    }
    else if (charecter >= '0' && charecter <= '9')
    {
        printf("This is number\n");
    }
    else
    {
        printf("This is special charecter\n");
    }
    */

    //=>>> Task 9
    /*
    float basicSalary, hra, da, grossSalary;
    printf("Enter basic salary : ");
    scanf("%f", &basicSalary);

    if (basicSalary >= 20000)
    {
        hra = basicSalary * (30.0 / 100);
        da = basicSalary * (95.0 / 100);
    }
    else
    {
        hra = basicSalary * (20.0 / 100);
        da = basicSalary * (80.0 / 100);
    }
    grossSalary = basicSalary + hra + da;

    printf("Basic salary = %.2f\n", basicSalary);
    printf("HRA = %.2f\n", hra);
    printf("DA = %.2f\n", da);
    printf("Gross salary = %.2f\n", grossSalary);
    */

    //=>>> Task 10
    /*
    int number;
    printf("Enter a number : ");
    scanf("%d", &number);

    switch (number)
    {
    case 1:
        printf("January\n");
        break;
    case 2:
        printf("February\n");
        break;
    case 3:
        printf("March\n");
        break;
    case 4:
        printf("April\n");
        break;
    case 5:
        printf("May\n");
        break;
    case 6:
        printf("June\n");
        break;
    case 7:
        printf("July\n");
        break;
    case 8:
        printf("August\n");
        break;
    case 9:
        printf("September\n");
        break;
    case 10:
        printf("October\n");
        break;
    case 11:
        printf("November\n");
        break;
    case 12:
        printf("December\n");
        break;
    default:
        printf("Nothing else\n");
    }
    */

    //=>>> Task 11
    /*
    float sellingPrice, costPrice, difference;
    printf("Enter selling price : ");
    scanf("%f", &sellingPrice);

    printf("Enter cost price : ");
    scanf("%f", &costPrice);

    difference = sellingPrice - costPrice;
    if (difference < 0)
    {
        printf("Loss = %.2f/-\n", -difference);
    }
    else if (difference > 0)
    {
        printf("Profit = %.2f/-\n", difference);
    }
    else
    {
        printf("No profit or loss\n");
    }
    */

    //=>>> Task 12
    /*
    float arm1, arm2, arm3;
    printf("Enter the length of first side of the triangle : ");
    scanf("%f", &arm1);
    printf("Enter the length of second side of the triangle : ");
    scanf("%f", &arm2);
    printf("Enter the length of third side of the triangle : ");
    scanf("%f", &arm3);

    if (arm1 + arm2 > arm3 && arm1 + arm3 > arm2 && arm2 + arm3 > arm1)
    {
        printf("They can form a valid triangle\n");
    }
    else
    {
        printf("They cannot form a valid triangle\n");
    }
    */

    //=>>> Task 13
    /*
    float arm1, arm2, arm3;
    printf("Enter the length of first side of the triangle : ");
    scanf("%f", &arm1);
    printf("Enter the length of second side of the triangle : ");
    scanf("%f", &arm2);
    printf("Enter the length of third side of the triangle : ");
    scanf("%f", &arm3);

    if (arm1 + arm2 > arm3 && arm1 + arm3 > arm2 && arm2 + arm3 > arm1)
    {
        printf("They can form a valid triangle\n");

        if (arm1 == arm2 && arm1 == arm3 && arm2 == arm3)
        {
            printf("This equilateral triangle\n");
        }
        else if (arm1 == arm2 || arm1 == arm3 || arm2 == arm3)
        {
            printf("This isosceles triangle\n");
        }
        else
        {
            printf("This scalene triangle\n");
        }
    }
    else
    {
        printf("They cannot form a valid triangle\n");
    }
    */

    //=>>> Task 14
    /*
    int number;
    printf("Enter a number : ");
    scanf("%d", &number);

    switch (number)
    {
    case 1:
        printf("One\n");
        break;
    case 2:
        printf("Two\n");
        break;
    case 3:
        printf("Three\n");
        break;
    case 4:
        printf("Four\n");
        break;
    case 5:
        printf("Five\n");
        break;
    default:
        printf("Nothing else\n");
        break;
    }
    */

    //=>>> Task 15
    /*
    int x, y;
    printf("Enter coordinate points (x & y) : ");
    scanf("%d%d", &x, &y);

    if (x > 0 && y > 0)
    {
        printf("First quadrant\n");
    }
    else if (x < 0 && y > 0)
    {
        printf("Second quadrant\n");
    }
    else if (x < 0 && y < 0)
    {
        printf("Third quadrant\n");
    }
    else if (x > 0 && y < 0)
    {
        printf("Fourth quadrant\n");
    }
    else
    {
        printf("X = %d; Y= %d\n", x, y);
    }
    */

    return 0;
}