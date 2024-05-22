//头文件和类声明
#include <iostream>
using namespace std;

class MyDate {
private:
	int year;
	int month;
	int day;
public:
	MyDate(); //无参构造，默认日期2022-4-1，输出相关构造信息
	MyDate(int ty, int tm, int td); //有参构造，根据参数初始化，输出相关构造信息
	~MyDate(); 
	bool Before(MyDate &rd);
	void print()
	{ cout<<year<<"-"<<month<<"-"<<day; }
};
//下面填写类实现和主函数
/********** Write your code here! **********/
MyDate::MyDate()
{
    year = 2022;
    month = 4;
    day = 1;
    cout << "Date 2022-4-1 default constructed" << endl;
}
MyDate::MyDate(int ty, int tm, int td):year(ty),month(tm),day(td)
{
    cout << "Date " << year << '-' << month << '-' << day << " constructed\n";
}
MyDate::~MyDate()
{
    cout << "Date " << year << '-' << month << '-' << day << " destructed\n";
}
bool MyDate::Before(MyDate &rd)
{
    if (year > 2022)
    {
        return true;
    }
    else if (year < 2022)
    {
        return false;
    }
    if (month > 4)
    {
        return true;
    }
    else if (month < 4)
    {
        return false;
    }
    if (day > 1)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    MyDate rd;
    for(int i = 0;i < n;i++)
    {
        int y, m, d;
        cin >> y >> m >> d;
        MyDate tem(y, m, d);
        if (tem.Before(tem))
        {
            rd.print();
            cout << " before ";
            tem.print();
            cout << endl;
        }
        else
        {
            tem.print();
            cout << " before ";
            rd.print();
            cout << endl;
        }
    }
}
/*******************************************/
//main end 