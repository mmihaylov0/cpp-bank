#include <ostream>

class Transaction {
private:
    double amount;
    Transaction *nextTransaction;
public:
    explicit Transaction(double amount, Transaction *nextTransaction);

    double getAmount() const;

    Transaction *getNextTransaction() const;

    void addTransaction(Transaction *t);

    std::ostream &operator<<(std::ostream &os);
};