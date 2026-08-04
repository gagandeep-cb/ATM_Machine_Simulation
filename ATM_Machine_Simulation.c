#include <stdio.h>
#include <string.h>
void account_details(char *bank_name, char *account_name, char *username, float *balance)
{
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
}
int main()
{
    int pin1 = 2345, pin2;
    char account_name[30] = "Gagandeep Banakar";
    char bank_name[] = "STATE BANK OF INDIA";
    char username[20] = "gagan";
    char input_username[20];
    char new_username[20];
    char confirm_username[20];
    int choice;
    float balance = 2000, amount;
    float history[10];
    int count = 0;
    float last_deposit = 0, last_withdraw = 0;
    int attempts = 0;
    printf("\n========== Welcome to the ATM. Please insert your card... ==========\n\n");

    while (attempts < 3)
    {
        printf("Enter Username: ");
        scanf("%s", input_username);

        if (strcasecmp(username, input_username) == 0)
        {
            printf("Username verified.\n");
            break;
        }
        printf("Invalid Username. Please try again.\n");
        attempts++;
        if (attempts == 3)
        {
            printf("Maximum login attempts reached.\n");
            printf("Please remove your card. Thank you.\n");
            return 0;
        }
    }

    while (attempts < 3)
    {
        printf("Please enter your ATM PIN: ");
        scanf("%d", &pin2);

        if (pin2 == pin1)
        {
            printf("\nPIN is correct. Please continue.\n");
            printf("\n==========================================\n");
            printf("          %s\n", bank_name);
            printf("==========================================\n");
            printf("\nAccount Holder : %s\n", account_name);
            printf("Username : %s\n", username);

            printf("\nLogin Successful!\n");
            printf("\n==========================================\n");
            break;
        }
        else
        {
            printf("Incorrect PIN. Please try again.\n");
            attempts++;

            if (attempts == 3)
            {
                printf("You have reached the maximum number of attempts.\n");
                printf("Please remove your card. Thank you.\n");
                return 0;
            }
        }
    }

    do
    {
        printf("\n<------ ATM Main Menu ------>\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Fast Cash\n");
        printf("5. Mini Statement\n");
        printf("6. Change PIN\n");
        printf("7. Change Username\n");
        printf("8. Account Details\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Your current balance is: %.2f\n", balance);
            break;

        case 2:
            printf("Enter the amount to deposit: ");
            scanf("%f", &amount);

            balance = balance + amount;
            history[count] = amount;
            count++;
            last_deposit = amount;

            printf("The amount has been deposited successfully.\n");
            break;

        case 3:
            printf("Enter the amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= balance)
            {
                balance = balance - amount;
                history[count] = -amount;
                count++;
                last_withdraw = amount;

                printf("The amount has been withdrawn successfully.\n");
            }
            else
            {
                printf("Insufficient balance.\n");
            }
            break;
        case 4:
        {
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
                break;
            }

            if (amount <= balance)
            {
                balance = balance - amount;

                history[count] = -amount;
                count++;

                printf("Fast cash withdrawn successfully.\n");
            }
            else
            {
                printf("Insufficient balance.\n");
            }
            break;
        }
        case 5:
            printf("\n------ Mini Statement ------\n");
            printf("Current Balance : %.2f\n", balance);
            printf("Last Deposit    : %.2f\n", last_deposit);
            printf("Last Withdraw   : %.2f\n", last_withdraw);
            printf("\nTransaction History:\n");

            for (int i = 0; i < count; i++)
            {
                printf("%.2f\n", history[i]);
            }
            break;
        case 6:
        {
            int old_pin, new_pin;

            printf("Enter your old PIN: ");
            scanf("%d", &old_pin);

            if (old_pin == pin1)
            {
                printf("Enter your new PIN: ");
                scanf("%d", &new_pin);

                pin1 = new_pin;

                printf("Your PIN has been changed successfully.\n");
            }
            else
            {
                printf("Incorrect old PIN. PIN change failed.\n");
            }
            break;
        }
        case 7:
        {
            char current_username[20];

            int username_attempts = 0;

            while (username_attempts < 3)
            {
                printf("Enter Current Username: ");
                scanf("%s", current_username);

                if (strcmp(username, current_username) == 0)
                {
                    printf("Username Verified.\n");
                    break;
                }
                else
                {
                    printf("Invalid Username. Please try again.\n");
                    username_attempts++;
                }
            }

            if (username_attempts == 3)
            {
                printf("Maximum attempts reached.\n");
                break;
            }

            int change_attempts = 0;

            while (change_attempts < 3)
            {
                printf("Enter New Username: ");
                scanf("%s", new_username);

                if (strcmp(username, new_username) == 0)
                {
                    printf("New username cannot be same as current username.\n");
                    change_attempts++;
                    continue;
                }

                printf("Confirm Username: ");
                scanf("%s", confirm_username);

                if (strcmp(new_username, confirm_username) == 0)
                {
                    strcpy(username, new_username);
                    printf("Username Changed Successfully.\n");
                    break;
                }
                else
                {
                    printf("Username Mismatch. Please try again.\n");
                    change_attempts++;
                }
            }

            if (change_attempts == 3)
            {
                printf("Maximum attempts reached.\n");
            }
            break;
        }

        case 8:
        {
            account_details(bank_name, account_name, username, &balance);
            break;
        }
        case 9:
            printf("Thank you for using our ATM. Have a nice day!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}