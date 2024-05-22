#include <iostream>
using namespace std;
class Rectangular
{
    private:
    int n, m;
    int **square;
    public:
    Rectangular(int **s, int M, int N):square(s),m(M),n(N)
    {
        cout << "before:\n";
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if (j != n - 1)
                {
                    cout << square[i][j] << ' ';
                }
                else
                {
                    cout << square[i][j] << endl;
                }
                
            }
        }

    }
    Rectangular(Rectangular &before)
    {
        m = before.n;
        n = before.m;
        square = new int*[before.n];
        for(int i = 0;i < before.n;i++)
        {
            square[i] = new int[before.m];
        }
        for(int i = 0;i < before.m;i++)
        {
            for(int j = 0;j < before.n;j++)
            {
                square[j][n - i - 1] = before.square[i][j];
            }
        }
        cout << "after:\n";
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if (j != n - 1)
                {
                    cout << square[i][j] << ' ';
                }
                else
                {
                    cout << square[i][j] << endl;
                }
                
            }
        }        
    }
    ~Rectangular()
    {
        for(int i = 0;i < m;i++)
        {
            delete square[i];
        }
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m,n;
        cin >> m >> n;
        int ** square;
        square = new int*[m];
        for(int i = 0;i < m;i++)
        {
            square[i] = new int[n];
        }
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                cin >> square[i][j];
            }
        }        
        Rectangular before(square, m, n);
        Rectangular after(before);
    }
    
    return 0;
}