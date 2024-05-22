//头文件和日期类声明
#include<iostream>
#include<iomanip>
using namespace std;
 
class TDate {
private:
    int year,month,day;
public:
    int getYear(){return year;}
    int getMonth(){return month;}
    int getDay(){return day;}
    void set(int y,int m,int d);
    void print();
    void addOneDay();
};

//----在以下区域完成部分成员函数的类外定义----
/********** Write your code here! **********/
void TDate::set(int y,int m,int d)
{
    year = y;
    month = m;
    day = d;
}
void TDate::print()
{
    if (month >= 10)
    {
        if (day >= 10)
        {
            cout << year << month << day;
        }
        else
        {
            cout << year << month << '0' << day;
        }
    }
    else
    {
        if (day >= 10)
        {
            cout << year << '0' << month << day;
        }
        else
        {
            cout << year << '0' << month << '0' << day;
        }
    }
}
void TDate::addOneDay()
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
    {
        if (month == 2)
        {
            if (day == 29)
            {
                month++;
                day = 1;
            }
            else
            {
                day++;
            }
            
        }
        else if(month == 1||month == 3||month == 5||month == 7||month == 8||month == 10)
        {
            if (day == 31)
            {
                month++;
                day = 1;
            }
            else
            {
                day++;
            }
        }
        else if (month == 12)
        {
            if (day == 31)
            {
                year++;
                month = 1;
                day = 1;
            }
            else
            {
                day++;
            }
        }
        else
        {
            if (day == 30)
            {
                month++;
                day = 1;
            }
            else
            {
                day++;
            }
        }
    } 
    else 
    {
        if (month == 2)
        {
            if (day == 28)
            {
                month++;
                day = 1;
            }
            
        }
        else if(month == 1||month == 3||month == 5||month == 7||month == 8||month == 10)
        {
            if (day == 31)
            {
                month++;
                day = 1;
            }
            else
            {
                day++;
            }
        }
        else if (month == 12)
        {
            if (day == 31)
            {
                year++;
                month = 1;
                day = 1;
            }
            else
            {
                day++;
            }
        }
        else
        {
            if (day == 30)
            {
                month++;
                day = 1;
            }
            else
            {
                day++;
            }
        }
    }
}

/*******************************************/
//主函数如下
int main()
{   int t, y,m,d;
    cin>>t;
    while(t--)
    {	TDate d1;
		cin>>y>>m>>d;
		d1.set(y, m, d);
        cout<<"Today-";
        d1.print();
        d1.addOneDay();
        cout<<" Tomorrow-";
        d1.print();
		cout<<endl;
    }
    return 0;
}
