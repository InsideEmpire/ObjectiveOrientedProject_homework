#include <iostream>
#include <cmath>
using namespace std;

class CPoint
{
private:
    int x;
    int y;
    int z;

public:
    CPoint()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    CPoint(int X, int Y, int Z) : x(X), y(Y), z(Z) {}

    void setPoint(int X, int Y, int Z)
    {
        x = X;
        y = Y;
        z = Z;
    }

    int getX(){ return x; }
    int getY(){ return y; }
    int getZ(){ return z; }

    ~CPoint() {}
};

class CCube
{
private:
    CPoint *point;

public:
    CCube(int x1, int y1, int z1, int x2, int y2, int z2)
    {
        point = new CPoint[2];
        point[0].setPoint(x1, y1, z1);
        point[1].setPoint(x2, y2, z2);
    }

    ~CCube()
    {
        delete[] point;
    }

    int collide(CCube &r)
    {
        int x_min1 = min(point[0].getX(), point[1].getX());
        int y_min1 = min(point[0].getY(), point[1].getY());
        int z_min1 = min(point[0].getZ(), point[1].getZ());

        int x_max1 = max(point[0].getX(), point[1].getX());
        int y_max1 = max(point[0].getY(), point[1].getY());
        int z_max1 = max(point[0].getZ(), point[1].getZ());

        int x_min2 = min(r.point[0].getX(), r.point[1].getX());
        int y_min2 = min(r.point[0].getY(), r.point[1].getY());
        int z_min2 = min(r.point[0].getZ(), r.point[1].getZ());

        int x_max2 = max(r.point[0].getX(), r.point[1].getX());
        int y_max2 = max(r.point[0].getY(), r.point[1].getY());
        int z_max2 = max(r.point[0].getZ(), r.point[1].getZ());

        if (x_max1 < x_min2 || x_max2 < x_min1 ||
            y_max1 < y_min2 || y_max2 < y_min1 ||
            z_max1 < z_min2 || z_max2 < z_min1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        CCube cube1(x1, y1, z1, x2, y2, z2);

        int x3, y3, z3, x4, y4, z4;
        cin >> x3 >> y3 >> z3 >> x4 >> y4 >> z4;
        CCube cube2(x3, y3, z3, x4, y4, z4);

        if (cube1.collide(cube2))
        {
            cout << "collide" << endl;
        }
        else
        {
            cout << "have distance" << endl;
        }
    }

    return 0;
}
