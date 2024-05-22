#include <iostream>
using namespace std;

class Date
{
private:
    int year, month, day;

public:
    Date();
    Date(int year, int month, int day);
    void setDate(int year, int month, int day);
    bool isLeapYear();
    void nextDay();
    void printDate();
};

Date::Date() : year(1990), month(1),day(1) {}

Date::Date(int Year, int Month, int Day) : year(Year), month(Month), day(Day) {}

void Date::setDate(int Year, int Month, int Day)
{
    year = Year;
    month = Month;
    day = Day;
}

bool Date::isLeapYear()
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Date::nextDay()
{
    if (month == 2)
    {
        if (isLeapYear() && day == 28)
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

void Date::printDate()
{
    cout << year << "/" << (month < 10 ? "0" : "") << month << "/" << (day < 10 ? "0" : "") << day << endl;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int year, month, day;
        cin >> year >> month >> day;

        Date date(year, month, day);

        cout << "Today is ";
        date.printDate();

        date.nextDay();

        cout << "Tomorrow is ";
        date.printDate();
    }

    return 0;
}
