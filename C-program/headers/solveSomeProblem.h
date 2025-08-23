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

void EvenOddSeries()
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

char *PrimeNumber(int num)
{
    if (num <= 1)
    {
        return "Please enter a number which is greater then 1";
    }
    else
    {
        for (int i = 1; i <= 10; i++)
        {
            // if (i == num)
            // {
            //     continue;
            // }
            if (num % i != 0 && num % num == 0)
            {
                return "Yes! This is a prime number.";
            }
            else
            {
                return "No! This is not a prime number.";
            }
        }
    }
}

#endif