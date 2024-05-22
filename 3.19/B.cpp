#include <iostream>
using namespace std;
class Date
{
    public:
    int day;
    int month;
    int year;
    
    void get()
    {
        cin >> year >> month >> day;
    }
    void print()
    {
        cout << year <<'-'<< month <<'-'<< day;
    }
}student[101];

int main()
{
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        student[i].get();
    }
    int minn;
    int y1 = 9999, y2 = 9999, m1 = 9999, m2 = 9999, d1 = 9999, d2 = 9999;
    for(int i = 1;i <= t;i++)
    {
        if (student[i].year < y1)
        {
            y1 = student[i].year;
            m1 = student[i].month;
            d1 = student[i].day;
            
        }
        else if (student[i].year == y1&&student[i].month < m1)
        {
            m1 = student[i].month;
            d1 = student[i].day;
        }
        else if (student[i].year == y1&&student[i].month == m1&&student[i].day < d1)
        {
            d1 = student[i].day;
        }
    }
    for(int i = 1;i <= t;i++)
    {
        if (student[i].year == y1&&student[i].month == m1&&student[i].day == d1)
        {
            continue;
        }
        
        if (student[i].year < y2)
        {
            y2 = student[i].year;
            m2 = student[i].month;
            d2 = student[i].day;
            
        }
        else if (student[i].year == y2&&student[i].month < m2)
        {
            m2 = student[i].month;
            d2 = student[i].day;
        }
        else if (student[i].year == y2&&student[i].month == m2&&student[i].day < d2)
        {
            d2 = student[i].day;
        }
    }
    for(int i = 1;i <= t;i++)
    {
        if (student[i].year == y2&&student[i].month == m2&&student[i].day == d2)
        {
            student[i].print();
        }
        
    }
}