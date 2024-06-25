#include <iostream>
using namespace std;
class Member
{
protected:
    int number;
    string name;
    int credit;
public:
    Member(){number = 0, name = "NULL", credit = 0;}
    Member(int n, string N, int c):number(n), name(N), credit(c){}
    ~Member(){}
    virtual void Add(int consumption)
    {
        credit += consumption;
    }
    virtual int Exchange(int consumption)
    {
        int backMoney = 0;
        backMoney = consumption / 100;
        credit -= backMoney * 100;
        return backMoney;
    }
    virtual void memberPrint()
    {
        cout << "普通会员" << number << "--" << name << "--" << credit << endl;
    }
};
class VIP : public Member
{
protected:
    int sumRate;
    int exchangeRate;
public:
    VIP()
    {
        number = 0, name = "NULL", credit = 0;
        sumRate = 0;
        exchangeRate = 0;
    }
    VIP(int n, string N, int c, int s, int e):Member(n, N, c),sumRate(s),exchangeRate(e){}
    void Add(int consumption)
    {
        credit += consumption * sumRate;
    }
    int Exchange(int consumption)
    {
        int backMoney = 0;
        backMoney = consumption / exchangeRate;
        credit -= backMoney * exchangeRate;
        return backMoney;
    }
    void memberPrint()
    {
        cout << "贵宾会员" << number << "--" << name << "--" << credit << endl;
    }
};
int main()
{
    Member *pm;
    int number, credit, sum, exchange;
    string name;
    //member
    cin >> number >> name >> credit;
    Member mm(number, name, credit);
    int a, b;
    cin >> a >> b;
    pm = &mm;
    pm->Add(a);
    pm->Exchange(b);
    pm->memberPrint();
    //VIP
    cin >> number >> name >> credit >> sum >> exchange;
    VIP vv(number, name, credit, sum, exchange);
    pm = &vv;
    cin >> a >> b;
    pm->Add(a);
    pm->Exchange(b);
    pm->memberPrint();
}