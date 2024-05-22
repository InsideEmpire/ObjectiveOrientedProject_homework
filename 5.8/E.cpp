#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>

using namespace std;

class CPeople {
protected:
    char id[20];
    char name[10];
public:
    CPeople() {}
    CPeople(const char* _id, const char* _name) {
        strcpy(id, _id);
        strcpy(name, _name);
    }
};

class CInternetUser : virtual public CPeople {
private:
    char password[20];
public:
    CInternetUser() {}
    void registerUser(const char* _id, const char* _name, const char* _password) {
        strcpy(id, _id);
        strcpy(name, _name);
        strcpy(password, _password);
    }
    bool login(const char* _id, const char* _password) {
        return (strcmp(id, _id) == 0 && strcmp(password, _password) == 0);
    }
};

class CBankCustomer : virtual public CPeople {
protected:
    double balance;
public:
    CBankCustomer() : balance(0) {}
    void openAccount(const char* _id, const char* _name) {
        strcpy(id, _id);
        strcpy(name, _name);
    }
    bool deposit(double amount) {
        balance += amount;
        return true;
    }
    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }
    double getBalance() const {
        return balance;
    }
};

class CInternetBankCustomer : public CInternetUser, public CBankCustomer {
private:
//余额, 前一日余额, 当日收益，今日万元收益和上一日万元收益等5个数据成员
    double todayBalance = 0;
    double yesterdayBalance;
    double todayEarning;
    double todayPerMillionEarning;
    double yesterdayPerMillionEarning;
public:
    CInternetBankCustomer() : yesterdayBalance(0), todayEarning(0), todayPerMillionEarning(0) {}

    void setInterest(double interest) {
        yesterdayPerMillionEarning = todayPerMillionEarning;
        todayPerMillionEarning = interest;
    }

    void calculateProfit() {
        //yesterdayBalance = todayBalance;
        todayEarning = (yesterdayBalance / 10000.0) * yesterdayPerMillionEarning ;
        // yesterdayBalance = balance;
        todayBalance += todayEarning;
    }

    bool BtI(double amount)
    {
        if (balance < amount)
        {
            return false;
        }
        else
        {
            balance -= amount;
            todayBalance += amount;
            return true;
        }
    }

    bool ItB(double amount)
    {
        if (todayBalance < amount)
        {
            return false;
        }
        else
        {
            balance += amount;
            todayBalance -= amount;
            return true;
        }
    }

    void print() {
        yesterdayBalance = todayBalance;
        cout << "Name: " << name << " ID: " << id << endl;
        cout << "Bank balance: " << balance << endl;
        cout << "Internet bank balance: " << todayBalance << endl;
    }
};

int main() {
    int t, no_of_days, i;
    string i_xm, i_id, i_mm, b_xm, b_id, ib_id, ib_mm;
    double money, interest;
    char op_code;

    cin >> t;

    while (t--) {
        cin >> i_xm >> i_id >> i_mm;
        cin >> b_xm >> b_id;
        cin >> ib_id >> ib_mm;

        CInternetBankCustomer ib_user;
        ib_user.registerUser(i_id.c_str(), i_xm.c_str(), i_mm.c_str());
        ib_user.openAccount(b_id.c_str(), b_xm.c_str());

        if (!ib_user.login(ib_id.c_str(), ib_mm.c_str())) {
            cout << "Password or ID incorrect" << endl;
            continue;
        }

        cin >> no_of_days;

        for (i = 0; i < no_of_days; i++) {
            cin >> op_code >> money >> interest;
            switch (op_code) {
                case 'S':
                case 's':
                    if (!ib_user.BtI(money)) {//?
                        cout << "S Bank balance not enough" << endl;
                        continue;
                    }
                    break;
                case 'T':
                case 't':
                    if (!ib_user.ItB(money)) {//?
                        cout << "T Internet bank balance not enough" << endl;
                        continue;
                    }
                    break;
                case 'D':
                case 'd':
                    ib_user.deposit(money);
                    break;
                case 'W':
                case 'w':
                    if (!ib_user.withdraw(money)) {
                        cout << "W Bank balance not enough" << endl;
                        continue;
                    }
                    break;
                default:
                    cout << "Illegal input" << endl;
                    continue;
            }
            ib_user.setInterest(interest);
            ib_user.calculateProfit();
            ib_user.print();
            cout << endl;

        }
    }

    return 0;
}
