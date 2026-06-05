#include <stdio.h>

void deposit(long long *balance, long long amount);
void withdraw(long long *balance, long long amount);
void showBalance(long long balance);

long long initBalance = 50000;

int main()
{
    int query;

    printf("Press 1 for deposit, 2 for withdraw, 3 for check balance : ");
    scanf("%d", &query);

    switch (query)
    {
    case 1:
    {
        long long depositAmount;
        printf("Enter deposit amount : ");
        scanf("%lld", &depositAmount);

        deposit(&initBalance, depositAmount);
        break;
    }

    case 2:
    {
        long long withdrawAmount;
        printf("Enter withdraw amount : ");
        scanf("%lld", &withdrawAmount);

        withdraw(&initBalance, withdrawAmount);
        break;
    }

    case 3:
        showBalance(initBalance);
        break;

    default:
        printf("Invalid input\n");
        break;
    }

    return 0;
}

void deposit(long long *balance, long long amount)
{
    *balance += amount;
    printf("Balance : %lld\n", *balance);
}

void withdraw(long long *balance, long long amount)
{
    if (*balance < amount)
    {
        printf("Insufficient Balance\n");
        printf("Balance : %lld\n", *balance);
    }
    else
    {
        *balance -= amount;
        printf("Balance : %lld\n", *balance);
    }
}

void showBalance(long long balance)
{
    printf("Balance : %lld\n", balance);
}

// #include <stdio.h>

// void deposit(long long *balance, long long amount);
// void withdraw(long long *balance, long long amount);
// void showBalance(long long balance);

// long long initBalance = 50000, query, depAmmount, witdrawAmmount, newBalance;

// int main()
// {
//     int query;
//     printf("Press 1 for deposit, 2 for withdraw, 3 for check balance : ");
//     scanf("%d", &query);

//     switch (query)
//     {
//     case 1:
//         printf("Enter deposit ammount : ");
//         scanf("%lld", &depAmmount);
//         deposit(initBalance, depAmmount);
//         break;
//     case 2:
//         printf("Enter withdraw ammount : ");
//         scanf("%lld", &witdrawAmmount);
//         withdraw(initBalance, witdrawAmmount);
//         break;
//     case 3:
//         showBalance(initBalance);
//         break;
//     default:
//         printf("Invalid input\n");
//         break;
//     }

//     return 0;
// }

// void deposit(long long *balance, long long amount)
// {
//     initBalance = balance + amount;
//     printf("Balance %lld\n", initBalance);
// }

// void withdraw(long long *balance, long long amount)
// {
//     if (balance < amount)
//     {
//         printf("Insufficient Balance\n");
//     }
//     else
//     {
//         newBalance = balance - amount;
//         printf("Balance : %lld\n", newBalance);
//     }
// }

// void showBalance(long long balance)
// {
//     printf("Balance : %lld\n", balance);
// }