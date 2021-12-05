#include "Account.h"
#include <iostream>
#include <string>

class Bank {
private:
    int currentNum = 0;
    char currentLetter = 'A';
    Account *accounts;

    std::string generateId();

    std::string getLeadingZeros() const;

public:
    Bank();

    ~Bank() = default;

    void createAccount();

    void makeTransaction(std::string *id, double amount);

    Account *getAccountById(std::string *id);

    void saveAccounts();

    void printSameNameAccounts();

    void printBalance();

    void saveZeroBalance();
};