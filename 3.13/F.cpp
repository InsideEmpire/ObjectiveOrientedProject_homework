#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int t ;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int **p;
        p = new int*[n];
        for(int i = 0;i < n;i++)
        {
            p[i] = new int[n];
        }
        int cont = 1;
        int i = 0, j = 0, k = 0;
        while (cont <= n * n)
        {
            
            for(i = k,j = k;j < n - k;j++)
            {
                p[i][j] = cont;
                cont++;
            }
            if (cont > n*n)
            {
                break;
            }
            for(i = k + 1,j = n - k - 1;i < n - k;i++)
            {
                p[i][j] = cont;
                cont++;
            }
            if (cont > n*n)
            {
                break;
            }
            for(j = n - k - 2,i = n - k - 1;j >= k;j--)
            {
                p[i][j] = cont;
                cont++;
            }
            if (cont > n*n)
            {
                break;
            }
            for(i = n - k - 2,j = k;i > k;i--)
            {
                p[i][j] = cont;
                cont++;
            }
            if (cont > n*n)
            {
                break;
            }
            k++;
        }
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < n - 1;j++)
            {
                cout << p[i][j] << ' ';
            }
            cout << p[i][n - 1] << endl;
        }
    }
    return 0;
}