#include <iostream>
#include <cmath>
using namespace std;
class Group
{
protected:
    int x;
    int y;
public:
    virtual int add(int x, int y) = 0; // 输出加法的运算结果
    virtual int sub(int x, int y) = 0; // 输出减法的运算结果
    Group(int X, int Y):x(X),y(Y){}
};
class GroupA:public Group
{
public:
    virtual int add(int x, int y)
    {
        return x + y;
    }
    virtual int sub(int x, int y)
    {
        return x - y;
    }
    GroupA(int X, int Y):Group(X, Y){}
};
class GroupB:public Group
{
public:
    virtual int add(int x, int y)
    {
        return x + y;
    }
    virtual int sub(int x, int y)
    {
        int ans = 0;
        //loops
        int times = 0;
        while (x >= 0 || y >= 0)
        {
            ans += (((x % 10) - (y % 10) + 10) % 10) * pow(10, times);
            x = x / 10;
            y = y / 10;
            if (x == 0 && y == 0)
            {
                break;
            }
            times++;
        }
        return ans;
    }
    GroupB(int X, int Y):Group(X, Y){}
};
class GroupC:public Group
{
public:
    virtual int add(int x, int y)
    {
        int ans = 0;
        int times = 0;
        while (x >= 0 || y >= 0)
        {
            ans += (((x % 10) + (y % 10)) % 10) * pow(10, times);
            x = x / 10;
            y = y / 10;
            if (x == 0 && y == 0)
            {
                break;
            }
            
            times++;
        }
        return ans;
    }
    virtual int sub(int x, int y)
    {
        int ans = 0;
        int times = 0;
        while (x >= 0 && y >= 0)
        {
            ans += (((x % 10) - (y % 10) + 10) % 10) * pow(10, times);
            x = x / 10;
            y = y / 10;
            if (x == 0 && y == 0)
            {
                break;
            }
            times++;
        }
        return ans;
    }
    GroupC(int X, int Y):Group(X, Y){}
};
int main()
{
    int t;
    cin >> t;
    int type;
    char tem;
    Group *p;
    while (t--)
    {
        int x, y;
        cin >> type;
        cin >> x >> tem >> y;
        if (type == 1)
        {
            GroupA test(x, y);
            p = & test;
            if (tem == '+')
            {
                cout << p->add(x, y) << endl;
            }
            else
            {
                cout << p->sub(x, y) << endl;
            }
        }
        else if (type == 2)
        {
            GroupB test(x, y);
            p = & test;
            if (tem == '+')
            {
                cout << p->add(x, y) << endl;
            }
            else
            {
                cout << p->sub(x, y) << endl;
            }
        }
        else if (type == 3)
        {
            GroupC test(x, y);
            p = & test;
            if (tem == '+')
            {
                cout << p->add(x, y) << endl;
            }
            else
            {
                cout << p->sub(x, y) << endl;
            }
        }
    }
    
}