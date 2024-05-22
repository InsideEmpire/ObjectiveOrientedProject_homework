#include <iostream>

class Complex {
private:
    int real;
    int imag;

public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex &other) const {
        return Complex(this->real + other.real, this->imag + other.imag);
    }

    Complex operator-(const Complex &other) const {
        return Complex(this->real - other.real, this->imag - other.imag);
    }

    Complex operator*(const Complex &other) const {
        int real_part = this->real * other.real - this->imag * other.imag;
        int imag_part = this->imag * other.real + this->real * other.imag;
        return Complex(real_part, imag_part);
    }

    void print() const {
        std::cout << "Real=" << real << " Image=" << imag << std::endl;
    }
};

int main() {
    int real1, imag1, real2, imag2;

    std::cin >> real1 >> imag1;
    Complex c1(real1, imag1);

    std::cin >> real2 >> imag2;
    Complex c2(real2, imag2);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    sum.print();
    diff.print();
    prod.print();

    return 0;
}
