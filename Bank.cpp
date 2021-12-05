#include <fstream>
#include <map>
#include <cstring>
#include <algorithm>
#include "Bank.h"

using namespace std;

Bank::Bank() : accounts(nullptr) {
}

void Bank::createAccount() {
    char *name = new char[255];
    cout << "Account name:";
    cin >> name;
    auto *account = new Account(generateId(), name, accounts);
    cout << "Created account for " << account->getName() << " with id " << account->getId() << endl;
    accounts = account;
}

string Bank::generateId() {
    if (++currentNum == 100000) {
        currentNum = 1;
        currentLetter++;
    }
    string output;
    output += currentLetter;
    output += getLeadingZeros();
    output += to_string(currentNum);
    return output;
}

string Bank::getLeadingZeros() const {
    if (currentNum < 10) return "0000";
    if (currentNum < 100) return "000";
    if (currentNum < 1000) return "00";
    if (currentNum < 10000) return "0";
    return "";
}

void Bank::makeTransaction(string *id, double amount) {
    Account *account = getAccountById(id);
    account->makeTransaction(amount);
}

Account *Bank::getAccountById(string *id) {
    Account *a = accounts;
    while (a != nullptr) {
        if (*id == a->getId()) return a;

        a = a->getNextAccount();
    }
    return nullptr;
}

void Bank::saveAccounts() {
    ofstream file;
    file.open("accounts.txt", ios::out | ios::trunc);
    if (!file.is_open()) return;
    Account *a = accounts;
    while (a != nullptr) {
        a->operator<<(file);
        a = a->getNextAccount();
    }
    file.close();
}

struct equals {
    bool operator()(char const *a, char const *b) const {
        return strcmp(a, b) != 0;
    }
};

int compareInterval(const void *a, const void *b) {
    return strcmp(*(const char **) a, *(const char **) b);
}

void Bank::printSameNameAccounts() {
    map<char *, int, equals> names;
    Account *a = accounts;
    while (a != nullptr) {
        auto it = names.find(a->getName());

        // key already present on the map
        if (it != names.end()) {
            it->second++;    // increment map's value for key `c`
        } else names.insert({a->getName(), 0});
        a = a->getNextAccount();
    }

    int count = 0;
    for (auto &i: names)
        if (i.second > 0) count++;

    char *orderedNames[count];
    int pos = 0;
    for (auto &i: names)
        if (i.second > 0) orderedNames[pos++] = i.first;
    qsort(orderedNames, count, sizeof(char *), compareInterval);
    cout << "Clients with more than 1 account:" << endl;
    for (auto i: orderedNames)
        cout << i << endl;
}

void Bank::printBalance() {
    Account *a = accounts;
    cout << "Accounts' balance:" << endl;
    while (a != nullptr) {
        cout << a->getName() << " " << a->getBalance() << " BGN" << endl;
        a = a->getNextAccount();
    }
}

void Bank::saveZeroBalance() {
    ofstream file;
    file.open("zero_balance.txt", ios::out | ios::trunc);
    if (!file.is_open()) return;
    Account *a = accounts;
    while (a != nullptr) {
        // save to the file only the accounts where the transactions' sum is 0
        if (a->getBalance() == 0 && a->getTransactions() != nullptr)
            a->operator<<(file);
        a = a->getNextAccount();
    }
    file.close();
}