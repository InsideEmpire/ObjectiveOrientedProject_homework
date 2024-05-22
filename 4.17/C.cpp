#include <iostream>
#include <cmath>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}

    int getHour() { return hour; }
    int getMinute() { return minute; }
    int getSecond() { return second; }

    friend int timeDifference(const Time* t1, const Time* t2);
};

int timeDifference(const Time* t1, const Time* t2) {
    int total_seconds1 = t1->hour * 3600 + t1->minute * 60 + t1->second;
    int total_seconds2 = t2->hour * 3600 + t2->minute * 60 + t2->second;
    return abs(total_seconds1 - total_seconds2);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int h1, m1, s1, h2, m2, s2;
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        Time* t1 = new Time(h1, m1, s1);
        Time* t2 = new Time(h2, m2, s2);
        int diff = timeDifference(t1, t2);
        cout << h1 << "时" << m1 << "分" << s1 << "秒--" << h2 << "时" << m2 << "分" << s2 << "秒时间差为" << diff << "秒" << endl;
        delete t1;
        delete t2;
    }

    return 0;
}
