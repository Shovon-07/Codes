/***
 *
 * A commercial bank has introduced an incentive policy of giving bonus to all its deposit holders. The policy is as follows: A bonus of 2 per cent of the balance held on 31st December is given to every one, inspective of their balance, and 5 per cent is given to female account holders if their balance is more than Tk. 50,000.
 *
 ***/

#include <stdio.h>

int main()
{
    char gender = 'f';
    float balance = 50000.1, bonus;

    if (gender == 'f')
    {
        if (balance > 50000.0)
        {
            bonus = balance * (5.0 / 100);
        }
        else
        {
            bonus = balance * (2.0 / 100);
        }
    }
    else
    {
        bonus = balance * (2.0 / 100);
    }

    printf("Bonus = %.3f\n", bonus);
    printf("New balance = %.3f\n", balance + bonus);

    return 0;
}