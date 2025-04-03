#include <iostream>
using namespace std;

class Account {
protected:
    string accountNumber, accountHolderName, accountType;
    double balance;
public:
    Account(string num, string name, string type, double bal) 
        : accountNumber(num), accountHolderName(name), accountType(type), balance(bal) {}

    virtual void deposit(double amount) { balance += amount; }
    virtual void withdraw(double amount) { if (balance >= amount) balance -= amount; }
    virtual double calculateInterest() = 0;
    virtual void printStatement() = 0;
    virtual void getAccountInfo() { cout << accountNumber << " " << accountHolderName << " " << accountType << " " << balance << endl; }
};

class SavingsAccount : public Account {
    double interestRate, minimumBalance;
public:
    SavingsAccount(string num, string name, double bal, double rate, double minBal)
        : Account(num, name, "Savings", bal), interestRate(rate), minimumBalance(minBal) {}

    double calculateInterest() override { return balance * interestRate; }
    void printStatement() override { cout << "Saving Account Statement" << endl; }
    void withdraw(double amount) override { if (balance - amount >= minimumBalance) balance -= amount; }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(string num, string name, double bal)
        : Account(num, name, "Checking", bal) {}

    double calculateInterest() override { return 0; }
    void printStatement() override { cout << "Checking Account Statement" << endl; }
};

class FixedDepositAccount : public Account {
    double fixedInterestRate, maturityDate;
public:
    FixedDepositAccount(string num, string name, double bal, double rate, double maturity)
        : Account(num, name, "Fixed Deposit", bal), fixedInterestRate(rate), maturityDate(maturity) {}

    double calculateInterest() override { return balance * fixedInterestRate; }
    void printStatement() override { cout << "Fixed Deposit Account Statement" << endl; }
};

int main() {
    SavingsAccount sa("001", "Umer", 1000, 0.05, 500);
    CheckingAccount ca("002", "hana", 1500);
    FixedDepositAccount fda("003", "Jerry", 5000, 0.07, 3);

    sa.deposit(900);
    sa.withdraw(1200);
    sa.printStatement();
    sa.getAccountInfo();

    ca.deposit(10000);
    ca.withdraw(500);
    ca.printStatement();
    ca.getAccountInfo();

    fda.deposit(2000);
    fda.printStatement();
    fda.getAccountInfo();

    return 0;
}

