# Banking System (C++ Console Application)

A console-based banking system built using C++ to demonstrate
Object-Oriented Programming, modular design, and persistent storage.

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

---

## Features Implemented

- Create Account
- Deposit Money
- Withdraw Money
- Display Account Details
- Multiple accounts support
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
g++ *.cpp -o bank
.\bank.exe

---

## Upcoming Phases

- PIN authentication before transactions
- Transaction history logging
- Duplicate account prevention
- Input validation improvements
- Code refactoring & modular improvements