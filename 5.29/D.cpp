#include <iostream>
#include <cmath>
using namespace std;

class CPoint
{
private:
    int x, y;

public:
    CPoint(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }
};

class CRectangle
{
private:
    CPoint leftPoint, rightPoint;

public:
    CRectangle(int x1, int y1, int x2, int y2) : leftPoint(x1, y1), rightPoint(x2, y2) {}

    bool operator>(const CPoint &point) const
    {
        return (point.getX() >= leftPoint.getX() && point.getX() <= rightPoint.getX() &&
                point.getY() >= rightPoint.getY() && point.getY() <= leftPoint.getY());
    }

    bool operator>(const CRectangle &other) const
    {
        return leftPoint.getX() <= other.leftPoint.getX() && leftPoint.getY() >= other.leftPoint.getY() &&
               rightPoint.getX() >= other.rightPoint.getX() && rightPoint.getY() <= other.rightPoint.getY();
    }
    bool operator==(const CRectangle &other) const
    {
        return leftPoint.getX() == other.leftPoint.getX() && leftPoint.getY() == other.leftPoint.getY() &&
               rightPoint.getX() == other.rightPoint.getX() && rightPoint.getY() == other.rightPoint.getY();
    }
    bool operator*(const CRectangle &other) const
    {
        return !(rightPoint.getX() < other.leftPoint.getX() || leftPoint.getX() > other.rightPoint.getX() ||
                 rightPoint.getY() > other.leftPoint.getY() || leftPoint.getY() < other.rightPoint.getY());
    }
    operator int() const
    {
        int width = abs(rightPoint.getX() - leftPoint.getX());
        int height = abs(leftPoint.getY() - rightPoint.getY());
        return width * height;
    }
    friend ostream &operator<<(ostream &out, const CRectangle &rect)
    {
        out << rect.leftPoint.getX() << " " << rect.leftPoint.getY() << " "
            << rect.rightPoint.getX() << " " << rect.rightPoint.getY();
        return out;
    }
};
int main()
{
    int t, x1, x2, y1, y2;
    cin >> t;

    while(t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;  //矩形1的左上角、右下角
        CRectangle rect1(x1,y1,x2,y2);
        cin >> x1 >> y1 >> x2 >> y2;  //矩形2的左上角、右下角
        CRectangle rect2(x1,y1,x2,y2);
        
        cout << "矩形1:" << rect1 << " " << (int)rect1 << endl;
        cout << "矩形2:"  << rect2 << " " << (int)rect2 << endl;

        if(rect1 == rect2)       //判两个矩形相等
            cout << "矩形1和矩形2相等" << endl;
        else if(rect2 > rect1)  //判矩形2包含矩形1
            cout << "矩形2包含矩形1" << endl;
        else if(rect1 > rect2)  //判矩形1包含矩形2
            cout << "矩形1包含矩形2" << endl;
        else if(rect1 * rect2)  //判矩形1和矩形2相交
            cout << "矩形1和矩形2相交" << endl;
        else
            cout << "矩形1和矩形2不相交" << endl;
        cout << endl;
    }
    return 0;
}

