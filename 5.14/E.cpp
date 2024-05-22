#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

class Shape {
protected:
    string name;
    double x, y;
public:
    virtual string getName() const = 0;
    virtual double getX() const = 0;
    virtual double getY() const = 0;
    virtual double getArea() const {
        return 0.0;
    }
    virtual double getVolume() const {
        return 0.0;
    }
    virtual void shapeName(string n) = 0;

};

class Point : public Shape {
public:
    Point(double _x, double _y){
        x = _x;
        y = _y;
        shapeName("Point");
    }
    string getName() const {
        return name;
    }
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    void shapeName(string n) {
        name = n;
    }
};

class Circle : public Point {
protected:
    double r;
public:
    Circle(double _x, double _y, double _r) : Point(_x, _y), r(_r) {
        shapeName("Circle");
    }
    double getArea() const {
        return 3.14159 * r * r;
    }
    string getName() const {
        return name;
    }
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    void shapeName(string n) {
        name = n;
    }
};

class Cylinder : public Circle {
protected:
    double h;
public:
    Cylinder(double _x, double _y, double _r, double _h) : Circle(_x, _y, _r), h(_h) {
        shapeName("Cylinder");
    }
    double getArea() const {
        return 2 * Circle::getArea() + 2 * 3.14159 * r * h;
    }
    double getVolume() const {
        return Circle::getArea() * h;
    }
    string getName() const {
        return name;
    }
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    void shapeName(string n) {
        name = n;
    }
};

void Print(Shape *shape) {
    cout << shape->getName() << "--(" << fixed << setprecision(1) << shape->getX() << "," << fixed << setprecision(1) << shape->getY() << ")--" << static_cast<int>(shape->getArea()) << "--" << static_cast<int>(shape->getVolume()) << endl;
}

int main() {
    double x, y, r, h;
    cin >> x >> y;
    Point point(x, y);
    Print(&point);

    cin >> x >> y >> r;
    Circle circle(x, y, r);
    Print(&circle);

    cin >> x >> y >> r >> h;
    Cylinder cylinder(x, y, r, h);
    Print(&cylinder);

    return 0;
}
