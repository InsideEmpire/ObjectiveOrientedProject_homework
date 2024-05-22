#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        int num;
        bool judge = 0;
        cin >> num;
        if (num % 6 == 0)
        {
            judge = 1;
        }
        if (num / 100000 >= 1&&num / 100000 <= 9)
        {
            judge = 1;
        }
        if (num % 10 == 6)
        {
            judge = 1;
        }
        if (judge == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        
    }
}