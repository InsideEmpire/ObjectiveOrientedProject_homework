#include <iostream>
using namespace std;

template <class T>
void myPrint(T *a, T *b, int n)
{
    for(int i = 0;i < n;i++)
    {
        cout << b[i];
    }
    for(int i = 0;i < n;i++)
    {
        cout << a[i];
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string type;
        cin >> type;
        int n;
        cin >> n;
        if (type == "I")
        {
            int *a = new int[n + 1];
            int *b = new int[n + 1];
            for(int i = 0;i < n;i++)
            {
                cin >> a[i];
            }
            for(int i = 0;i < n;i++)
            {
                cin >> b[i];
            }
            myPrint(a, b, n);
        }
        if (type == "D")
        {
            double *a = new double[n + 1];
            double *b = new double[n + 1];
            for(int i = 0;i < n;i++)
            {
                cin >> a[i];
            }
            for(int i = 0;i < n;i++)
            {
                cin >> b[i];
            }
            myPrint(a, b, n);
        }
        if(type == "C")
        {
            char *a = new char[n + 1];
            char *b = new char[n + 1];
            for(int i = 0;i < n;i++)
            {
                cin >> a[i];
            }
            for(int i = 0;i < n;i++)
            {
                cin >> b[i];
            }
            myPrint(a, b, n);
        }
        
        
    }
    return 0;
}