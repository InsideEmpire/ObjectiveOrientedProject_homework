#include <iostream>
using namespace std;

class CClock
{
public:
    int hour, minute, second;
    CClock(int h, int m, int s) : hour(h), minute(m), second(s) {}
};

class CRmb
{
public:
    int hour, minute, second;
    CRmb(int y, int j, int f) : hour(y), minute(j), second(f) {}
};

template <typename T>
T add(T a, T b, int base)
{
    T result(0, 0, 0);
    result.second = (a.second + b.second) % base;
    int carry = (a.second + b.second) / base;
    result.minute = (a.minute + b.minute + carry) % base;
    carry = (a.minute + b.minute + carry) / base;
    result.hour = a.hour + b.hour + carry;
    return result;
}

int main()
{
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    CClock c1(h1, m1, s1), c2(h2, m2, s2);
    CClock c = add(c1, c2, 60);
    cout << c.hour << " " << c.minute << " " << c.second << endl;

    int y1, j1, f1, y2, j2, f2;
    cin >> y1 >> j1 >> f1 >> y2 >> j2 >> f2;
    CRmb r1(y1, j1, f1), r2(y2, j2, f2);
    CRmb r = add(r1, r2, 10);
    cout << r.hour << " " << r.minute << " " << r.second << endl;

    return 0;
}