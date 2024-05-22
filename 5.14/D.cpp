#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class CDate
{
protected:
    int year;
    int month;
    int day;

public:
    CDate() {}
    CDate(int Y, int M, int D) : year(Y), month(M), day(D) {}
    int duration(CDate &current)
    {
        int Y;
        int M;
        int D;
        Y = year - current.year;
        M = month - current.month;
        D = day - current.day;
        int last = 0;
        int days_in_month[] = {31, 28 + (year % 4 == 0 && year % 100 != 0 || year % 400 == 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (Y < 0 || (Y <= 0 && M < 0) || (Y <= 0 && M <= 0 && D < 0))
        {
            return -1;
        }
        else
        {
            if (M == 0)
            {
                return D + Y * 365;
            }
            else
            {
                for (int i = current.month - 1; i < month - 1; i++)
                {
                    last += days_in_month[i];
                }
                last += day;
                last -= current.day;
                return last + Y * 365;
            }
        }
    }
};

class Pet
{
protected:
    string name;   // 姓名
    float length;  // 身长
    float weight;  // 体重
    CDate current; // 开始记录时间

public:
    Pet(string n, float l, float w, CDate c) : name(n), length(l), weight(w), current(c) {}
    virtual void display(CDate day) = 0; // 输出目标日期时宠物的身长和体重
};

class Cat : public Pet
{
public:
    Cat(string n, float l, float w, CDate c) : Pet(n, l, w, c) {}
    void display(CDate day)
    {
        int last = day.duration(current);
        length += 0.1 * last;
        weight += 0.2 * last;
        if (last == -1)
        {
            cout << "error\n";
        }
        else
        {
            cout << fixed << setprecision(2) << name << " after " << last << " day: length=" << length << ",weight=" << weight << endl;
        }
    }
};

class Dog : public Pet
{
public:
    Dog(string n, float l, float w, CDate c) : Pet(n, l, w, c) {}
    void display(CDate day)
    {
        int last = day.duration(current);
        length += 0.2 * last;
        weight += 0.1 * last;
        if (last == -1)
        {
            cout << "error\n";
        }
        else
        {
            cout << fixed << setprecision(2) << name << " after " << last << " day: length=" << length << ",weight=" << weight << endl;
        }
    }
};

int main()
{
    int test_cases;
    cin >> test_cases;

    int start_year, start_month, start_day;
    cin >> start_year >> start_month >> start_day;
    CDate start_date(start_year, start_month, start_day);

    for (int i = 0; i < test_cases; ++i)
    {
        int type;
        string name;
        float length, weight;
        int year, month, day;

        cin >> type >> name >> length >> weight >> year >> month >> day;
        CDate last_date(year, month, day);

        Pet *pt;
        if (type == 1)
        {
            Cat *cat = new Cat(name, length, weight, start_date);
            pt = cat;
        }
        else if (type == 2)
        {
            Dog *dog = new Dog(name, length, weight, start_date);
            pt = dog;
        }

        pt->display(last_date);
    }

    return 0;
}
