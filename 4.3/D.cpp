#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

class CTriangle {
private:
    double side1, side2, side3;
    string type;

public:
    CTriangle(double s1, double s2, double s3);
    ~CTriangle();
    double calcArea();
    void setType();
    string getType();
};

CTriangle::CTriangle(double s1, double s2, double s3) {
    side1 = s1;
    side2 = s2;
    side3 = s3;
    setType();
}

CTriangle::~CTriangle() {
    side1 = side2 = side3 = 0;
    type = "none";
}

void CTriangle::setType() {
    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        type = "no triangle";
        return;
    }

    if (fabs(side1 - side2) < 1e-1 || fabs(side1 - side3) < 1e-1 || fabs(side2 - side3) < 1e-1) {
        if (fabs(side1 * side1 + side2 * side2 - side3 * side3) < 1e-1 ||
            fabs(side1 * side1 + side3 * side3 - side2 * side2) < 1e-1 ||
            fabs(side2 * side2 + side3 * side3 - side1 * side1) < 1e-1) {
            type = "isosceles right triangle";
        } else {
            type = "isosceles triangle";
        }
    } else {
        if (fabs(side1 * side1 + side2 * side2 - side3 * side3) < 1e-1 ||
            fabs(side1 * side1 + side3 * side3 - side2 * side2) < 1e-1 ||
            fabs(side2 * side2 + side3 * side3 - side1 * side1) < 1e-1) {
            type = "right triangle";
        } else {
            type = "general triangle";
        }
    }
}

string CTriangle::getType() {
    return type;
}

double CTriangle::calcArea() {
    double s = (side1 + side2 + side3) / 2;
    double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    return area;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        double s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        CTriangle triangle(s1, s2, s3);
        cout << triangle.getType();

        if (triangle.getType() != "no triangle") {
            cout << fixed << setprecision(1) << ", " << triangle.calcArea() << endl;
        } else {
            cout << endl;
        }
    }

    return 0;
}
