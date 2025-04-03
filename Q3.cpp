#include <iostream>
using namespace std;

class Currency {
protected:
    double amount, exchangeRate;
    string currencyCode, currencySymbol;
public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() = 0;
    virtual void displayCurrency() = 0;
    double convertToTarget(double targetRate) { return convertToBase() * targetRate; }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    double convertToBase() override { return amount; }
    void displayCurrency() override { cout << currencySymbol << amount << " " << currencyCode << endl; }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

    double convertToBase() override { return amount * exchangeRate; }
    void displayCurrency() override { cout << currencySymbol << amount << " " << currencyCode << endl; }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "?", 0.012) {}

    double convertToBase() override { return amount * exchangeRate; }
    void displayCurrency() override { cout << currencySymbol << amount << " " << currencyCode << endl; }
};

int main() {
    Dollar d(100);
    Euro e(100);
    Rupee r(10000);

    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();

    cout << "EUR to USD: " << e.convertToTarget(1 / 1.1) << endl;
    cout << "INR to USD: " << r.convertToTarget(1 / 0.012) << endl;

    return 0;
}

