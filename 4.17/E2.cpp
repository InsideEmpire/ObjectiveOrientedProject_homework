#include <iostream>
using namespace std;

class CCow {
public:
    int age;
    bool sat;

public:
    static int TotalNum;
    CCow() {
        age = 0;
        sat = false;
    }
    void set() {
        age = 1;
        sat = true;
    }
    void passYear(const CCow &a) {
        age = a.age + 1;
        sat = true;
        if (age >= 10) {
            sat = false; // 母牛死亡
            TotalNum--; // 总数减一
        }
    }
    bool isAlive() {
        return sat;
    }
};

int CCow::TotalNum = 1;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int year;
        cin >> year;
        //year++;
        CCow **p = new CCow *[year + 1]; // 创建动态数组

        for (int i = 0; i <= year; i++) {
            p[i] = new CCow[28365]; // 创建每年的母牛数组
        }

        p[1][1].set(); // 初始时有一头母牛

        for (int i = 1; i <= year; i++) {
            for (int j = 1; j <= CCow::TotalNum; j++) {
                if (p[i][j].isAlive()) {
                    p[i + 1][j].passYear(p[i][j]); // 过一年
                    if (p[i][j].isAlive() && p[i][j].age >= 4) {
                        p[i + 1][++CCow::TotalNum].set(); // 新生母牛
                        //CCow::TotalNum++;
                    }
                }
            }
        }

        cout << CCow::TotalNum << endl;

        // 释放内存
        for (int i = 0; i <= year; i++) {
            delete[] p[i];
        }
        delete[] p;
    }

    return 0;
}
