#include <iostream>
using namespace std;
int getGCD(int a, int b)
{
    if (a < b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    int r;
    while (a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}
class Fraction
{
public:
    int sit = 1;
    int af, as;
    int bf, bs;
    int gcd;
    char slash;
    void get()
    {
        cin >> as >> slash >> af;
        cin >> bs >> slash >> bf;
    }
    void addFS()
    {
        int cf = af * bf;
        int cs = as * bf + bs * af;
        int gcd = getGCD(cf, cs);
        cout << cs / gcd << slash << cf / gcd << endl;
    }
    void subFS()
    {
        int cf = af * bf;
        int cs = as * bf - bs * af;
        if (cs < 0)
        {
            int gcd = getGCD(cs * -1, cf);
            cout << cs / gcd << slash << cf / gcd << endl;
        }
        else
        {
            int gcd = getGCD(cf, cs);
            cout << cs / gcd << slash << cf / gcd << endl;
        }
        
    }
    void mulFS()
    {
        int cf = af * bf;
        int cs = as * bs;
        int gcd = getGCD(cf, cs);
        cout << cs / gcd << slash << cf / gcd << endl;
    }
    void divFS()
    {
        int temp;
        temp = bf;
        bf = bs;
        bs = temp;
        int cf = af * bf;
        int cs = as * bs;
        int gcd = getGCD(cf, cs);
        cout << cs / gcd << slash << cf / gcd << endl;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Fraction a;
        a.get();
        a.addFS();
        a.subFS();
        a.mulFS();
        a.divFS();
        cout << endl;
    }
}