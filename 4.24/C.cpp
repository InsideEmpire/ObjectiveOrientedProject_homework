#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Point_1D
{
    protected:
    double x;
    public:
    void get(double X)
    {
        x = X;
    }
    double dis()
    {
        return sqrt(pow(x, 2));
    }
    void print()
    {
        cout << "Distance between [" << x << "] and [0] = " << fixed << setprecision(2) << dis() << endl;
    }
};
class Point_2D : public Point_1D
{
    protected:
    double y;
    public:
    void get(double X, double Y)
    {
        x = X;
        y = Y;
    }
    double dis()
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    void print()
    {
        cout << "Distance between [" << x << ", " << y << "] and [0, 0] = " << fixed << setprecision(2) << dis() << endl;
    }
};
class Point_3D : public Point_2D
{
    protected:
    double z;
    public:
    void get(double X, double Y, double Z)
    {
        x = X;
        y = Y;
        z = Z;
    }
    double dis()
    {
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }
    void print()
    {
        cout << "Distance between [" << x << ", " << y << ", " << z << "] and [0, 0, 0] = " << fixed << setprecision(2) << dis() << endl;
    }
};
int main()
{
    int type;
    cin >> type;
    while (type != 0)
    {
        if (type == 1)
        {
            double x;
            cin >> x;
            Point_1D tem;
            tem.get(x);
            tem.print();
        }
        else if (type == 2)
        {
            double x, y;
            cin >> x >> y;
            Point_2D tem;
            tem.get(x, y);
            tem.print();
        }
        else if (type == 3)
        {
            double x, y, z;
            cin >> x >> y >> z;
            Point_3D tem;
            tem.get(x, y, z);
            tem.print();
        }
        cin >> type;
    }
    
}