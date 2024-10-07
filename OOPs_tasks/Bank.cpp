#include <iostream>
#include <string>
using namespace std;

// Abstract class for Account
class Account {
    protected:
        double balance;
    
    public:
        Account(double initialBalance = 0) : balance(initialBalance) {} // Constructor with optional initial balance
        
        // Pure virtual function for withdrawal (Abstraction)
        virtual void withdraw(double amount) = 0;
        
        // Virtual function for deposit (common for all accounts)
        virtual void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
                cout << "Deposited: " << amount << ". Current balance: " << balance << endl;
            } else {
                cout << "Invalid deposit amount." << endl;
            }
        }

        // Display balance
        virtual void displayBalance() const {
            cout << "Current balance: " << balance << endl;
        }
};

// Savings Account
class SavingsAccount : public Account {
    private:
        double interestRate;

    public:
        // Constructor
        SavingsAccount(double initialBalance, double rate) : Account(initialBalance), interestRate(rate) {}

        // Overridden withdraw function
        void withdraw(double amount) override {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrawn: " << amount << ". Current balance: " << balance << endl;
            } else {
                cout << "Insufficient balance for withdrawal." << endl;
            }
        }

        // Function to calculate interest and add to balance
        void addInterest() {
            double interest = balance * interestRate / 100;
            balance += interest;
            cout << "Interest added: " << interest << ". New balance: " << balance << endl;
        }
};

// Current Account
class CurrentAccount : public Account {
    private:
        double overdraftLimit;

    public:
        // Constructor
        CurrentAccount(double initialBalance, double overdraft) : Account(initialBalance), overdraftLimit(overdraft) {}

        // Overridden withdraw function
        void withdraw(double amount) override {
            if (amount <= balance + overdraftLimit) {
                balance -= amount;
                cout << "Withdrawn: " << amount << ". Current balance: " << balance << endl;
            } else {
                cout << "Overdraft limit exceeded. Cannot withdraw." << endl;
            }
        }
};

int main() {
    // Create a savings account with initial balance of 500 and interest rate of 5%
    SavingsAccount savings(500, 5.0);
    savings.displayBalance();
    savings.deposit(200);          // Deposit into savings account
    savings.withdraw(100);         // Withdraw from savings account
    savings.addInterest();         // Add interest to savings account

    cout << "----------------------------" << endl;

    // Create a current account with initial balance of 1000 and overdraft limit of 500
    CurrentAccount current(1000, 500);
    current.displayBalance();
    current.deposit(300);          // Deposit into current account
    current.withdraw(1500);        // Withdraw within overdraft limit
    current.withdraw(2000);        // Attempt to exceed overdraft limit

    return 0;
}
