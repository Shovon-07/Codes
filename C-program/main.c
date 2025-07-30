#include <stdio.h>
#include <stdbool.h>

//=>>> Function declaration
int Calculator(int x, int y);
int RecursionFunc(int num);

int main()
{
    printf("Name : Al jubair shovon\n");

    // int studentId = 252311244, studentPaid = 25100;
    // char studentGrade = 'A';
    // float studentCgpa = 3.73;

    // printf("Student id : %d\n", studentId);
    // printf("Student paid : %d\n", studentPaid);
    // printf("Student grade : %c\n", studentGrade);
    // printf("Student cgpa : %.2f\n", studentCgpa);

    // float price = 20.24;
    // char currency = '$';
    // printf("Price : %.2f%c\n", price, currency);

    // char string[] = "shovon";
    // printf("String : %s\n", string);

    // int num1 = 9, num2 = 2;
    // float res = (float)num1 / num2;
    // printf("Result = %.2f\n", res);

    // const char BIRTHDAY[] = "07/11/2002";
    // printf("%s\n", BIRTHDAY);

    // int age = 20;
    // age >= 18 ? printf("You can voting\n") : printf("Alas!\n");

    // for (int i = 1; i <= 5; i++)
    // {
    //     if (i <= 3)
    //     {
    //         continue;
    //     }
    //     printf("%d\n", i);
    // }

    // int x = 5, y = 2;
    // float result = (float)x / (float)y;
    // printf("%.2f\n", result);

    // int numArr[] = {10, 13, 20, 16, 25, 100};
    // int length = sizeof(numArr) / sizeof(numArr[0]);
    // for (int i = 0; i <= length; i++)
    // {
    //     if (numArr[i] < 15)
    //     {
    //         continue;
    //     }
    //     printf("%d, ", numArr[i]);
    // }

    // char studentName[] = "\"Al jubair shovon\'s\"";
    // printf("%s\n", studentName);

    // int num;
    // float cgpa;
    // printf("Inset a number : ");
    // scanf("%d", &num);
    // printf("Inset Cgpa : ");
    // scanf("%f", &cgpa);
    // printf("Number = %d\ncgpa = %f\n", num, cgpa);

    // char name[30];
    // printf("Enter your first name : ");
    // scanf("%s", name);
    // printf("%s\n", name);

    // char fullname[30];
    // printf("Enter fullname : ");
    // fgets(fullname, sizeof(fullname), stdin);
    // printf("%s\n", fullname);

    // int result[4];
    // result[0] = Calculator(10, 2);
    // result[1] = Calculator(10, 5);
    // result[2] = Calculator(5, 2);
    // result[3] = Calculator(5, 4);

    // int length = sizeof(result) / sizeof(result[0]);
    // for (int i = 0; i < length; i++)
    // {
    //     printf("%d\n", result[i]);
    // }

    // int recursionResult = RecursionFunc(5);
    // printf("Result of recursion : %d\n", recursionResult);

    // int x = 10;
    // int *pointerVar = &x;

    // printf("Value of x = %d\n", x);
    // printf("Address of x = %p\n", &x);

    // printf("Value of pointer variable = %d\n", *pointerVar);
    // printf("Address of pointer variable = ");
    // printf("%p\n", pointerVar);

    int xArr[4];
    xArr[0] = 12;
    xArr[1] = 2;
    xArr[2] = 30;
    xArr[3] = 20;

    int i, length;
    length = sizeof(xArr) / sizeof(xArr[0]);
    for (i = 0; i < length; i++)
    {
        printf("%p\n", &xArr[i]);
    }
    printf("Address of x Array : %p\n", &xArr);

    return 0;
}

//=>>> Function definition
int Calculator(int x, int y)
{
    int n1 = x, n2 = y;
    int res = n1 + n2;
    // printf("%d\n", res);
    return res;
}

int RecursionFunc(int num)
{
    if (num != 0)
    {
        int calc = num + RecursionFunc(num - 1);
        return calc;
    }
    else
    {
        return num;
    }
}

/***
 *
 # Pending =>
 * Multidimensional Arrays
 * String functions
 * Memory address
 * Pointer
 ***/