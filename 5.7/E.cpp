// 请补充头文件、polyitem类、友元函数split和poly类实现。注意poly类的析构函数已经实现，无需再写

/********** Write your code here! **********/
#include <iostream>
using namespace std;
class polyitem
{
private:
    int A, B, C;
public:
    friend poly;
    friend polyitem split(string item);
    polyitem(int a, int b, int c):A(a),B(b),C(c){}
    polyitem(){}

};
polyitem split(string item)
{
    int a = 0, b = 0, c = 0;
    if (item[0] == '-' && (item[1] == 'x' || item[1] == 'y'))
    {
        a = -1;
    }
    else if (item[0] == '-' && (item[1] != 'x' || item[1] != 'y'))
    {
        a = -1 * ((int)item[1] - 48);
    }
    else if (item[0] == 'x' || item[0] == 'y')
    {
        a = 1;
    }
    else if (item[1] == 'x' || item[1] == 'y')
    {
        a = ((int)item[0] - 48);
    }
    else
    {
        return polyitem(1, 0, 0);
    }
    for (int i = 0; i < item.length(); i++)
    {
    //     if (item[i] == 'x')
    //     {
    //         if (item[i - 1] == '-')
    //         {
    //             a = -1;
    //         }
    //         else if (item[i - 2] == '-')
    //         {
    //             a = -1 * ((int)item[i - 1] - 48);
    //         }
    //         else
    //         {
    //             a = ((int)item[i - 1] - 48);
    //         }
    //     }
        if (item[i] == 'x')
        {
            if (item[i + 1] == '^')
            {
                if (item[i + 2] == '-' && item[i + 3] != 'y')
                {
                    b = -1 * ((int)item[i + 3] - 48);
                }
                else if (item[i + 3] == 'y')
                {
                    b = ((int)item[i + 2] - 48);
                }
            }
            else if (item[i + 1] == 'y')
            {
                b = 1;
            }
            
        }
        // if (item[i] == 'y')
        // {
        //     if (item[i + 1] == '^')
        //     {
        //         if (item[i + 2] == '-')
        //         {
        //             c = -1 * ((int)item[i + 3] - 48);
        //         }
        //         else if (item[i + 2] == 'y')
        //         {
        //             c = ((int)item[i + 2] - 48);
        //         }
        //     }
        // }
    }
    if (item[item.length() - 2] == '-')
    {
        c = -1 * ((int)item[item.length() - 1] - 48);
    }
    else if (item[item.length() - 2] == '^')
    {
        c = ((int)item[item.length() - 1] - 48);
    }
    else if (item[item.length() - 2] == 'y')
    {
        c = 1;
    }
    return polyitem(a, b, c);
}
class poly
{
private:
    polyitem *item;
    int n;
public:
    poly(string polystr)
    {
        
    }
};
/*******************************************/
// poly类的析构函数
poly::~poly()
{
    if (items)
        delete[] items;
}

// 主函数
int main()
{
    string polystr;
    int t, m;
    string op;

    cin >> t; // 输入测试次数t

    while (t--)
    {
        cin >> m; // 输入m, 表示m个多项式

        poly polyres; // 初始结果多项式，项数0

        for (auto i = 0; i < m; i++)
        {
            cin >> polystr;         // 输入多项式串
            poly polya(polystr);    // 解析polystr串构造多项式
            polya.polysort();       // 按指数降序排序
            polya.display();        // 输出解析构造的多项式
            polyres.addpoly(polya); // polyres+=polya
        }
        polyres.display(); // 按指数降序排序输出
    }

    return 0;
}
