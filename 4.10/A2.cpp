//头文件区域
#include <iostream>
using namespace std;
//填空区域1：类CDate的定义
/********** Write your code here! **********/

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

CDate::CDate(int Day, int Month, int Year) : year(Year), month(Month), day(Day) {}

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



/*******************************************/
//主函数区域
int main()
{	int a,b,c;
	cin>>a>>b>>c;
	CDate d1(a,b,c);
	CDate d2=d1;
	CDate d3(d2);
	d1.print();
	d2.print();
	d3.print();
	return 0;
}

