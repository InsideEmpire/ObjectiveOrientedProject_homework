#include <iostream>
#include <cstring>

using namespace std;

class CAccount {
private:
    long account;
    char name[10];
    float balance;

public:
    CAccount() {}

    void input(long acc, const char* n, float bal) {
        account = acc;
        strncpy(name, n, 10);
        balance = bal;
    }

    void deposit(float amount) {
        balance += amount;
        cout << "saving ok!" << endl;
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "withdraw ok!" << endl;
        } else {
            cout << "sorry! over limit!" << endl;
        }
    }

    void check() {
        cout << name << "'s balance is " << balance << endl;
    }
};

int main() {
    CAccount account1, account2;
    long acc1, acc2;
    char name1[10], name2[10];
    float balance1, balance2, deposit1, deposit2, withdraw1, withdraw2;

    cin >> acc1 >> name1 >> balance1 >> deposit1 >> withdraw1;
    account1.input(acc1, name1, balance1);

    account1.check();
    account1.deposit(deposit1);
    account1.check();
    account1.withdraw(withdraw1);
    account1.check();

    cin >> acc2 >> name2 >> balance2 >> deposit2 >> withdraw2;
    account2.input(acc2, name2, balance2);

    account2.check();
    account2.deposit(deposit2);
    account2.check();
    account2.withdraw(withdraw2);
    account2.check();

    return 0;
}