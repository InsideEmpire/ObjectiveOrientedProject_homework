#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14
class Point
{
    double x, y;

public:
    Point()// 缺省构造函数，给x,y分别赋值为0
    {
        x = 0;
        y = 0;
    }
    Point(double x_value, double y_value):x(x_value),y(y_value){}// 有参构造函数，给x，y赋参数的值
    double getX()// 返回x的值
    {
        return x;
    }
    double gety()// 返回y的值
    {
        return y;
    }
    void setXY(double x1, double y1)
    {
        x = x1;
        y = y1;
    }
    void setX(double x_value)// 设置x的值
    {
        x = x_value;
    }
    void setY(double y_value)// 设置y的值
    {
        y = y_value;
    }
    double getDisTo(Point &p)// 计算当前点到参数点p的距离
    {
        return sqrt(pow((x - p.getX()), 2) + pow(y - p.gety(), 2));
    }
    //~Point();
};
class Circle 
{
    Point centre;// 圆心
    double radius; // 半径
public:
    Circle()// 设置圆心位置为(0,0），半径为1 
    {
        centre.setXY(0, 0);
        radius = 1;
    }
    Circle(double x,double y,double r)//设置圆心位置为(x,y），半径为r
    {
        centre.setXY(x, y);
        radius = r;
    }
    double getArea()// 返回圆的面积
    {
        return PI * pow(radius, 2);
    }
    void moveCentreTo(double x1,double y1)//将圆心位置移动到(x1.y1）
    {
        centre.setXY(x1, y1);
    }
    int contain(Point & p)// 判断圆与点p的关系，如果点p在圆内，返回1，否则返回o
    {
        return p.getDisTo(centre) <= radius ? 1 : 0;
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
    for(int i = 1;i <= n;i++)
    {
        cin >> X[i] >> Y[i];
    }
    for(int i = 1;i <= n;i++)
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
    cout << "after move the centre of circle:\n";
    double new_x, new_y;
    tem.moveCentreTo(new_x, new_y);
    for(int i = 1;i <= n;i++)
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
}