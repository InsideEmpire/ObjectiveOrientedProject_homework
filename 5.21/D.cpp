#include <iostream>
#include <cmath>
using namespace std;
class Quad
{
    friend Quad operator+(Quad a, Quad b);
private:
    int num;
public:
    Quad()
    {
        num = 0;
    }
    Quad(int n):num(n){}
    void print()
    {
        cout << num << endl;
    }
};
Quad operator+(Quad a, Quad b)
{
    Quad ans;
    ans.num = 0;
    int times = 0;
    while (a.num != 0 || b.num != 0)
    {
        int a1, b1;
        a1 = a.num % 10;
        b1 = b.num % 10;
        if (a1 + b1 >= 4)
        {
            ans.num += pow(10, times + 1) + pow(10, times) * ((a1 + b1) % 4);
        }
        else
        {
            ans.num += pow(10, times) * (a1 + b1);
        }
        times++;
        a.num /= 10;
        b.num /= 10;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    Quad ans;
    while (t--)
    {
        int num;
        cin >> num;
        Quad tem(num);
        ans = ans + num;
    }
    ans.print();
}