#include <iostream>
using namespace std;

class Lottery
{
private:
    int group1[6];
    int num;
    int **groupn;

public:
    Lottery(int *group, int num);
    Lottery(const Lottery &other);
    ~Lottery()
    {
        for (int i = 0; i < num; i++)
        {
            delete[] groupn[i];
        }
        delete[] groupn;
    }
    void print();
};

Lottery::Lottery(int *g, int n)
{
    for (int i = 0; i < 6; i++)
    {
        group1[i] = g[i];
    }
    num = n;
    groupn = new int *[num];
    for (int i = 0; i < num; i++)
    {
        groupn[i] = new int[6];
    }
    for (int j = 0; j < num; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            if (i == 0)
            {
                groupn[j][i] = group1[5] + 1;
            }
            else
            {
                groupn[j][i] = group1[i - 1] + 1;
            }
        }
    }
}

Lottery::Lottery(const Lottery &other)
{
    groupn = new int *[other.num];
    for (int i = 0; i < other.num; i++)
    {
        groupn[i] = new int[6];
    }
    for (int i = 0; i < 6; i++)
    {
        group1[i] = other.group1[i];
    }
    for (int j = 0; j < other.num; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            if (i == 0)
            {
                groupn[j][i] = other.groupn[j][5] + 1;
            }
            else
            {
                groupn[j][i] = other.groupn[j][i - 1] + 1;
            }
        }
    }
}

void Lottery::print()
{
    for (int i = 0; i < 6; i++)
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
    for (int j = 0; j < num; j++)
    {
        for (int i = 0; i < 6; i++)
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
    int t = 1; // 初始化t
    while (t--)
    {
        int group[6];
        int num;
        for (int i = 0; i < 6; i++)
        {
            cin >> group[i];
        }
        cin >> num;
        Lottery tem1(group, num);
        Lottery tem2 = tem1;
        tem2.print();
    }
}
