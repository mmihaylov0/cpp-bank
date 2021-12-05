#include "Bank.h"

int main() {
    Bank bank;
    for (int i = 0; i < 2; ++i) bank.createAccount();
    bank.saveAccounts();
    bank.printSameNameAccounts();
    std::string id = "A00001";
    bank.makeTransaction(&id, 1000);
    bank.makeTransaction(&id, -100);
    id = "A00002";
    bank.makeTransaction(&id, 1000);
    bank.makeTransaction(&id, -1000);
    bank.printBalance();
    bank.saveZeroBalance();
    return 0;
}
