#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
void mySort(T *a, int n, int beg, int end)
{
    if (beg > end)
    {
        return;
    }
    if (beg < 0)
    {
        beg = 0;
    }
    if (end > n)
    {
        end = n;
    }
    for (int i = beg; i < end; i++)
    {
        for (int j = i + 1; j < end; j++)
        {
            if (a[i] > a[j])
            {
                T temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
template <class T>
void myPrint(T *a, int n)
{
    cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << ", ";
    }
    cout << a[n - 1];
    cout << "]" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char trash;
        string type;
        int n;
        int beg, end;
        cin >> type >> n;
        for (int i = 1; i <= 1; i++)
        {
            cin >> trash;
        }
        cin >> beg;
        for (int i = 1; i <= 1; i++)
        {
            cin >> trash;
        }
        cin >> end;

        for (int i = 1; i <= 2; i++)
        {
            cin >> trash;
        }
        if (type == "int")
        {
            int *p = new int[n + 1];
            for (int i = 0; i < n; i++)
            {
                cin >> p[i];
            }
            mySort<int>(p, n, beg, end);
            myPrint(p, n);
        }
        if (type == "string")
        {
            string *p = new string[n + 1];
            for (int i = 0; i < n; i++)
            {
                cin >> p[i];
            }
            mySort<string>(p, n, beg, end);
            myPrint(p, n);
        }
        if (type == "float")
        {
            float *p = new float[n + 1];
            for (int i = 0; i < n; i++)
            {
                cin >> p[i];
            }
            mySort<float>(p, n, beg, end);
            //
            cout << "[";
            for (int i = 0; i < n - 1; i++)
            {
                cout << fixed << setprecision(1) << p[i] << ", ";
            }
            cout << fixed << setprecision(1) << p[n - 1];
            cout << "]" << endl;
        }
    }
}