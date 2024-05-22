#include <iostream>
using namespace std;
struct Date
{
    int year;
    int month;
    int day;
    void get()
    {
        cin >> year >> month >> day;
    }
    void print()
    {
        cout << year << '-' << month << '-' << day << endl;
    }
}birthday[101];
void swapdate(Date &a, Date &b)
{
    int temy;
    int temm;
    int temd;
    temy = a.year;
    a.year = b.year;
    b.year = temy;
    temm = a.month;
    a.month = b.month;
    b.month = temm;
    temd = a.day;
    a.day = b.day;
    b.day = temd;
}
int main()
{
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        birthday[i].get();
    }
    for(int i = 1;i <= t;i++)
    {
        for(int j = 1;j <= t - i;j++)
        {
            if (birthday[j].year > birthday[j + 1].year)
            {
                swapdate(birthday[j], birthday[j + 1]);
            }
            else if (birthday[j].year == birthday[j + 1].year&&birthday[j].month > birthday[j + 1].month)
            {
                swapdate(birthday[j], birthday[j + 1]);
            }
            else if (birthday[j].year == birthday[j + 1].year&&birthday[j].month == birthday[j + 1].month&&birthday[j].day > birthday[j + 1].day)
            {
                swapdate(birthday[j], birthday[j + 1]);
            }
        }
    }
    for(int i = 1;i <= t;i++)
    {
        cout << i << ":";
        birthday[i].print();
    }
}