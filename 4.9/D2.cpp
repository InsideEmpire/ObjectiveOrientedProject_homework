#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CTelNumber
{
private:
    char *str = new char[10];

public:
    CTelNumber() = default;
    CTelNumber(char *x);
    CTelNumber(CTelNumber &a);
    ~CTelNumber() = default;
    void print();
};

CTelNumber::CTelNumber(char *x)
{
    int len = 0;
    bool jud = true;
    if (x[0] > '8' || x[0] < '2')
        jud = false;
    for (int i = 0; x[i] != '\0'; i++)
    {
        len++;
        if (x[i] > '9' || x[0] < '0')
            jud = false;
    }
    if (len != 7)
        jud = false;
    if (jud == false)
        cout << "Illegal phone number" << endl;
    else
    {
        strcpy(str, x);
        print();
    }
}
CTelNumber::CTelNumber(CTelNumber &a)
{
    strcpy(str, a.str);
}
void CTelNumber::print()
{
    if (str[0] <= '4' && str[0] >= '2')
        cout << "8";
    else
        cout << '2';
    cout << str << endl;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char ans[1000];
        cin >> ans;
        CTelNumber x(ans);
    }
}