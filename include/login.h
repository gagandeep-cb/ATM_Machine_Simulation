#ifndef LOGIN_H
#define LOGIN_H

int verify_username(char username[]);
int verify_pin(int pin);
void change_pin(int *pin);
void change_username(char username[]);
#endif