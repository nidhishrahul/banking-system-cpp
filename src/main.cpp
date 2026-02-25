#include <iostream>
#include "Account.h"

using namespace std;

int main() {
    Account acc1(1, "Nidhish", 5000, 1234);

    acc1.deposit(1000);
    acc1.withdraw(250);

    acc1.display();

    return 0;
}