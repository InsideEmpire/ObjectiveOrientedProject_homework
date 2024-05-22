#include <iostream>
#include <iomanip>
using namespace std;

#define PI 3.14

class CPoint {
public:
    int x;
    int y;
};

class CCircle : protected CPoint {
public:
    CCircle(int X, int Y, int R) : x(X), y(Y), r(R) {}
    int r;
    double countArea() {
        double area;
        area = PI * r * r;
        return area;
    }
    void print() {
        cout << "Circle:(" << x << "," << y << ")," << r << endl;
        cout << "Area:" << fixed << setprecision(2) << countArea() << endl;
    }
};

class CCylinder : public CCircle {
public:
    int h;
    CCylinder(int X, int Y, int R, int H) : CCircle(X, Y, R), h(H) {}
    double countVolume() {
        double volume;
        volume = countArea() * h;
        return volume;
    }
    void print() {
        cout << "Cylinder:(" << x << "," << y << ")," << r << "," << h << endl;
        cout << "Volume:" << fixed << setprecision(2) << countVolume() << endl;
    }
};

int main() {
    int x1, y1, r1, h1;
    cout << "Enter the coordinates (x y) and radius (r) of the circle: ";
    cin >> x1 >> y1 >> r1;
    cout << "Enter the height (h) of the cylinder: ";
    cin >> h1;

    CCylinder cylinder(x1, y1, r1, h1);
    cylinder.print();

    return 0;
}
