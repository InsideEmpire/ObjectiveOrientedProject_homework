#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.14
class CPoint
{
    public:
    int x;
    int y;
};
class CCircle : public CPoint
{
    public:
    //CCircle(int X, int Y, int R):CPoint::x(X),CPoint::y(Y),r(r){}
    void get(int X, int Y, int R)
    {
        CPoint::x = X;
        CPoint::y = Y;
        r = R;
    }
    int r;
    double countArea()
    {
        double area;
        area = PI * r * r;
        return area;
    }
    void print()
    {
        cout << "Circle:(" << CPoint::x << "," << CPoint::y << ")," << r << endl;
        cout << "Area:" << fixed << setprecision(2) << countArea() << endl;
    }
};
class CCylinder : public CCircle
{
    public:
    void get(int X, int Y, int R, int H)
    {
        CPoint::x = X;
        CPoint::y = Y;
        CCircle::r = R;
        h = H;
    }
    int h;
    double countVolume()
    {
        double volume;
        volume = countArea() * h;
        return volume;
    }
    void print()
    {
        cout << "Cylinder:(" << CPoint::x << "," << CPoint::y << ")," << CCircle::r << "," << h <<endl;
        cout << "Volume:" << fixed << setprecision(2) << countVolume() << endl;
    }
};
int main()
{
    int x1, y1, r1;
    cin >> x1 >> y1 >> r1;
    CCircle circle;
    circle.get(x1, y1, r1);
    circle.print();
    int x2, y2, r2, h2;
    cin >> x2 >> y2 >> r2 >> h2;
    CCylinder cylinder;
    cylinder.get(x2, y2, r2, h2);
    cylinder.print();
}