#include <stdio.h>
#include "account.h"

void account_details(struct account *user)
{
    printf("\n=====================================\n");
    printf("         ACCOUNT DETAILS\n");
    printf("=====================================\n");

    printf("Bank Name      : %s\n", user->bank_name);
    printf("Account Holder : %s\n", user->account_name);
    printf("Username       : %s\n", user-> username);
    printf("Current Balance: %.2f\n", user->balance);

    printf("=====================================\n");
}