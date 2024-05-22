#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Equation {
private:
    double a, b, c;

public:
    Equation() : a(1), b(1), c(0) {}
    Equation(double A, double B, double C) : a(A), b(B), c(C) {}
    void set(double A, double B, double C) {
        a = A;
        b = B;
        c = C;
    }
    void getRoot() {
        double delta = b * b - 4 * a * c;
        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "x1=" << fixed << setprecision(2) << x1 << " x2=" << x2 << endl;
        } else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "x1=x2=" << fixed << setprecision(2) << x << endl;
        } else {
            double real = -b / (2 * a);
            double imaginary = sqrt(-delta) / (2 * a);
            cout << "x1=" << fixed << setprecision(2) << real << "+" << imaginary << "i ";
            cout << "x2=" << real << "-" << imaginary << "i" << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        double a, b, c;
        cin >> a >> b >> c;

        Equation eq(a, b, c);
        eq.getRoot();
    }

    return 0;
}
