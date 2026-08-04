#ifndef TRANSACTION_H
#define TRANSACTION_H

void deposit(float *balance,
             float history[],
             int *count,
             float *last_deposit);

void withdraw(float *balance,
              float history[],
              int *count,
              float *last_withdraw);

void fast_cash(float *balance,
               float history[],
               int *count);

void mini_statement(float balance,
                    float history[],
                    int count,
                    float last_deposit,
                    float last_withdraw);
#endif