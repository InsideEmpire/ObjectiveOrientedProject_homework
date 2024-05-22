#include <iostream>
using namespace std;
void ReSequence(int &a, int &b, int &c)
{
    if (b < c)
    {
        int temp;
        temp = b;
        b = c;
        c = temp;
    }
    if (a < b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    if (b < c)
    {
        int temp;
        temp = b;
        b = c;
        c = temp;
    }
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ReSequence(a, b, c);
        cout <<' '<< a <<' '<< b <<' '<< c << endl;
    }
    
}