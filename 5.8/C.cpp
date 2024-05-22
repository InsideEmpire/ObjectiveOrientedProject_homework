#include <iostream>
using namespace std;
class TravelCard
{
protected:
    int TID;
    int Tcredit = 0;
public:
    TravelCard(int id, int credit):TID(id), Tcredit(credit){}
};
class CreditCard
{
protected:
    int CID;
    string Cname;
    int Climit;
    double Cvalue = 0;
    int Ccredit = 0;
public:
    CreditCard(int id, string name, int limit, double value, int credit):CID(id), Cname(name), Climit(limit), Cvalue(value), Ccredit(credit){}
    void creditConsume(double m)
    {
        if (m + Cvalue <= Climit)
        {
            Cvalue += m;
            Ccredit += (int)m;
        }
        
    }
    void creditReturn(double m)
    {
        Cvalue -= m;
        Ccredit -= (int)m;
    }
};
class TravelCreditCard :public TravelCard,public CreditCard
{
public:
    TravelCreditCard(int Tid, int Tcredit, int Cid, string Cname, int Climit, double Cvalue, int Ccredit):TravelCard(Tid, Tcredit), CreditCard(Cid, Cname, Climit, Cvalue, Ccredit){}
    void travelConsume(double m)
    {
        if (m + Cvalue <= Climit)
        {
            Cvalue += m;
            Ccredit += (int)m;
            Tcredit += (int)m;
        }
    }
    void transfer(int m)
    {
        Ccredit -= m;
        Tcredit += m * 0.5;
    }
    void print()
    {
        cout << TID << ' ' << Tcredit << endl;
        cout << CID << ' ' << Cname << ' ' << Cvalue << ' ' << Ccredit << endl;
    }
};
int main()
{
    int TID, CID, limit;
    string name;
    cin >> TID >> CID >> name >> limit;
    TravelCreditCard VIP(TID, 0, CID, name, limit, 0, 0);
    int t;
    cin >> t;
    while (t--)
    {
        char type;
        cin >> type;
        double m;
        cin >> m;
        if (type == 'o')
        {
            VIP.travelConsume(m);
        }
        else if (type == 'c')
        {
            VIP.creditConsume(m);
        }
        else if (type == 'q')
        {
            VIP.creditReturn(m);
        }
        else
        {
            VIP.transfer(m);
        }
    }
    VIP.print();
}