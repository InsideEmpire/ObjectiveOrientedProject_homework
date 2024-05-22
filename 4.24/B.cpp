#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class CAccount
{


protected:
    long account;
    char name[10];
    float blance;
public:
    CAccount(int a, char *n, float b):account(a), blance(b)
    {
        strcpy(name, n);
    }
    void deposit()
    {
        float money;
        cin >> money;
        blance += money;
        cout << "saving ok!" << endl;
        cout << "balance is " << blance << endl;
    }
    void withdraw()
    {
        float money;
        cin >> money;
        if (blance >= money)
        {
            blance -= money;
            cout << "withdraw ok!" << endl;
            cout << "balance is " << blance << endl;
        }
        else
        {
            cout << "sorry! over balance!" << endl;
            cout << "balance is " << blance << endl;
        }
    }
    void check()
    {
        cout << "balance is " << blance << endl;
    }
};
class CCreditcard : public CAccount
{
protected:
    float limit;
public:
    CCreditcard(int a, char *n, float b, float l):CAccount(a, n, b), limit(l){}
    void withdraw()
    {
        float money;
        cin >> money;
        if (blance + limit >= money)
        {
            blance -= money;
            cout << "withdraw ok!" << endl;
            cout << "balance is " << blance << endl;
        }
        else
        {
            cout << "sorry! over limit!" << endl;
            cout << "balance is " << blance << endl;
        }
    }
};
int main()
{
    int account1;
    char name1[5];
    float blance1;
    cin >> account1 >> name1 >> blance1;
    CAccount tem1(account1, name1, blance1);
    tem1.check();tem1.deposit();tem1.withdraw();
    int account2;
    char name2[5];
    float blance2;
    float limit;
    cin >> account2 >> name2 >> blance2 >> limit;
    CCreditcard tem2(account2, name2, blance2, limit);
    tem2.check();tem2.deposit();tem2.withdraw();
    return 0;
}
