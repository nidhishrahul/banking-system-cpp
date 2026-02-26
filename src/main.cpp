#include <iostream>
#include <vector>
#include "Account.h"

using namespace std;

int main() {
    vector<Account> accounts;
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
        
        switch(choice) {

            case 1: {
                int accNo, pin;
                string name;
                double balance;

                cout << "Enter Account Number: ";
                cin >> accNo;

                cout << "Enter Name: ";
                cin >> name;

                cout << "Enter Initial Balance: ";
                cin >> balance;

                cout << "Set PIN: ";
                cin >> pin;

                accounts.push_back(Account(accNo, name, balance, pin));
                cout << "Account created successfully!\n";
                break;
            }

            case 2: {
                int accNo;
                double amount;

                cout << "Enter Account Number: ";
                cin >> accNo;

                bool found = false;

                for(auto &acc : accounts) {
                    if(acc.getAccountNumber() == accNo) {
                        
                        cout << "Enter amount to deposit: ";
                        cin >> amount;

                        acc.deposit(amount);
                        cout << "Deposit successful!\n";
                        found = true;
                        break;
                    }
                }

                if(!found) {
                    cout << "Account not found!\n";
                }
                break;
            }

            case 3: {
                int accNo;
                double amount;

                cout << "Enter Account Number: ";
                cin >> accNo;

                bool found = false;

                for(auto &acc : accounts) {
                    if(acc.getAccountNumber() == accNo) {
                        
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;

                        if(acc.withdraw(amount)) {
                            cout << "Withdrawal Successfully!\n";
                        } else {
                            cout << "Insufficient Balance.\n";
                        }
                        found = true;
                        break;
                    }
                }

                if(!found) {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 4: {
                int accNo;
                
                cout << "Enter Account Number: ";
                cin >> accNo;

                bool found = false;

                for(auto &acc : accounts) {

                    if(acc.getAccountNumber() == accNo) {
                        acc.display();
                        found = true;
                        break;
                    }
                }

                if(!found) {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 5: {
                cout << "Exiting Program...\n";
                return 0;
            }

            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}