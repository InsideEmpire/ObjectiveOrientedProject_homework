#include <iostream>
using namespace std;
class complex
{
public:
    complex();
    complex(double r, double i);
    friend complex addCom(complex &c1, complex c2);
    // 友元函数，复数c1+c2（二参数对象相加）
    friend void outCom(complex c);
    // 友元函数，输出类对象c的有关数据（c为参数对象）
private:
    double real; // 买部
    double imag; // 虚部
};
complex::complex()
{

}
complex::complex(double r, double i):real(r),imag(i){}
complex addCom(complex &c1, complex c2)
{
    c1.real = c1.real + c2.real;
    c1.imag = c1.imag + c2.imag;
    return c1;
}
void outCom(complex c)
{
    cout << '(' << c.real << ',' << c.imag << ')' << endl;
}
int main()
{
    int a, b;
    cin >> a >> b;
    complex first(a, b);
    int t;
    cin >> t;
    while (t--)
    {
        char sign;
        cin >> sign >> a >> b;
        if (sign == '-')
        {
            a *= -1;
            b *= -1;
        }
        
        complex tem(a, b);
        outCom(addCom(first, tem));
    }
    
}