#include <stdio.h>

int main()
{
    int pin1 = 2345, pin2;
    int choice;
    float balance = 2000, amount;
    printf("====================Welcome to the ATM. Please insert your card....======================\n");
    pin2 = pin1;
    int attempts = 0;
    while (attempts < 3)
    {
        printf("Please enter your ATM PIN:");
        scanf("%d", &pin2);
        if (pin2 == pin1)
        {
            printf("PIN is correct. Please continue.\n");
            break;
        }
        else
        {
            printf("Incorrect PIN. Please try again.\n");
            attempts++;
            if (attempts == 3)
            {
                printf("You have reached the maximum number of attempts. Please remove your card. Thank you...\n");
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
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Your current balance is:%.2f\n", balance);
            break;

        case 2:
            printf("Enter the amount to deposit: ");
            scanf("%f", &amount);

            balance = balance + amount;
            printf("The amount has been deposited successfully.\n");
            break;

        case 3:
            printf("Enter the amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= balance)
            {
                balance = balance - amount;
                printf("The amount has been withdrawn successfully.\n");
            }
            else
            {
                printf("Insufficient balance. Please enter a valid amount.\n");
            }
            break;

        case 4:
            printf("Thank you for using our ATM. Have a nice day!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}