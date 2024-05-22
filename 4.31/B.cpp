#include <iostream>
using namespace std;
class Date
{
private:
    int year;
    int month;
    int day;
public:
    void get()
    {
        cin >> year >> month >> day;
    }
    Date()
    {
        year = 0;
        month = 0;
        day = 0;
    }
    Date(int Y, int M, int D):year(Y),month(M),day(D){}
    bool ifMonth(Date &thisMonth)
    {
        if (this->month == thisMonth.month)
        {
            return true;
        }
        return false;
    }
    bool ifDay(Date &thisDay)
    {
        if (this->day == thisDay.day)
        {
            return true;
        }
        return false;
    }
};
class VIP
{
private:
    int consumption;
    Date birthday;
    int id;
    double discount = 0.95;
public:
    VIP()
    {
        cin >> id;
        birthday.get();
        cin >> consumption;
    }
    void ifBirthday(Date &today)
    {
        if (birthday.ifDay(today) && birthday.ifMonth(today))
        {
            discount = 0.5;
        }
        
    }
    void printVIP()
    {
        cout << id << "'s consumption is " << int(consumption * discount) << endl;
    }
};
int main()
{
    
    int y, m, d;
    cin >> y >> m >> d;
    Date today(y, m, d);
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        VIP p;
        p.ifBirthday(today);
        p.printVIP();
    }
}