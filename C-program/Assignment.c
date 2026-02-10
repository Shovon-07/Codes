/***
 *
 * Make a Calculator that will take 2 input and shows the output. Try to input operator from user using char.
 *
 ***/

#include <stdio.h>

int main()
{
    char operator;
    int num1, num2, result;

    printf("Type an operator between (+ - * / %%) : ");
    scanf("%c", &operator);

    if (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '%')
    {
        printf("Enter number 1 : ");
        scanf("%d", &num1);
        printf("Enter number 2 : ");
        scanf("%d", &num2);

        switch (operator)
        {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '%':
            result = num1 % num2;
            break;
        default:
            printf("Nothing else\n");
            break;
        }
        printf("Result : %d %c %d = %d\n", num1, operator, num2, result);
    }
    else
    {
        printf("Please enter a valid operator\n");
    }

    return 0;
}