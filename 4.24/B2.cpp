#include <iostream>
#include <cstring>
using namespace std;

class CAccount {
protected:
    long account;
    char name[10];
    float balance;

public:
    CAccount(long acc, const char* n, float b) : account(acc), balance(b) {
        strcpy(name, n);
    }

    void deposit(float amount) {
        balance += amount;
        cout << "saving ok!" << endl;
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "sorry! over balance!" << endl;
        } else {
            balance -= amount;
            cout << "withdraw ok!" << endl;
        }
    }

    void check() const {
        cout << "balance is " << balance << endl;
    }
};

class CCreditcard : public CAccount {
private:
    float limit;

public:
    CCreditcard(long acc, const char* n, float b, float l) : CAccount(acc, n, b), limit(l) {}

    void withdraw(float amount) {
        if (amount > balance + limit) {
            cout << "sorry! over limit!" << endl;
        } else {
            balance -= amount;
            cout << "withdraw ok!" << endl;
        }
    }
};

int main() {
    // 存折类测试
    long acc1;
    char name1[10];
    float balance1;
    float deposit1, withdraw1;

    cin >> acc1 >> name1 >> balance1 >> deposit1 >> withdraw1;

    CAccount account1(acc1, name1, balance1);
    account1.check();
    account1.deposit(deposit1);
    account1.check();
    account1.withdraw(withdraw1);
    account1.check();

    // 信用卡类测试
    long acc2;
    char name2[10];
    float balance2, limit2;
    float deposit2, withdraw2;

    cin >> acc2 >> name2 >> balance2 >> limit2 >> deposit2 >> withdraw2;

    CCreditcard creditcard1(acc2, name2, balance2, limit2);
    creditcard1.check();
    creditcard1.deposit(deposit2);
    creditcard1.check();
    creditcard1.withdraw(withdraw2);
    creditcard1.check();

    return 0;
}
