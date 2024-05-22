#include <iostream>
#include <cmath>
using namespace std;
int isNumber(string str)
{
    int sum = 0;
    for(int i = 0;i < str.length();i++)
    {
        if (str[i] >= '0'&&str[i] <= '9')
        {
            sum += pow(10, str.length() - 1 - i) * (int(str[i]) - 48);
        }
        else
        {
            return -1;
        }
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        string str;
        cin >> str;
        cout << isNumber(str) << endl;
    }
}