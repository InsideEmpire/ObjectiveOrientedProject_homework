#include <iostream>
#include <cmath>
using namespace std;
long change(string s)
{
    int total = 0;
    for(int i = s.length() - 1, j = 0;i >= 0;i--, j++)
    {
        if (s[i] >= '0'&&s[i] <= '9')
        {
            total += pow(16, j) * (int(s[i]) - 48);
        }
        else
        {
            total += pow(16, j) * (int(s[i]) - 55);
        }
    }
    return total;
}
int main()
{
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        string s;
        cin >> s;
        cout << change(s) << endl;
    }
    return 0;
}