#include <ostream>
#include <utility>
#include "Account.h"

using namespace std;

Account::Account(string _id, char *_name, Account *next)
        : id(move(_id)), balance(0), transactions(nullptr) {
    name = _name;
    nextAccount = next;
}

Account *Account::getNextAccount() { return nextAccount; }


const string &Account::getId() const {
    return id;
}

double Account::getBalance() const {
    return balance;
}

Transaction *Account::getTransactions() const {
    return transactions;
}

ostream &Account::operator<<(ostream &os) {
    os << id << ' ' << getName() << ' ' << balance << " BGN" << endl;
    return os;
}

void Account::makeTransaction(double amount) {
    balance += amount;
    auto* transaction = new Transaction(amount, transactions);
    transactions = transaction;
}

char *Account::getName() const {
    return name;
}
