#ifndef FILE_H
#define FILE_H

void save_balance(float balance);
float load_balance(void);

void save_history(char operation[], float amount);
void display_history(void);

#endif