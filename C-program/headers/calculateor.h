#ifndef CALC_H
#define CALC_H
#include <stdio.h>

int addition(int a, int b)
{
    int result = a + b;
    printf("Addition = %d\n", result);
}
int substract(int a, int b)
{
    int result = a - b;
    printf("Substract = %d\n", result);
}
int multiply(int a, int b)
{
    int result = a * b;
    printf("Multiply = %d\n", result);
}
int division(int a, int b)
{
    int result = a / b;
    printf("Division = %d\n", result);
}

#endif