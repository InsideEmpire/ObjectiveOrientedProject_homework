#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int t ;
    cin >> t;
    string month[12] = {{"January"},{"February"},{"March"},{"April"},{"May"},{"June"},{"July"},{"August"},{"September"},{"October"},{"November"},{"December"}};
    for(int i = 1;i <= t;i++)
    {
        string *p = month;
        int num;
        cin >> num;
        if (num <= 12 && num >= 1)
        {
            cout << *(p + num - 1) << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }
}