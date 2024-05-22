#include <iostream>
#include <string.h>
using namespace std;
class CTelNumber
{
private:
    char *phone;

public:
    CTelNumber(char *p)
    {
        phone = new char[100];
        strcpy(phone, p);
    }
    CTelNumber(const CTelNumber &c)
    {
        phone = new char[100];
        for (int i = 7; i >= 0; i--)
        {
            phone[i + 1] = c.phone[i];
        }
        if (c.phone[0] >= '2' && c.phone[0] <= '4')
        {
            phone[0] = '8';
        }
        else
        {
            phone[0] = '2';
        }
    }
    ~CTelNumber()
    {
        delete[] phone;
    }
    bool judge()
    {
        int bok = 1;
        if (strlen(phone) != 7)
        {
            bok = 0;
        }
        for (int i = 0; i < 7; i++)
        {
            if (phone[i] > '9' || phone[i] < '0')
            {
                bok = 0;
            }
        }
        if (phone[0] >= '9' || phone[0] <= '1')
        {
            bok = 0;
        }
        if (bok == 0)
        {
            cout << "Illegal phone number" << endl;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    void print()
    {
        for (int i = 0; i < 8; i++)
        {
            cout << phone[i];
        }
        cout << endl;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char p[8];
        cin >> p;
        CTelNumber tem(p);
        if (tem.judge())
        {
            CTelNumber phone(tem);
            phone.print();
        }
    }
}