#include <iostream>
using namespace std;

class Clock {
private:
    int hour;
    int minute;
    int second;

public:
    Clock(int h, int m, int s) : hour(h), minute(m), second(s) {}
    Clock() : hour(0), minute(0), second(0) {}

    void print() const {
        cout << hour << ':' << minute << ':' << second << endl;
    }

    Clock& operator++() {
        ++second;
        if (second >= 60) {
            second -= 60;
            ++minute;
        }
        if (minute >= 60) {
            minute -= 60;
            ++hour;
        }
        if (hour >= 12) {
            hour -= 12;
        }
        return *this;
    }

    Clock operator--(int) {
        Clock temp = *this;
        --second;
        if (second < 0) {
            second += 60;
            --minute;
        }
        if (minute < 0) {
            minute += 60;
            --hour;
        }
        if (hour < 0) {
            hour += 12;
        }
        return temp;
    }
};

int main() {
    int h, m, s;
    cin >> h >> m >> s;
    Clock ans(h, m, s);
    int times;
    int t;
    cin >> t;
    while (t--) {
        cin >> times;
        if (times > 0) {
            for (int i = 0; i < times; ++i) {
                ++ans;
            }
            ans.print();
        } else if (times < 0) {
            for (int i = 0; i < -times; ++i) {
                ans--;
            }
            ans.print();
        }
    }
    return 0;
}
