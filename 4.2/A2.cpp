#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {} // 默认构造函数
    Point(int x, int y) : x(x), y(y) {} // 构造函数重载

    ~Point() {
        x = 0;
        y = 0;
        cout << "point clear" << endl;
    }

    void setXY(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
};

class Circle {
private:
    int x, y;
    double r;

public:
    Circle(int x, int y, double r) : x(x), y(y), r(r) {}

    ~Circle() {
        x = 0;
        y = 0;
        r = 0;
        cout << "circle clear" << endl;
    }

    bool contain(Point p) {
        double distance = sqrt((x - p.getX()) * (x - p.getX()) + (y - p.getY()) * (y - p.getY()));
        return distance <= r;
    }
};

int main() {
    int px, py;
    cin >> px >> py;
    Point point(px, py);

    int n;
    cin >> n;
    Point *points = new Point[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i].setXY(x, y);
    }

    int cx, cy;
    double cr;
    cin >> cx >> cy >> cr;
    Circle circle(cx, cy, cr);

    for (int i = 0; i < n; i++) {
        if (circle.contain(points[i])) {
            cout << "in" << endl;
        } else {
            cout << "out" << endl;
        }
    }

    // 不要忘记释放内存
    delete[] points;

    return 0;
}