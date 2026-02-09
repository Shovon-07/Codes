#include <stdio.h>

#include <stdio.h>
#include <math.h>

//=>>> Function declaration
//=>>> Task 3
void PerformAllArOpp(int x, int y, char operator);

int main()
{
    //=>>> Task 1
    // int integerNumber = 5;
    // float floatingNumber = 2.1234567890;
    // double doubleNumber = 2.1234567890;
    // char character = 'A';

    // printf("%d\n", integerNumber);
    // printf("%f\n", floatingNumber);
    // printf("%lf\n", doubleNumber);
    // printf("%c\n", character);

    //=>>> Task 2
    // int n1 = 3;
    // int n2 = 2;
    // float result = n1 + n2;
    // printf("Sum = %f\n", result);

    //=>>> Task 3
    // PerformAllArOpp(10, 2, '+');

    //=>>> Task 4
    // float length = 10, breadth = 5;
    // float perimeter = 2 * (length + breadth);
    // printf("Perimeter = %f\n", perimeter);

    //=>>> Task 5
    // float length = 12, breadth = 4;
    // float area = length * breadth;
    // printf("Area = %f\n", area);

    //=>>> Task 6
    // float radius = 15;
    // float diameter = 2 * radius;
    // float circumference = 2 * 3.1416 * radius;
    // float area = 3.1416 * (radius * radius);
    // printf("Diameter = %f\n", diameter);
    // printf("Circumference = %f\n", circumference);
    // printf("Area = %f\n", area);

    //=>>> Task 7
    // float lengthInCm = 500;
    // float meter = lengthInCm / 100;
    // float kMeter = lengthInCm / 100000;
    // printf("Cm to m = %f\n", meter);
    // printf("Cm to km = %f\n", kMeter);

    //=>>> Task 8
    // float celsius = 40;
    // float fahrenheit = (celsius * 9 / 5) + 32;
    // printf("Celsius to fahrenheit = %f\n", fahrenheit);

    //=>>> Task 9
    //=>>> Task 10
    // int years, weeks, days;
    // int totalDays;
    // printf("Enter days = ");
    // scanf("%d", &totalDays);

    // years = totalDays / 365;
    // weeks = (totalDays % 365) / 7;
    // days = (totalDays % 365) % 7;
    // printf("Year/s = %d\nWeeks = %d\nDays = %d\n", years, weeks, days);

    //=>>> Task 11 & 12
    // int power = pow(2, 2);
    // int squreRoot = sqrt(49);
    // printf("Power = %d\n", power);
    // printf("Squre root = %d\n", squreRoot);

    //=>>> Task 13
    // int angle_1 = 90, angle_2 = 45, angle_3;
    // angle_3 = 180 - (angle_1 + angle_2);
    // printf("Third angle = %d\n", angle_3);

    //=>>> Task 14
    // float base = 100, height = 50, area;
    // area = ((float)1 / (float)2) * (base * height);
    // printf("Area of triangle = %.2f\n", area);

    //=>>> Task 15
    // float area = (sqrt(3) * pow(50, 2)) / 4; // side = 50
    // printf("Area of equilateral = %.2f\n", area);

    // Task 16
    float math = 90, phy = 86, che = 80, eee = 91, eng = 90, total, average, percentage;
    total = math + phy + che + eee + eng;
    average = total / (float)5;
    percentage = (total / (float)500) * (float)100;
    printf("Total = %.2f\n", total);
    printf("Total = %.2f\n", average);
    printf("Percentage = %.2f%%\n", percentage); // percentage = ((math+phy+che+eee+eng) / The sum of the highest marks in each subject) * 100

    // Task 17
    // Task 18
    float p, t, t, compoundInterest;

    return 0;
}

//=>>> Function definition
//=>>> Task 3
void PerformAllArOpp(int x, int y, char operator)
{
    int result = 0;

    if (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '%')
    {
        printf("Please enter a valid operator!\n");
    }
    else
    {
        switch (operator)
        {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        case '%':
            result = x % y;
            break;
        default:
            break;
        }
        printf("Result of (%d %c %d) = %d\n", x, operator, y, result);
    }
}