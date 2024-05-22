#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14

class Point
{
    double x, y;

public:
    Point() // Default constructor, initializes x and y to 0
    {
        x = 0;
        y = 0;
    }
    Point(double x_value, double y_value) : x(x_value), y(y_value) {} // Parameterized constructor
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    void setXY(double x1, double y1)
    {
        x = x1;
        y = y1;
    }
    void setX(double x_value)
    {
        x = x_value;
    }
    void setY(double y_value)
    {
        y = y_value;
    }
    double getDistanceTo(Point &p)
    {
        return sqrt(pow((x - p.getX()), 2) + pow(y - p.getY(), 2));
    }
};

class Circle
{
    Point centre;
    double radius;

public:
    Circle() // Default constructor, sets centre position to (0, 0) and radius to 1
    {
        centre.setXY(0, 0);
        radius = 1;
    }
    Circle(double x, double y, double r) // Parameterized constructor
    {
        centre.setXY(x, y);
        radius = r;
    }
    double getArea()
    {
        return PI * pow(radius, 2);
    }
    void moveCentreTo(double x1, double y1)
    {
        centre.setXY(x1, y1);
    }
    int contain(Point &p)
    {
        return p.getDistanceTo(centre) <= radius ? 1 : 0;
    }
};

int main()
{
    double x, y, r;
    int n;
    cin >> x >> y >> r;
    cin >> n;
    Circle tem(x, y, r);
    double X[101], Y[101];
    for (int i = 1; i <= n; i++)
    {
        cin >> X[i] >> Y[i];
    }
    for (int i = 1; i <= n; i++)
    {
        Point p(X[i], Y[i]);
        if (tem.contain(p))
        {
            cout << "inside\n";
        }
        else
        {
            cout << "outside\n";
        }
    }
    cout << "after moving the center of the circle:\n";
    double new_x, new_y;
    cin >> new_x >> new_y; // Read in the new center coordinates
    tem.moveCentreTo(new_x, new_y);
    for (int i = 1; i <= n; i++)
    {
        Point p(X[i], Y[i]);
        if (tem.contain(p))
        {
            cout << "inside\n";
        }
        else
        {
            cout << "outside\n";
        }
    }
    return 0;
}
