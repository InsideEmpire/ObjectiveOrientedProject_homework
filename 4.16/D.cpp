#include <iostream>
#include <iomanip>
using namespace std;
class CDate;
class CTime;
void Display(CDate &D, CTime &T);
class CDate
{
    friend void Display(CDate &, CTime &);

private:
    int year;
    int month;
    int day;

public:
    CDate(int y, int m, int d):year(y),month(m),day(d){}
};
class CTime
{
    friend void Display(CDate &, CTime &);

private:
    int hour;
    int minute;
    int second;

public:
    CTime(int h, int m, int s):hour(h),minute(m),second(s){}
};
void Display(CDate &D, CTime &T)
{
    cout << D.year << '-' << setfill('0') << setw(2) << D.month << '-' << setfill('0') << setw(2) << D.day << ' ';
    cout << setfill('0') << setw(2) << T.hour << ':' << setfill('0') << setw(2) << T.minute << ":" << setfill('0') << setw(2) << T.second << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int year, month, day, hour, minute, second;
        cin >> year >> month >> day;
        cin >> hour >> minute >> second;
        CDate tem1(year, month, day);
        CTime tem2(hour, minute, second);
        Display(tem1, tem2);
    }
    
}