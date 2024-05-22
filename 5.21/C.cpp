#include <iostream>
using namespace std;

class Student
{
    friend int operator-(Student a, Student b);
private:
    
    string name;
    int year;
    int month;
    int day;
public:
    Student(string n, int y, int m, int d):name(n),year(y),month(m),day(d){}
    Student()
    {
        name = "NULL";
        year = 0000;
        month = 0;
        day = 0;
    }
    string get_name()
    {
        return name;
    }
};
int operator-(Student a, Student b)
{
    // int days_in_month[] = {31, 28 + (a.year % 4 == 0 && a.year % 100 != 0 || a.year % 400 == 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // int total_days = 0;
    // total_days += (a.year - b.year) * 365 + (a.year % 4 == 0 && a.year % 100 != 0 || a.year % 400 == 0);
    // total_days += 
    int Y;
        int M;
        int D;
        Y = a.year - b.year;
        M = a.month - b.month;
        D = a.day - b.day;
        int last = 0;
        int days_in_month[] = {31, 28 + (a.year % 4 == 0 && a.year % 100 != 0 || a.year % 400 == 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (Y < 0 || (Y <= 0 && M < 0) || (Y <= 0 && M <= 0 && D < 0))
        {
            return b - a;
        }
        else
        {
            if (M == 0)
            {
                return D + Y * 365;
            }
            else
            {
                for (int i = b.month - 1; i < a.month - 1; i++)
                {
                    last += days_in_month[i];
                }
                last += a.day;
                last -= b.day;
                return last + Y * 365;
            }
        }
}
int main()
{
    int t;
    cin >> t;
    Student *list = new Student[t];
    for(int i = 0;i < t;i++)
    {
        string name;
        int y, m, d;
        cin >> name >> y >> m >> d;
        list[i] = Student(name, y, m, d);
    }
    string n1, n2;
    int longest = 0;
    for(int i = 0;i < t;i++)
    {
        for(int j = 0;j < t - i;j++)
        {
            if (list[i] - list[j] > longest)
            {
                n1 = list[i].get_name();
                n2 = list[j].get_name();
                longest = list[i] - list[j];
            }
            
        }
    }
    cout << n1 << "和" << n2 << "年龄相差最大，为" << longest << "天。";
}