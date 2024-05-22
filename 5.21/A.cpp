#include <iostream>
using namespace std;
class Fraction
{
private:
    int numerator, denominator;
public:
    int common_divisor(Fraction tem)//计算最大公约数
    {
        int biggest = 2;
        while (true)
        {
            if (tem.denominator % biggest == 0 && tem.numerator % biggest == 0)
            {
                return biggest;
            }
            else if (biggest > tem.denominator && biggest > tem.numerator)
            {
                return 1;
            }
            
            else
            {
                biggest++;
            }
        }
        
    }
    // void contracted();//分数化简
    Fraction()
    {
        numerator = 1;
        denominator = 1;
    }
    Fraction(int nu, int de):numerator(nu), denominator(de) {}
    Fraction(Fraction &tem){*this = tem;}
    Fraction operator+(Fraction in)
    {
        Fraction tem;
        tem.denominator = this->denominator * in.denominator;
        tem.numerator = this->numerator * in.denominator + this->denominator * in.numerator;
        int biggest = common_divisor(tem);
        tem.denominator /= biggest;
        tem.numerator /= biggest;
        return tem;
    }
    Fraction operator-(Fraction in)
    {
        Fraction tem;
        tem.denominator = this->denominator * in.denominator;
        tem.numerator = this->numerator * in.denominator - this->denominator * in.numerator;
        int biggest = common_divisor(tem);
        tem.denominator /= biggest;
        tem.numerator /= biggest;
        return tem;
    }
    Fraction operator*(Fraction in)
    {
        Fraction tem;
        tem.denominator = this->denominator * in.denominator;
        tem.numerator = this->numerator * in.numerator;
        int biggest = common_divisor(tem);
        tem.denominator /= biggest;
        tem.numerator /= biggest;
        return tem;
    }
    Fraction operator/(Fraction in)
    {
        Fraction tem;
        tem.denominator = this->denominator * in.numerator;
        tem.numerator = this->numerator * in.denominator;
        int biggest = common_divisor(tem);
        tem.denominator /= biggest;
        tem.numerator /= biggest;
        return tem;
    }
    void Set(int nu, int de)
    {
        numerator = nu;
        denominator = de;
    }
    void disp()
    {
        cout << "fraction=" << numerator << "/" << denominator << endl;
    }
};

int main()
{
    int n1, d1, n2, d2;
    cin >> n1 >> d1 >> n2 >> d2;
    Fraction a(n1, d1);
    Fraction b(n2, d2);
    (a + b).disp();
    (a - b).disp();
    (a * b).disp();
    (a / b).disp();
}