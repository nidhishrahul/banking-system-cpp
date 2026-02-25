#include "Account.h"
#include <iostream>

Account::Account(int accNo, string accName, double initialBalance, int accPin) {
    accountNumber = accNo;
    name = accName;
    balance = initialBalance;
    pin = accPin;
}

int Account::getAccountNumber() const {
    return accountNumber;
}

int Account::getPin() const {
    return pin;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount > balance) {
        return false;
    }
    balance -= amount;
    return true;
}

void Account::display() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Name: " << name << endl;
    cout << "Balance: " << balance << endl;
}
