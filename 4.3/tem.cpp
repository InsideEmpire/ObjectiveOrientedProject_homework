#include <iostream>
using namespace std;
// 假设每组彩票包含6个号码，设计一个彩票类lottery，数据成员包括第一组号码、其他组数、其他组号码，描述如下
class Lottery
{
private:
    int group1[6]; // 1、第一组号码group1，整数数组，长度为6
    int num;       // 2、其他组数num，表示以第一组号码为样本，创建num组其他号码
    int **groupn;

public:
    Lottery(int *group, int num);
    Lottery(const Lottery &other);
    ~Lottery();
    void print();
};

Lottery::Lottery(int *g, int n)
{
    for (int i = 0; i < 6; i++)
    {
        group1[i] = g[i];
    }
    num = n;
}

Lottery::Lottery(const Lottery &other)
{
    groupn = new int *[num];
    for (int i = 0; i < 6; i++)
    {
        group1[i] = other.group1[i];
    }
    for (int i = 0; i < 6; i++)
    {
        if (i == 0)
        {
            groupn[0][i] = group1[5] + 1;
        }
        else
        {
            groupn[0][i] = group1[i - 1] + 1;
        }
    }
    for (int j = 1; j < num; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            if (i == 0)
            {
                groupn[0][i] = group1[5] + 1;
            }
            else
            {
                groupn[0][i] = group1[i - 1] + 1;
            }
        }
    }
}
void Lottery::print()
{
    for(int i = 0;i < 6;i++)
    {
        if (i == 5)
        {
            cout << group1[i] << endl;
        }
        else
        {
            cout << group1[i] << ' ';
        }
    }
    for(int j = 0;j < num;j++)
    {
        for(int i = 0;i < 6;i++)
        {
            if (i == 5)
            {
                cout << groupn[j][i] << endl;
            }
            else
            {
                cout << groupn[j][i] << ' ';
            }
        }
    }
}

int main()
{
    int t;
    while (t--)
    {
        int group[6];
        int num;
        for(int i = 0;i < 6;i++)
        {
            cin >> group[i];
        }
        cin >> num;
        Lottery tem1(group, num);
        Lottery tem2 = tem1;
        tem2.print();
    }
    
}
