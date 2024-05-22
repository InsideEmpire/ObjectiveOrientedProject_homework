#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    friend double Distance(Point &a, Point &b);
};

double Distance(Point &a, Point &b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point p1(x1, y1);
        Point p2(x2, y2);
        cout << int(Distance(p1, p2)) << endl;
    }

    return 0;
}
