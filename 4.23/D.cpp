#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Time
{
protected:
    int hour, minute, second;
};
class Time_12hours : Time
{
public:
    int type;
    bool d;
    int num;
    char interval[5] = { 'A', 'M', 'P', 'M' };
    void get(int t, int h, int m, int s, bool D, int n)
    {
        type = t;
        hour = h;
        minute = m;
        second = s;
        d = D;
        num = n;
        if (d == 1)
        {
            while (n--)
            {
                add();
            }
            if (type == 121)
            {
                cout << "AM " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << endl;
            }
            else
            {
                cout << "PM " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << endl;
            }
        }
        else
        {
            while (n--)
            {
                minus();
            }
            if (type == 121)
            {
                cout << "AM " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << endl;
            }
            else
            {
                cout << "PM " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << endl;
            }
        }
    }
    void add()
    {
        second++;
        if (second == 60)
        {
            second = 0;
            minute++;
        }
        if (minute == 60)
        {
            minute = 0;
            hour++;
        }
        if (hour == 12)
        {
            hour = 0;
            if (type == 121)
            {
                type = 122;
            }
            else
            {
                type = 121;
            }
        }
    }
    void minus()
    {
        second--;
        if (second == -1)
        {
            second = 59;
            minute--;
        }
        if (minute == -1)
        {
            minute = 59;
            hour--;
        }
        if (hour == -1)
        {
            hour = 11;
            if (type == 121)
            {
                type = 122;
            }
            else
            {
                type = 121;
            }
        }   
    }
};
int main()
{
    int type;
    cin >> type;
    while (type != 0)
    {
        int h, m, s, N;
        bool D;
        char d;
        cin >> h >> m >> s >> d >> N;
        if (d == '-')
        {
            D = 0;
        }
        else
        {
            D = 1;
        }
        Time_12hours tem;
        tem.get(type, h, m, s, D, N);
        cin >> type;
    }
    
}