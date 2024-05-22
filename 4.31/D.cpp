#include <iostream>
using namespace std;

class CDate {
private:
    int year, month, day;

public:
    CDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    int getYear() {
        return year;
    }

    int getMonth() {
        return month;
    }

    int getDay() {
        return day;
    }

    int getDayofYear() {
        int i, sum = day;
        int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int b[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (isLeapYear()) {
            for (i = 0; i < month; i++)
                sum += b[i];
        } else {
            for (i = 0; i < month; i++)
                sum += a[i];
        }

        return sum;
    }
};

class Software {
private:
    string name;
    char type;
    char media;
    CDate expirationDate;

public:
    Software(string n, char t, char m, CDate expDate)
        : name(n), type(t), media(m), expirationDate(expDate) {}

    Software(const Software &software)
        : name(software.name), type('B'), media('H'), expirationDate(software.expirationDate) {}

    int daysUntilExpiration() {
        CDate currentDate(2015, 4, 7);
        int daysLeft = expirationDate.getDayofYear() - currentDate.getDayofYear();

        if (expirationDate.getYear() == 0 && expirationDate.getMonth() == 0 && expirationDate.getDay() == 0) {
            cout << "this software has unlimited use" << endl;
        } else if (expirationDate.getYear() < 2015 || (expirationDate.getYear() == 2015 && expirationDate.getMonth() < 4) ||
                   (expirationDate.getYear() == 2015 && expirationDate.getMonth() == 4 && expirationDate.getDay() < 7)) {
            cout << "this software has expired" << endl;
        } else {
            cout << "this software is going to be expired in " << daysLeft << " days" << endl;
        }

        return daysLeft;
    }

    void printInfo() {
        cout << "name:" << name << endl;
        cout << "type:";
        switch (type) {
            case 'O':
                cout << "original" << endl;
                break;
            case 'T':
                cout << "trial" << endl;
                break;
            case 'B':
                cout << "backup" << endl;
                break;
        }
        cout << "media:";
        switch (media) {
            case 'D':
                cout << "optical disk" << endl;
                break;
            case 'H':
                cout << "hard disk" << endl;
                break;
            case 'U':
                cout << "USB disk" << endl;
                break;
        }
        daysUntilExpiration();
        cout << endl;
    }
};

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        string name;
        char type, media;
        int year, month, day;
        cin >> name >> type >> media >> year >> month >> day;

        CDate expDate(year, month, day);
        Software software(name, type, media, expDate);
        software.printInfo();

        Software copy(software);
        copy.printInfo();
    }

    return 0;
}
