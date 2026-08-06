#include <stdio.h>
#include "file.h"

void save_balance(float balance)
{
    FILE *fp;

    fp = fopen("account.txt", "w");

    if (fp == NULL)
    {
        printf("File opening failed.\n");
        return;
    }

    fprintf(fp, "%.2f", balance);

    fclose(fp);
}

float load_balance(void)
{
    FILE *fp;
    float balance;

    fp = fopen("account.txt", "r");

    if (fp == NULL)
    {
        return 2000;
    }

    fscanf(fp, "%f", &balance);

    fclose(fp);

    return balance;
}


    void save_history(char operation[], float amount)
{
    FILE *fp;

    fp = fopen("history.txt", "a");

    if (fp == NULL)
    {
        printf("File opening failed.\n");
        return;
    }

    fprintf(fp, "%s : %.2f\n", operation, amount);

    fclose(fp);
}

void display_history(void)
{
    FILE *fp;
    char ch;

    fp = fopen("history.txt", "r");

    if (fp == NULL)
    {
        printf("No transaction history found.\n");
        return;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }

    fclose(fp);
}


