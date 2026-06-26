#include <stdio.h>

int main()
{
    int pin1 = 2345, pin2;
    int choice;
    float balance = 2000, amount;
    float history[10];
    int count = 0;
    float last_deposit = 0, last_withdraw = 0;
    int attempts = 0;
    printf("========== Welcome to the ATM. Please insert your card... ==========\n");

    while (attempts < 3)
    {
        printf("Please enter your ATM PIN: ");
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
        printf("7. Exit\n");

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
            printf("Thank you for using our ATM. Have a nice day!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}