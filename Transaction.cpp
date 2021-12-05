#include <ostream>
#include "Transaction.h"

using namespace std;

Transaction::Transaction(double amount, Transaction* t)
        : amount(amount) {
    nextTransaction = t;
}

double Transaction::getAmount() const {
    return amount;
}

Transaction *Transaction::getNextTransaction() const {
    return nextTransaction;
}

void Transaction::addTransaction(Transaction *t) {
    if (nextTransaction == nullptr) nextTransaction = t;
    else nextTransaction->addTransaction(t);
}

ostream &Transaction::operator<<(ostream &os) {
    char op = '+';
    if (amount < 0) op = '\0';

    os << op << amount << " BGN" << endl;
    if (nextTransaction) os << nextTransaction;
    return os;
}
