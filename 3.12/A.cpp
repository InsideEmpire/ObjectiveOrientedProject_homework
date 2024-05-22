#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        int *a[3];
        int q, w, e;
        cin >> q >> w >> e;
        a[0] = &q;
        a[1] = &w;a[2] = &e;
        for(int j = 0;j < 3;j++)
        {
            for(int k = 0;k < 3 - j - 1;k++)
            {
                if (*a[k] < *a[k + 1])
                {
                    swap(a[k] , a[k + 1]);
                }
                
            }
        }
        cout << *a[0] << ' ' << *a[1] << ' ' << *a[2] << ' ' << endl;
    }
    return 0;
}