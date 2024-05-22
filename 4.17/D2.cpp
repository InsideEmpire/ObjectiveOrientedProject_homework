#include <iostream>
using namespace std;

class complex {
public:
    complex();
    complex(double r, double i);
    friend complex addCom(complex &c1, complex c2);
    friend void outCom(complex c);

private:
    double real;
    double imag;
};

complex::complex() {}

complex::complex(double r, double i) : real(r), imag(i) {}

complex addCom(complex &c1, complex c2) {
    c1.real = c1.real + c2.real;
    c1.imag = c1.imag + c2.imag;
    return c1;
}

void outCom(complex c) {
    cout << '(' << c.real << ',' << c.imag << ')' << endl;
}

int main() {
    int a, b;
    cin >> a >> b;
    complex *first = new complex(a, b);
    int t;
    cin >> t;
    while (t--) {
        char sign;
        cin >> sign >> a >> b;
        if (sign == '-') {
            a *= -1;
            b *= -1;
        }
        complex tem(a, b);
        outCom(addCom(*first, tem));
    }
    delete first;
    return 0;
}
