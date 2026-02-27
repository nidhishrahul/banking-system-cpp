#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<string>
using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    double balance;
    int pin;

public:
    Account(int accNo, string accName, double initialBalance, int accPin);

    int getAccountNumber() const;
    int getPin() const;
    double getBalance() const;
    string getName() const;

    bool deposit(double amount);
    bool withdraw(double amount);

    void display() const;
};

#endif