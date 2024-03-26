#include <iostream>
using namespace std;

struct AccountHolder {
    string cnic;
    string phoneNumber;
    string address;
    string profession;
};

struct BankAccount {
    string accountNumber;
    AccountHolder accountHolder;
    double limit;
    double balance;
};

const int MAX_ACCOUNTS = 100;
BankAccount accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        cout << "Maximum limit reached. Cannot create more accounts." << endl;
        return;
    }

    BankAccount newAccount;
    AccountHolder newAccountHolder;

    cout << "Enter the account number: ";
    cin >> newAccount.accountNumber;

    cout << "Enter CNIC number: ";
    cin >> newAccountHolder.cnic;

    cout << "Enter phone number: ";
    cin >> newAccountHolder.phoneNumber;

    cout << "Enter address: ";
    cin.ignore();
    getline(cin, newAccountHolder.address);

    cout << "Enter profession: ";
    getline(cin, newAccountHolder.profession);

    cout << "Enter the initial balance: ";
    cin >> newAccount.balance;

    cout << "Enter the account withdrawal limit: ";
    cin >> newAccount.limit;

    newAccount.accountHolder = newAccountHolder;

    accounts[numAccounts] = newAccount;
    numAccounts++;

    cout << "Account created successfully." << endl;
}

void displayAccounts() {
    if (numAccounts == 0) {
        cout << "No accounts found." << endl;
        return;
    }

    cout << "All Accounts:" << endl;
    for (int i = 0; i < numAccounts; i++) {
        cout << "Account Number: " << accounts[i].accountNumber << endl;
        cout << "Account Holder's CNIC: " << accounts[i].accountHolder.cnic << endl;
        cout << "Account Holder's Phone Number: " << accounts[i].accountHolder.phoneNumber << endl;
        cout << "Account Holder's Address: " << accounts[i].accountHolder.address << endl;
        cout << "Account Holder's Profession: " << accounts[i].accountHolder.profession << endl;
        cout << "Balance: " << accounts[i].balance << endl;
        cout << "Account Limit: " << accounts[i].limit << endl;
        cout << endl;
    }
}

void deposit(string accountNumber, double amount) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (amount <= accounts[i].limit) {
                accounts[i].balance += amount;
                cout << "Amount deposited successfully." << endl;
            } else {
                cout << "Deposit amount exceeds the limit of the account." << endl;
            }
            return;
        }
    }

    cout << "Account not found." << endl;
}

void withdraw(string accountNumber, double amount) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance - amount >= 0 && amount <= accounts[i].limit) {
                accounts[i].balance -= amount;
                cout << "Amount withdrawn successfully." << endl;
            } else if (amount > accounts[i].limit) {
                cout << "Withdrawal amount exceeds the limit of the account." << endl;
            } else {
                cout << "Insufficient balance." << endl;
            }
            return;
        }
    }

    cout << "Account not found." << endl;
}

int main() {
    BankAccount sampleAccount1;
    sampleAccount1.accountNumber = "112233";
    sampleAccount1.accountHolder.cnic = "123456789";
    sampleAccount1.accountHolder.phoneNumber = "987654321";
    sampleAccount1.accountHolder.address = "123 Main Street, City";
    sampleAccount1.accountHolder.profession = "Engineer";
    sampleAccount1.balance = 1000.0;
    sampleAccount1.limit = 5000.0;

    BankAccount sampleAccount2;
    sampleAccount2.accountNumber = "12345";
    sampleAccount2.accountHolder.cnic = "987654321";
    sampleAccount2.accountHolder.phoneNumber = "123456789";
    sampleAccount2.accountHolder.address = "456 Elm Street, Town";
    sampleAccount2.accountHolder.profession = "Teacher";
    sampleAccount2.balance = 5000.0;
    sampleAccount2.limit = 10000.0;

    accounts[numAccounts] = sampleAccount1;
    numAccounts++;
    accounts[numAccounts] = sampleAccount2;
    numAccounts++;

    int choice;
    do {
        cout << "Bank Account Management System" << endl;
        cout << "1. Create an account" << endl;
        cout << "2. Display all accounts" << endl;
        cout << "3. Deposit money" << endl;
        cout << "4. Withdraw money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                {
                    string accountNumber;
                    double amount;
                    cout << "Enter the account number: ";
                    cin >> accountNumber;
                    cout << "Enter the amount to deposit: ";
                    cin >> amount;
                    deposit(accountNumber, amount);
                }
                break;
            case 4:
                {
                    string accountNumber;
                    double amount;
                    cout << "Enter the account number: ";
                    cin >> accountNumber;
                    cout << "Enter the amount to withdraw: ";
                    cin >> amount;
                    withdraw(accountNumber, amount);
                }
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
