#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Point
{
    private:
    double x, y;
    public:
    Point():x(0.00),y(0.00){}
    Point(double x_value, double y_value):x(x_value),y(y_value){}
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    void setX(double x_value)
    {
        x = x_value;
    }
    void setY(double y_value)
    {
        y = y_value;
    }
    double distanceToAnotherPoint(Point p)
    {
        double distance = sqrt((x - p.getX()) * (x - p.getX()) + (y - p.getY()) * (y - p.getY()));
        return distance;
    }
};
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        Point p1, p2;
        double x, y;
        cin >> x >> y;
        p1.setX(x);
        p1.setY(y);
        cin >> x >> y;
        p2.setX(x);
        p2.setY(y);
        double dis = p1.distanceToAnotherPoint(p2);
        cout << fixed << setprecision(2) << "Distance of Point(" << p1.getX() << ',' << p1.getY() << ") to Point(" << p2.getX() << ',' << p2.getY() << ") is " << dis << endl;
    }
}