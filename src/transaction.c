#include <stdio.h>
#include "transaction.h"

void deposit(float *balance,
             float history[],
             int *count,
             float *last_deposit)
{
    float amount;

    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);

    *balance += amount;

    history[*count] = amount;
    (*count)++;

    *last_deposit = amount;

    printf("Amount deposited successfully.\n");
}
void withdraw(float *balance,
              float history[],
              int *count,
              float *last_withdraw)
{
    float amount;

    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= *balance)
    {
        *balance -= amount;

        history[*count] = -amount;
        (*count)++;

        *last_withdraw = amount;

        printf("Amount withdrawn successfully.\n");
    }
    else
    {
        printf("Insufficient balance.\n");
    }
}
void fast_cash(float *balance,
               float history[],
               int *count,
               float *last_fast_cash)

{
    float amount;
    int fast_choice;

    printf("\nFast Cash Options:\n");
    printf("1. 100\n");
    printf("2. 500\n");
    printf("3. 1000\n");
    printf("4. 2000\n");

    printf("Choose amount: ");
    scanf("%d", &fast_choice);

    if (fast_choice == 1)
        amount = 100;
    else if (fast_choice == 2)
        amount = 500;
    else if (fast_choice == 3)
        amount = 1000;
    else if (fast_choice == 4)
        amount = 2000;
    else
    {
        printf("Invalid choice.\n");
        return;
    }

    if (amount <= *balance)
    {
        *balance -= amount;

        history[*count] = -amount;
        (*count)++;
        *last_fast_cash = amount;

        printf("Fast cash withdrawn successfully.\n");
    }
    else
    {
        printf("Insufficient balance.\n");
    }
}
void mini_statement(float balance,
                    float history[],
                    int count,
                    float last_deposit,
                    float last_withdraw)
{
    printf("\n------ Mini Statement ------\n");

    printf("Current Balance : %.2f\n", balance);
    printf("Last Deposit    : %.2f\n", last_deposit);
    printf("Last Withdraw   : %.2f\n", last_withdraw);

    printf("\nTransaction History:\n");

    for (int i = 0; i < count; i++)
    {
        printf("%.2f\n", history[i]);
    }
}