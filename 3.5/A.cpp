#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        bool fit = 0;
        int x[3];
        int y[3];
        for (int j = 0; j < 3; j++)
        {
            cin >> x[j];
        }
        for (int j = 0; j < 3; j++)
        {
            cin >> y[j];
        }
        sort(x, x + 3);
        sort(y, y + 3);
        if ((x[0] >= y[0] && x[1] >= y[1] && x[2] >= y[2]) || (x[0] <= y[0] && x[1] <= y[1] && x[2] <= y[2]))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}