#include <stdio.h>
#include <string.h>
#include <math.h>
#include "./headers/calculateor.h"

struct students
{
    char name[100];
    int id;
    float cgpa;
};

int main()
{
    // int x, y;
    // printf("Enter two number : \n");
    // scanf("%d%d", &x, &y);
    // addition(x, y);
    // substract(x, y);
    // multiply(x, y);
    // division(x, y);

    // struct students s1;
    // struct students s2;

    // strcpy(s1.name, "Al jubair shovon");
    // s1.id = 252311244;
    // s1.cgpa = 3.01;
    // printf("Name : %s\n", s1.name);
    // printf("Id = %d\n", s1.id);
    // printf("Cgpa = %.2f\n", s1.cgpa);

    // strcpy(s2.name, "Mst zerin akter");
    // s2.id = 252311246;
    // s2.cgpa = 2.70;
    // printf("Name : %s\n", s2.name);
    // printf("Id = %d\n", s2.id);
    // printf("Cgpa = %.2f\n", s2.cgpa);

    // 3
    double r, a, n = 3.14159;
    scanf("%lf", &r);
    a = n * r * r;
    printf("A=%.4lf\n", a);

    // 4
    int a, b, soma;
    scanf("%d%d", &a, &b);
    soma = a + b;
    printf("SOMA = %d\n", soma);

    return 0;
}