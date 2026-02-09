#include <stdio.h>
#include <math.h>
#define PI 3.14159

void AllAarithmeticOperations()
{
    int n1, n2, result;
    printf("Please enter first number : ");
    scanf("%d", &n1);
    printf("Please enter second number : ");
    scanf("%d", &n2);

    result = n1 + n2;
    printf("Sum = %d\n", result);

    result = n1 - n2;
    printf("Difference = %d\n", result);

    result = n1 * n2;
    printf("Product = %d\n", result);

    result = n1 / n2;
    printf("Quotient = %d\n", result);

    result = n1 % n2;
    printf("Reminder = %d\n", result);
}

void AreaAndPerimeter()
{
    int width, length, area, perimeter;

    printf("Please enter width : ");
    scanf("%d", &width);
    printf("Please enter length : ");
    scanf("%d", &length);

    area = width * length;
    printf("Area = %d\n", area);

    perimeter = 2 * (width + length);
    printf("Perimeter = %d\n", perimeter);
}

void ValueSwaping()
{
    int a = 10, b = 20, temp;

    a = a + b;
    b = a - b;
    a = a - b;

    printf("A = %d\n", a);
    printf("B = %d\n", b);
}

void SquareAndCube()
{
    int result;
    result = pow(2, 2);
    printf("Square = %d\n", result);
    result = pow(2, 3);
    printf("Cube = %d\n", result);
}

int main()
{
    // AllAarithmeticOperations();
    // AreaAndPerimeter();
    // ValueSwaping();
    // SquareAndCube();

    // float math = 60, phy = 70, che = 40, total, percentage;
    // total = math + phy + che;
    // percentage = ((float)total / 500) * 100;
    // printf("Percentage = %.2f\n", percentage);

    double angle = 45.0 * (3.14159 / 180.0);
    printf("Sin = %f\n", sin(angle));
    return 0;
}