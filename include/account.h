#ifndef ACCOUNT_H
#define ACCOUNT_H
struct account
{
    char account_name[30];
    char bank_name[30];
    char username[20];
    float balance;
    int pin;
};

void account_details(struct account *user);

#endif