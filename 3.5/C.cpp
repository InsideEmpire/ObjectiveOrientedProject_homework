#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        string sen, ans;
        cin >> sen;
        for(int j = 0;j < sen.length();j++)
        {
            if ((sen[j] >= 'a'&&sen[j] <= 'v')||(sen[j] >= 'A'&&sen[j] <= 'V'))
            {

                ans = ans + char(int(sen[j] + 4));
                continue;
            }
            if ((sen[j] >= 'w'&&sen[j] <= 'z')||(sen[j] >= 'W'&&sen[j] <= 'Z'))
            {
                
                ans = ans + char(int(sen[j] - 22));
                continue;
            }
            ans = ans + sen[j];
        }
        cout << ans << endl;
    }
    return 0;
}