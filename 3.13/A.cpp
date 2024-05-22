#include <iostream>
#include <iomanip> 
using namespace std;
int main()
{
    double usdollar = 6.2619;
    double europe = 6.6744;
    double japan = 0.0516;
    double hk = 0.8065;
    const double *p = &usdollar;
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        double num;
        char category;
        cin >> category >> num;
        if (category == 'D')
        {
            p = &usdollar;
        }
        if (category == 'E')
        {
            p = &europe;
        }
        if (category == 'Y')
        {
            p = &japan;
        }
        if (category == 'H')
        {
            p = &hk;
        }
        cout << fixed << setprecision(4) << *p * num << endl;
    }
    return 0;
}