#include <iostream>
#include <iomanip>
using namespace std;
class CDate
{
private:
    int year, month, day;
public:
    CDate():year(0),month(0),day(0){}
    CDate(int str)
    {
        year = str / 10000;
        str %= 10000;
        month = str / 100;
        str %= 100;
        day = str;
    }
    operator int() const {
        return year * 10000 + month * 100 + day;
    }

    void Print() const {
        cout << setw(4) << setfill('0') << year << "年"
             << setw(2) << setfill('0') << month << "月"
             << setw(2) << setfill('0') << day << "日" << endl;
    }
};
int main()
{
    int t, t1, t2;
    CDate C1, C2;
    cin >> t;
    while (t--)
    {
        cin >> t1 >> t2;
        C1 = t1;
        C2 = t2;
        ((C1 > C2) ? C1 : C2).Print(); // 日期大的输出，在代码C1>C2中，会自动把C1和C2转换为整数进行比较
    }
    return 0;
}