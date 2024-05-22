#include <iostream>
using namespace std;
int countf(int n, int m)
{
    int upper = 1, lower = 1;
    for(int i = 1;i <= n;i++)
    {
        upper *= i;
    }
    for(int i = 1;i <= m;i++)
    {
        lower *= i;
    }
    for(int i = 1;i <= n - m;i++)
    {
        lower *= i;
    }
    return upper / lower;
}
int main()
{
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        int n, m;
        cin >> n >> m;
        cout << countf(n, m) << endl;
    }
    return 0;
}