#include <stdio.h>
#include <stdbool.h>
#include "./headers/calculateor.h"
#include "./headers/solveSomeProblem.h"

//=>>> Function declaration
int RecursionFunc(int num);

int main()
{
    printf("Name : Al jubair shovon\n");
    // printf("%s\n", AgeCalculator());
    EvenSeries();

    return 0;
}

//=>>> Function definition
// This is Recursion function
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