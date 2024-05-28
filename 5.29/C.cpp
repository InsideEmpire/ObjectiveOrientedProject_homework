#include <iostream>
#include <iomanip>
using namespace std;

#include <string>
#include <sstream>

class CDate {
private:
    int year, month, day;

public:
    CDate(int date = 0) {
        year = date / 10000;
        month = (date % 10000) / 100;
        day = date % 100;
    }

    operator int() const {
        return year * 10000 + month * 100 + day;
    }

    void Print() const {
        cout << year << "年" << setw(2) << setfill('0') << month << "月" << setw(2) << setfill('0') << day << "日" << endl;
    }

    bool operator>(const CDate& other) const {
        return static_cast<int>(*this) > static_cast<int>(other);
    }
};

/*******************************************/

// 主函数
int main() {
    int t, t1, t2;
    CDate C1, C2;
    cin >> t;
    while (t--) {
        cin >> t1 >> t2;
        C1 = t1;
        C2 = t2;
        ((C1 > C2) ? C1 : C2).Print(); // 日期大的输出
    }
    return 0;
}
