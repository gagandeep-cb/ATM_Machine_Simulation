#include <stdio.h>
#include <string.h>
#include "login.h"

int verify_username(char username[])
{
    int attempts = 0;
    char input_username[20];
    printf("\n========== Welcome to the ATM. Please insert your card... ==========\n\n");
    while (attempts < 3)
    {
        printf("Enter Username: ");
        scanf("%s", input_username);

        if (strcasecmp(username, input_username) == 0)
        {
            printf("Username verified.\n");
            return 1;
        }

        printf("Invalid Username.\n");

        attempts++;
        if (attempts == 3)
        {
            printf("Maximum login attempts reached.\n");
            printf("Please remove your card. Thank you.\n");
            return 0;
        }
    }

    return 0;
}

int verify_pin(int pin)
{
    int attempts = 0;
    int input_pin;

    while (attempts < 3)
    {
        printf("Enter your PIN: ");
        scanf("%d", &input_pin);

        if (input_pin == pin)
        {
            printf("PIN verified.\n");
            return 1;
        }

        printf("Incorrect PIN.\n");
        attempts++;
        if (attempts == 3)
        {
            printf("You have reached the maximum number of attempts.\n");
            printf("Please remove your card. Thank you.\n");
            return 0;
        }
    }
    return 0 ;
}

void change_pin(int *pin)
{
    int old_pin, new_pin;

    printf("Enter your old PIN: ");
    scanf("%d", &old_pin);

    if (old_pin == *pin)
    {
        printf("Enter your new PIN: ");
        scanf("%d", &new_pin);

        *pin = new_pin;

        printf("Your PIN has been changed successfully.\n");
    }
    else
    {
        printf("Incorrect old PIN. PIN change failed.\n");
    }
}
void change_username(char username[])
{
    char current_username[20];
    char new_username[20];
    char confirm_username[20];

    int username_attempts = 0;

    while (username_attempts < 3)
    {
        printf("Enter Current Username: ");
        scanf("%19s", current_username);

        if (strcmp(username, current_username) == 0)
        {
            printf("Username Verified.\n");
            break;
        }

        printf("Invalid Username.\n");
        username_attempts++;
    }

    if (username_attempts == 3)
    {
        printf("Maximum attempts reached.\n");
        return;
    }

    int change_attempts = 0;

    while (change_attempts < 3)
    {
        printf("Enter New Username: ");
        scanf("%19s", new_username);

        if (strcmp(username, new_username) == 0)
        {
            printf("New username cannot be the same as the old username.\n");
            change_attempts++;
            continue;
        }

        printf("Confirm Username: ");
        scanf("%19s", confirm_username);

        if (strcmp(new_username, confirm_username) == 0)
        {
            strcpy(username, new_username);

            printf("Username changed successfully.\n");
            return;
        }

        printf("Username mismatch.\n");
        change_attempts++;
    }

    printf("Maximum attempts reached.\n");
}