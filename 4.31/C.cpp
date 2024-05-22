#include <iostream>
#include <string.h>
using namespace std;

int key[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char last[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

class CDate {
private:
    int year, month, day;

public:
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    
    CDate() : year(0), month(0), day(0) {}
    
    CDate(int Y, int M, int D) : year(Y), month(M), day(D) {}

    void print() {
        cout << " " << year << "年" << month << "月" << day << "日 ";
    }
};

class CStudentID {
private:
    char *p_id, *p_name; // 身份证号码，姓名
    CDate birthday;      // 出生日期
    int registered;      // 登记否
    string d = "";

public:
    CStudentID(char *p_idval, char *p_nameval, CDate &day) : registered(0) {
        p_id = new char[strlen(p_idval) + 1];
        strcpy(p_id, p_idval);
        p_name = new char[strlen(p_nameval) + 1];
        strcpy(p_name, p_nameval);
        birthday = day;
        cout << p_name;
        if (checkID() == true) {
            birthday.print();
            cout << p_id << endl;
            registered = 1;
        } else {
            cout << " illegal id\n";
            delete[] p_id;
            delete[] p_name;
        }
    }

    bool checkID() {
        if (strlen(p_id) != 15 && strlen(p_id) != 18) // id不是15位或18位
            return false;
        
        for (int i = 0; i < strlen(p_id); i++) { // id有非法字符
            if (!((p_id[i] >= '0' && p_id[i] <= '9') || p_id[i] == 'X'))
                return false;
        }
        
        if (strlen(p_id) == 18) { // id是18位但检验码不对
            int total = 0;
            int reminder;
            for (int i = 0; i < 17; i++)
                total += (p_id[i] - '0') * key[i];
            reminder = total % 11;
            if (last[reminder] != p_id[17])
                return false;
        }

        d += (char)(birthday.getYear() % 100) / 10 + '0';
        d += (char)(birthday.getYear() % 100) % 10 + '0';
        if (birthday.getMonth() < 10) {
            d += '0';
            d += (char)birthday.getMonth() + '0';
        } else {
            d += (char)(birthday.getMonth() / 10) + '0';
            d += (char)(birthday.getMonth() % 10) + '0';
        }
        if (birthday.getDay() < 10) {
            d += '0';
            d += (char)birthday.getDay() + '0';
        } else {
            d += (char)(birthday.getDay() / 10) + '0';
            d += (char)(birthday.getDay() % 10) + '0';
        }

        for (int i = 8; i <= 13; i++) { // 日期与id日期不符 ？？
            if ((i == 10 && birthday.getMonth() < 10) || (i == 12 && birthday.getDay() < 10))
                continue;
            if (p_id[i] != d[i - 8])
                return false;
        }
        return true;
    }

    CStudentID(const CStudentID &r) : registered(r.registered) {
        p_id = new char[strlen(r.p_id) + 4];
        strcpy(p_id, r.p_id);
        p_name = new char[strlen(r.p_name) + 1];
        strcpy(p_name, r.p_name);
        birthday = r.birthday;


        for (int i = 0, j = 0; i < 15; i++, j++) {
            if (i == 6) {
                p_id[6] = '1';
                p_id[7] = '9';
                j += 2;
            }
            p_id[j] = r.p_id[i];
        }

        int total = 0;
        int reminder;
        for (int i = 0; i < 17; i++)
            total += (p_id[i] - '0') * key[i];
        reminder = total % 11;
        p_id[17] = last[reminder];
        cout << p_name;
        birthday.print();
        cout << p_id << endl;
    }

    bool checked() { return registered; }

    ~CStudentID() {
        if (registered) {
            delete[] p_id;
            delete[] p_name;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int y, m, d;
        cin >> y >> m >> d;
        CDate birthday(y, m, d);
        char name[50], id[20];
        cin >> name >> id;
        CStudentID s(id, name, birthday);
        if (s.checked()) {
            CStudentID s_copy(s);
        }
    }
    return 0;
}
