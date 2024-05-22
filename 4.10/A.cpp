#include <iostream>
using namespace std;

class CDate
{
private:
    int year, month, day;

public:
    CDate();
    CDate(int year, int month, int day);
    void setCDate(int year, int month, int day);
    bool isLeapYear();
    CDate(CDate &past);
    void print();
};

CDate::CDate() : year(1990), month(1),day(1) {}

CDate::CDate(int Year, int Month, int Day) : year(Year), month(Month), day(Day) {}

void CDate::setCDate(int Year, int Month, int Day)
{
    year = Year;
    month = Month;
    day = Day;
}

bool CDate::isLeapYear()
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

CDate::CDate(CDate &past)
{
    year = past.year;
    month = past .month;
    day = past.day;
    if (past.month == 2)
    {
        if (past.isLeapYear() && past.day == 28)
        {
            day++;
        }
        else if (day == 29)
        {
            day = 1;
            month++;
        }
        else if (day == 28)
        {
            day = 1;
            month++;
        }
        else
        {
            day++;
        }
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30)
    {
        day = 1;
        month++;
    }
    else if (day == 31)
    {
        if (month == 12)
        {
            year++;
            month = 1;
        }
        else
        {
            month++;
        }
        day = 1;
    }
    else
    {
        day++;
    }
}

void CDate::print()
{
    cout << year << "/" << month << "/" << day << endl;
}

int main()
{

        int year, month, day;
        cin >> day >> month >> year;

        CDate CDate(year, month, day);
        CDate.print();
        CDate CDate2(CDate);
        CDate2.print();
        CDate CDate3(CDate2);
        CDate3.print();

    return 0;
}
