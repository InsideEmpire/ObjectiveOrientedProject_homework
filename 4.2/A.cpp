#include <iostream>
#include <cmath>
using namespace std;
class Point
{
    private:
    int x, y;
    public:
    Point():x(0),y(0){}
    Point(int X, int Y):x(X), y(Y) {}
    ~Point()
    {
        x = 0;
        y = 0;
        cout << "point clear" <<endl;
    }
    void setXY()
    {
        cin >> x >> y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};
class Circle
{
    private:
    int x, y, r;
    public:
    Circle(int X, int Y, int R):x(X), y(Y), r(R){};
    ~Circle()
    {
        x = 0;
        y = 0;
        r = 0;
        cout << "circle clear" <<endl;
    }
    void Contain(int X, int Y)
    {
        int distance = sqrt((x - X) * (x - X) + (y - Y) * (y - Y));
        if (distance > r)
        {
            cout << "out" << endl;
        }
        else
        {
            cout << "in" << endl;
        }
    }
};
int main()
{
    int n;
    int px, py;
    cin >> px >> py;
    Point p1(px, py);
    cin >> n;
    Point *p = new Point[n];
    for(int i = 0;i < n;i++)
    {
        p[i].setXY();
    }
    int cx, cy, cr;
    cin >> cx >> cy >> cr;
    Circle c(cx, cy, cr);
    c.Contain(px, py);
    for(int i = 0;i < n;i++)
    {
        px = p[i].getX();
        py = p[i].getY();
        c.Contain(px, py);
    }
    delete &c;
    delete &p1;
    //cout << "circle clear" <<endl;
    //cout << "point clear" <<endl;
    return 0;
}