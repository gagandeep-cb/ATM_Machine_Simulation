#include <stdio.h>
#include "account.h"
#include "login.h"
#include "transaction.h"
#include "menu.h"

int main()
{

    char bank_name[50] = "STATE BANK OF INDIA";
    char account_name[50] = "Gagandeep Banakar";
    char username[50] = "gagan";

    float history[10];
    int count = 0;

    float last_deposit = 0;
    float last_withdraw = 0;

    float balance = 2000;

    if (verify_username(username))
    {
        printf("Success\n");
    }
    else
    {
        //printf("Failed\n");
        return 0;
    }

    int pin = 1234;

    if (verify_pin(pin))
    {
        printf("Login successful.\n");
    }
    else
    {
       // printf("Login failed.\n");
        return 0;
    }

    printf("\n==========================================\n");
    printf("          %s\n", bank_name);
    printf("==========================================\n");

    printf("Account Holder : %s\n", account_name);
    printf("Username       : %s\n", username);

    int choice;
    while (1)
    {
        menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            deposit(&balance, history, &count, &last_deposit);
            break;

        case 2:
            withdraw(&balance, history, &count, &last_withdraw);
            break;

        case 3:
            fast_cash(&balance, history, &count);
            break;

        case 4:
            mini_statement(balance,
                           history,
                           count,
                           last_deposit,
                           last_withdraw);
            break;

        case 5:
            change_pin(&pin);
            break;

        case 6:
            change_username(username);
            break;

        case 7:
            account_details(bank_name,
                            account_name,
                            username,
                            &balance);
            break;
                case 8:
            printf("Your current balance is: %.2f\n", balance);
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