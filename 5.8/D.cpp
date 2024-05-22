#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
protected:
    int year;
    int month;
    int day;

public:
    Date(int _year, int _month, int _day) : year(_year), month(_month), day(_day) {}
    bool before(const Date &other) const
    {
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        return day < other.day;
    }
    void display() const
    {
        cout << year << "/" << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day;
    }
};

class Time
{
protected:
    int hour;
    int minute;
    int second;

public:
    Time(int _hour, int _minute, int _second) : hour(_hour), minute(_minute), second(_second) {}
    bool before(const Time &other) const
    {
        if (hour != other.hour)
            return hour < other.hour;
        if (minute != other.minute)
            return minute < other.minute;
        return second < other.second;
    }
    void display() const
    {
        cout << setw(2) << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second;
    }
};

class Schedule : public Date, public Time
{
private:
    int ID;

public:
    Schedule(int _ID, int _year, int _month, int _day, int _hour, int _minute, int _second)
        : Date(_year, _month, _day), Time(_hour, _minute, _second), ID(_ID) {}
    friend bool before(const Schedule &s1, const Schedule &s2);
    void display() const
    {
        cout << "The urgent schedule is No." << ID << ": ";
        Date::display();
        cout << " ";
        Time::display();
        cout << endl;
    }
};

bool before(const Schedule &s1, const Schedule &s2)
{
    if (s1.Date::before(s2) || (s1.Date::year == s2.Date::year && s1.Date::month == s2.Date::month && s1.Date::day == s2.Date::day && s1.Time::before(s2)))
        return true;
    return false;
}

int main()
{
    int ID, year, month, day, hour, minute, second;
    Schedule earliest(0, 9999, 9999, 9999, 9999, 9999, 9999);

    while (true)
    {
        cin >> ID;
        if (ID == 0)
            break;
        cin >> year >> month >> day >> hour >> minute >> second;
        Schedule current(ID, year, month, day, hour, minute, second);
        if (before(current, earliest))
            earliest = current;
    }

    earliest.display();

    return 0;
}
