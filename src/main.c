#include <stdio.h>
#include "account.h"
#include "login.h"
#include "transaction.h"
#include "menu.h"
#include "file.h"
#include <string.h>

int main()
{
    struct account user;

    strcpy(user.account_name, "Gagandeep Banakar");
    strcpy(user.bank_name, "STATE BANK OF INDIA");
    strcpy(user.username, "gagan");

    user.balance = load_balance();
    user.pin = 2345;

    float history[10];
    int count = 0;

    float last_deposit = 0;
    float last_withdraw = 0;
    float last_fast_cash = 0;

    if (verify_username(user.username))
    {
        printf("Success\n");
    }
    else
    {
        // printf("Failed\n");
        return 0;
    }

    if (verify_pin(user.pin))
    {
        printf("Login successful.\n");
    }
    else
    {
        // printf("Login failed.\n");
        return 0;
    }

    printf("\n==========================================\n");
    printf("          %s\n", user.bank_name);
    printf("==========================================\n");

    printf("Account Holder : %s\n", user.account_name);
    printf("Username       : %s\n", user.username);

    int choice;
    while (1)
    {
        menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            deposit(&user.balance, history, &count, &last_deposit);
            save_balance(user.balance);
            save_history("DEPOSIT", last_deposit);
            break;

        case 2:
            withdraw(&user.balance, history, &count, &last_withdraw);
            save_balance(user.balance);
            save_history("WITHDRAW", last_withdraw);
            break;

        case 3:

            fast_cash(&user.balance,
                      history,
                      &count,
                      &last_fast_cash);

            save_balance(user.balance);

            save_history("FAST CASH", last_fast_cash);

        case 4:
            mini_statement(user.balance,
                           history,
                           count,
                           last_deposit,
                           last_withdraw);
            break;

        case 5:
            change_pin(&user.pin);
            break;

        case 6:
            change_username(user.username);
            break;

        case 7:
            account_details(&user);
            break;
        case 8:
            printf("Your current balance is: %.2f\n", user.balance);
            break;
        case 9:
            printf("Thank you for using our ATM.\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}