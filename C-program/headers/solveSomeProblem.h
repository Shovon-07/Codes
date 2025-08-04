#ifndef solveSomeProblem_H
#define solveSomeProblem_H
#include <stdio.h>

char *AgeCalculator()
{
    int age;
    printf("Please enter your age : ");
    scanf("%d", &age);

    if (18 > age)
    {
        return "You are a minor";
    }
    else if (18 <= age && age <= 60)
    {
        return "You are an adult";
    }
    else if (age > 60)
    {
        return "You are a senior citizen";
    }
}

void EvenSeries()
{
    int i;
    for (i = 1; i <= 100; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d, ", i);
        }
    }
}

#endif