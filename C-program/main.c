#include <stdio.h>

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
    float celsius = 40;
    float fahrenheit = (celsius * 9 / 5) + 32;
    printf("Celsius to fahrenheit = %f\n", fahrenheit);

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