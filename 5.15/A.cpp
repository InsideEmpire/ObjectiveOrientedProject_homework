#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.1415
class Shape
{
public:
    virtual void Circumference() = 0;
};
class Circle:public Shape
{
protected:
    double r;
public:
    void Circumference()
    {
        cout << fixed << setprecision(2) << "Circumference of Circle: " << 2 * PI * r << endl;
    }
    Circle(double R):r(R){}
};
class Square:public Shape
{
protected:
    double s;
public:
    void Circumference()
    {
        cout << fixed << setprecision(2) << "Circumference of Square: " << 4 * s << endl;
     
    }
    Square(double S):s(S){}
};
class Rectangle:public Shape
{
protected:
    double w;
    double l;
public:
    void Circumference()
    {
        cout << fixed << setprecision(2) << "Circumference of Rectangle: " << (w + l) * 2 << endl;
    }
    Rectangle(double W, double L):w(W),l(L){}
};
int main()
{
    int t;
    cin >> t;
    Shape *p;
    while (t--)
    {
        double r;
        double s;
        double w, l;
        cin >> r >> s >> l >> w;
        Circle a(r);
        p = &a;
        p->Circumference();
        Square b(s);
        p = &b;
        p->Circumference();
        Rectangle c(w, l);
        p = &c;
        p->Circumference();
    }
    
}