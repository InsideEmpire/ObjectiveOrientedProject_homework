#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Point
{
public:
    double x, y;
public:
    bool operator > (Point &b)
    {
        double disA, disB;
        disA = sqrt(this->x * this->x + this->y * this->y);
        disB = sqrt(b.x * b.x + b.y * b.y);
        if (disA > disB)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

template <class T>
void mySort(T *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
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
    //cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << " ";
    }
    cout << a[n - 1];
    cout << " " << endl;
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
            int *p = new int[n + 1];
            for (int i = 0; i < n; i++)
            {
                cin >> p[i];
            }
            mySort<int>(p, n);
            myPrint(p, n);
        }
        if (type == "S")
        {
            string *p = new string[n + 1];
            for (int i = 0; i < n; i++)
            {
                cin >> p[i];
            }
            mySort<string>(p, n);
            myPrint(p, n);
        }
        if (type == "D")
        {
            float *p = new float[n + 1];
            for (int i = 0; i < n; i++)
            {
                cin >> p[i];
            }
            mySort<float>(p, n);
            //
            //cout << "[";
            for (int i = 0; i < n - 1; i++)
            {
                cout << p[i] << " ";
            }
            cout << p[n - 1];
            cout << " " << endl;
        }
        if (type == "P")
        {
            Point *p = new Point[n + 1];
            for (int i = 0; i < n; i++)
            {
                cin >> p[i].x >> p[i].y;
            }
            mySort<Point>(p, n);
            for (int i = 0; i < n; i++)
            {
                cout << '(';
                cout << fixed << setprecision(1) << p[i].x << ", " << fixed << setprecision(1) << p[i].y << ") ";
            }
            cout << endl;
        }
    }
}