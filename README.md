# Banking System (C++ Console Application)

A console-based banking system built using C++ to demonstrate
Object-Oriented Programming, modular design, persistent storage,
and defensive programming principles.

---

## Completed Phases

### Phase 1 – Project Setup
- Structured project folders
- Separated header and implementation files

### Phase 2 – Account Class
- Constructor implementation
- Deposit functionality
- Withdraw functionality
- Encapsulation using private members

### Phase 3 – Menu Driven System
- Dynamic account creation
- Multiple accounts using STL vector
- Deposit & withdraw via search
- Interactive console menu

### Phase 4 – File Persistence (Persistent Storage)
- Accounts stored in `data/accounts.txt`
- Auto-load accounts on program start
- Auto-save accounts on exit
- File handling using `ifstream`, `ofstream`
- Data parsing using `stringstream`

### Phase 5 – Input Validation & Security Improvements
- Numeric input validation using `cin.fail()`
- Buffer clearing using `cin.clear()` and `cin.ignore()`
- Prevention of negative deposits and withdrawals
- PIN authentication before deposit, withdrawal, and display
- Duplicate account number prevention
- Menu input validation
- Defensive programming implementation

---

## Features Implemented

- Create Account
- Deposit Money (with PIN verification)
- Withdraw Money (with PIN verification)
- Display Account Details (with PIN verification)
- Multiple accounts support
- Duplicate account prevention
- Input validation for numeric fields
- Data persistence between program runs

---

## Concepts Used

- OOP (Encapsulation, Constructors)
- Header & Source separation
- STL (`vector`)
- Loop-based menu system
- `switch-case`
- Linear search logic
- File Handling (`ifstream`, `ofstream`)
- String parsing (`stringstream`)
- Input stream error handling
- Defensive programming

---

## Project Structure

Banking-System/
│
├── src/
│   ├── main.cpp
│   ├── Account.h
│   └── Account.cpp
│
├── data/
│   └── accounts.txt
│
├── run.bat
└── README.md

---

## How to Run

### Using run.bat
.\run.bat

### Manual Compilation
cd src
g++ -I../include *.cpp -o bank
.\bank.exe

---

## Current System Status

✔ Stable  
✔ User-error resistant  
✔ Persistent storage enabled  
✔ PIN-protected transactions  

---

## Upcoming Phases

- Transaction history logging
- Automatic save after each transaction
- Refactoring repeated logic into helper functions
- Improved file write safety (temporary file strategy)
- Admin/User role separation