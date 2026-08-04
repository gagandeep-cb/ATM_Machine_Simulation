#include <stdio.h>
#include "account.h"

void account_details(char *bank_name,
                     char *account_name,
                     char *username,
                     float *balance)
{
    printf("\n=====================================\n");
    printf("         ACCOUNT DETAILS\n");
    printf("=====================================\n");

    printf("Bank Name      : %s\n", bank_name);
    printf("Account Holder : %s\n", account_name);
    printf("Username       : %s\n", username);
    printf("Current Balance: %.2f\n", *balance);

    printf("=====================================\n");
}