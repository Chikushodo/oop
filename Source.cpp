#include <iostream>
#include <string>

using namespace std;

class BankAccount {
public:
    BankAccount(){
        accountNumber_ = "none";
        balance_ = 0;
    }

    BankAccount(const string& accountNumber, double initialBalance)
        : accountNumber_(accountNumber), balance_(initialBalance) {
        cout << "Вызван основной конструктор" << endl;
    }

    BankAccount(const BankAccount& other)
        : accountNumber_(other.accountNumber_ + "_copy"),  
        balance_(other.balance_ + 1.0) {               

        cout << "Вызван конструктор копирования" << endl;
        cout << "  Копирование номера счета: " << other.accountNumber_ << " -> " << accountNumber_ << endl;
        cout << "  Копирование баланса: " << other.balance_ << " -> " << balance_ << endl;
    }

    string getAccountNumber() const {
        return accountNumber_;
    }

    double getBalance() const {
        return balance_;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance_ += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance_) {
            balance_ -= amount;
        }
    }

    void transferTo(BankAccount& target, double amount) {
        if (amount > 0 && amount <= balance_) {
            balance_ -= amount;
            target.deposit(amount);
        }
    }

private:
    string accountNumber_;
    double balance_;
};

int main() {
    BankAccount account1("12345", 100.0);
    cout << "Счет 1: Номер = " << account1.getAccountNumber() << ", Баланс = " << account1.getBalance() << endl;

    BankAccount account2 = account1; 
    cout << "Счет 2: Номер = " << account2.getAccountNumber() << ", Баланс = " << account2.getBalance() << endl;
}