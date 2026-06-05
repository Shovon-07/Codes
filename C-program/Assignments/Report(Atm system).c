#include <stdio.h>

void deposit(long long *balance, long long amount);
void withdraw(long long *balance, long long amount);
void showBalance(long long balance);

long long initBalance, depAmmount, witdrawAmmount, newBalance;

int main()
{
    printf("Enter initial balance : ");
    scanf("%lld", &initBalance);

    int q;
    printf("How many times do you want to query? : ");
    scanf("%d", &q);

    for (int i = 1; i <= q; i++)
    {
        int button;
        printf("\nPress 1 for deposit, Press 2 for withdraw, Press 3 for check balance : ");
        scanf("%d", &button);

        switch (button)
        {
        case 1:
            printf("Enter deposit ammount : ");
            scanf("%lld", &depAmmount);
            deposit(&initBalance, depAmmount);
            break;
        case 2:
            printf("Enter withdraw ammount : ");
            scanf("%lld", &witdrawAmmount);
            withdraw(&initBalance, witdrawAmmount);
            break;
        case 3:
            showBalance(initBalance);
            break;
        default:
            printf("Invalid input\n");
            break;
        }
    }

    return 0;
}

void deposit(long long *balance, long long amount)
{
    initBalance = *balance + amount;
    printf("Balance : %lld\n", initBalance);
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
        initBalance = *balance - amount;
        printf("Balance : %lld\n", initBalance);
    }
}

void showBalance(long long balance)
{
    printf("Balance : %lld\n", balance);
}