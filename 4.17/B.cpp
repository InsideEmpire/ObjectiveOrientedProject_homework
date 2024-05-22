#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Account
{
public:
    Account(string acco, string name, float balance, float deposit, float withdraw, float Rate);
    ~Account();
    void Deposit(float amount);
    void Withdraw(float amount);
    float GetBalance();
    void Show();
    static int GetCount();
    static float GetInterestRate();
    friend void Update(Account& a);

private:
    int deposit;
    int withdraw;
    static int count;
    static float InterestRate;
    string accno, _accname;
    float balance;
};

int Account::count = 0;
float Account::InterestRate = 0.0;

Account::Account(string acco, string name, float balance, float Deposit, float Withdraw, float Rate):accno(acco), _accname(name), balance(balance),deposit(Deposit),withdraw(Withdraw)
{
    InterestRate = Rate;
    count++;
}

Account::~Account()
{
    count--;
}

void Account::Deposit(float amount)
{
    balance += amount;
}

void Account::Withdraw(float amount)
{
    if (amount <= balance)
    {
        balance -= amount;
    }
    else
    {
        cout << "Insufficient balance!" << endl;
    }
}

float Account::GetBalance()
{
    return balance;
}

void Account::Show()
{
    cout << accno << " " << _accname << " ";
    Deposit(deposit);
    cout << fixed << setprecision(0) << balance << " ";
    cout << fixed << setprecision(0) << (balance + balance * InterestRate) << " ";
    Deposit(balance * InterestRate);
    Withdraw(withdraw);
    cout << fixed << setprecision(0) << balance << endl;
}

int Account::GetCount()
{
    return count;
}

float Account::GetInterestRate()
{
    return InterestRate;
}
int main()
{
    float rate;
    int n;
    cin >> rate >> n;

    Account** accounts = new Account*[n];
    for (int i = 0; i < n; ++i)
    {
        string accno, name;
        float balance, deposit, withdraw;
        cin >> accno >> name >> balance >> deposit >> withdraw;
        accounts[i] = new Account(accno, name, balance, deposit, withdraw, rate);
        accounts[i][0].Show();
    }

    float total_balance = 0;
    for (int i = 0; i < n; ++i)
    {
        total_balance += accounts[i][0].GetBalance();
    }
    cout << fixed << setprecision(0) << total_balance << endl;

    for (int i = 0; i < n; ++i)
    {
        delete accounts[i];
    }
    delete[] accounts;

    return 0;
}
