# HT Bank System (C Project)

## Overview
HT Bank System is a console-based banking management application written in C.  
The program simulates a simplified banking environment where users can create accounts, log in securely, perform financial operations, and manage their banking activities.

The system includes custom encryption for sensitive client data and stores account information securely in binary files.

---

## Features

### Account Management
Users can:
- Register a new bank account
- Log in securely using ID and password
- View account information
- Track account activity

Each account stores information such as:
- Name
- Age
- Address
- National card number
- Phone number
- Birth date
- Password
- Current balance

---

### Banking Operations

#### Deposit
Users can deposit money into their accounts.  
The system verifies deposit limits and updates the account balance.

#### Withdraw
Users can withdraw money from their accounts while respecting withdrawal limits and available balance.

#### Lending System
Eligible users can request loans if they meet certain conditions:
- Account activity
- Deposit history
- Account status

If approved, the loan amount is added to the account balance.

---

### Secure Login
The system provides a login authentication system that includes:

- User ID verification
- Password validation
- Limited login attempts
- Access denial after multiple failed attempts

The program also stores the last login date for each user.

---

## Data Security

Sensitive user information is protected using a custom encryption system.

The program encrypts data before storing it in files.

Two types of encryption are used:

### Character Encryption
Text data such as:
- Name
- Address
- Phone number
- Password

are encrypted before storage.

### Numeric Encryption
Numerical data such as:
- Age
- Balance
- Deposits
- Withdrawals
- Account status

are encrypted using bitwise operations and key transformations.

---

## File Storage

Client data is stored in encrypted binary files.

Example file used by the system:

clients_data_encrypted_bin.bin.txt

Each user is stored as a structured record using C structs.

Transaction logs and reports are stored in a separate file.

---

## Technologies Used

- C Programming Language
- Windows Console API
- Binary File Handling
- Custom Encryption Algorithms
- Structured Data Management

---

## Program Structure

The project is divided into multiple logical components:

### Interface
Console menus allow the user to navigate through the banking system.

### Account System
Handles:
- User registration
- Login authentication
- Account data management

### Banking System
Handles:
- Deposits
- Withdrawals
- Loans
- Balance updates

### Encryption System
Encrypts and decrypts client data before file storage.

### Reporting System
Allows users to submit reports and view transaction history.

---

## Learning Objectives

This project demonstrates practical experience with:

- File handling in C
- Struct-based data storage
- Custom encryption logic
- User authentication systems
- Console interface design
- Modular programming

---

## Author

Mohamed Rayan Htalal  
Engineering Student – ENSAM

---

## Future Improvements

Possible future upgrades include:

- Graphical user interface
- Database integration
- Network-based banking system
- Stronger encryption algorithms
- Multi-user support
