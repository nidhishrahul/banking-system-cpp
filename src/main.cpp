#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <ctime>

#include "Account.h"

using namespace std;

// helper function to find account
Account* findAccount(vector<Account> &accounts, int accNo) {
    for(auto &acc : accounts) {
        if(acc.getAccountNumber() == accNo) {
            return &acc;
        }
    }
    return nullptr;
}

void loadAccounts(vector<Account> &accounts) {
    ifstream file("data/accounts.txt");

    // file existence check
    if(!file.is_open()) {
        cout << "No existing data file found. Starting fresh.\n";
        return;
    }

    string line;

    while(getline(file, line)) {
        stringstream ss(line);

        int accNo, pin;
        string name;
        double balance;

        // validate file format before loading
        if(!(ss >> accNo >> name >> balance >> pin)) {
            continue;
        }

        accounts.push_back(Account(accNo, name, balance, pin));
    }

    file.close();
}

void saveAccounts(vector<Account> &accounts) {
    ofstream file("data/accounts.txt");

    for(auto &acc : accounts) {
        file << acc.getAccountNumber() << " "
            << acc.getName() << " "
            << acc.getBalance() << " "
            << acc.getPin() << "\n";
    }

    file.close();
}

double getValidAmount() {
    double amount;

    while(true) {
        cin >> amount;

        // check type validation
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter numeric value: ";
            continue;
        }

        // check value validation
        if(amount <= 0) {
            cout << "Amount must be positive. Try again: ";
            continue;
        }

        break;
    }
    return amount;
}

int main() {
    vector<Account> accounts;

    // load accounts at the start
    loadAccounts(accounts);

    int choice;
    
    while(true) {
        cout << "\n===== Banking System =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Amount\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> choice;

        // check choice validation
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice.\n";
            continue;
        }
        
        switch(choice) {

            case 1: {
                int accNo, pin;
                string name;
                double balance;

                cout << "Enter Account Number: ";
                cin >> accNo;

                // p-6 use helper function
                if(findAccount(accounts, accNo) != nullptr) {
                    cout << "Account number already exists!\n";
                    break;
                }

                cout << "Enter Name: ";
                cin >> name;

                cout << "Enter Initial Balance: ";
                // validation used
                balance = getValidAmount();

                cout << "Set PIN: ";
                cin >> pin;

                accounts.push_back(Account(accNo, name, balance, pin));

                // p-6 auto-save
                saveAccounts(accounts);

                cout << "Account created successfully!\n";
                break;
            }

            case 2: {
                int accNo;

                cout << "Enter Account Number: ";
                cin >> accNo;

                // p-6 change
                Account* acc = findAccount(accounts, accNo);


                if(acc == nullptr) {
                    cout << "Account not found!\n";
                    break;
                }

                int enteredPin;
                cout << "Enter PIN: ";
                cin >> enteredPin;

                // pin authentication
                if(enteredPin != acc->getPin()) {
                    cout << "Incorrect PIN!\n";
                    break;
                }

                cout << "Enter amount to deposit: ";
                double amount = getValidAmount();

                acc->deposit(amount);

                // auto-save
                saveAccounts(accounts);

                cout << "Deposit Successfully!\n";
                break;
            }

            case 3: {
                int accNo;
                
                cout << "Enter Account Number: ";
                cin >> accNo;

                Account* acc = findAccount(accounts, accNo);

                if(acc == nullptr) {
                cout << "Account not found.\n";
                break;
            }

                int enteredPin;
                cout << "Enter PIN: ";
                cin >> enteredPin;

                if(enteredPin != acc->getPin()) {
                    cout << "Incorrect PIN!\n";
                    break;  
                }

                cout << "Enter amount to withdraw: ";
                double amount = getValidAmount();

                if(acc->withdraw(amount)) {
                    saveAccounts(accounts);  // PHASE 6 CHANGE (auto-save)
                    cout << "Withdrawal Successfully!\n";
                    } else {
                    cout << "Insufficient Balance.\n";
                }

                break;
            }

            case 4: {
                int accNo;
                cout << "Enter Account Number: ";
                cin >> accNo;

                Account* acc = findAccount(accounts, accNo);  // PHASE 6 CHANGE

                if(acc == nullptr) {
                    cout << "Account not found.\n";
                    break;
                }

                int enteredPin;
                cout << "Enter PIN: ";
                cin >> enteredPin;

                if(enteredPin != acc->getPin()) {
                    cout << "Incorrect PIN!\n";
                    break;
                }

                cout << "Account Holder: " << acc->getName() << endl;
                cout << "Available Balance: " << acc->getBalance() << endl;

                break;
            }

            case 5: {
                saveAccounts(accounts);

                cout << "Data saved successfully. Exiting Program...\n";
                return 0;
            }

            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}