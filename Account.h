#include <string>
#include "Transaction.h"

class Account {
private:
    std::string id;
    char *name;
    double balance;
    Account *nextAccount;
    Transaction *transactions;
public:
    Account(std::string _id, char *_name, Account *next);

    ~Account() = default;

    Account *getNextAccount();

    const std::string &getId() const;

    char *getName() const;

    double getBalance() const;

    Transaction *getTransactions() const;

    void makeTransaction(double amount);

    std::ostream &operator<<(std::ostream &os);
};