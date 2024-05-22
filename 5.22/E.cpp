#include <iostream>
#include <cstring> 
#include <string.h>
using namespace std;

class str {
    char *p;

public:
    str() {
        p = nullptr;
    }

    str(const char *s) {
        p = new char[strlen(s) + 1];
        strcpy(p, s);
    }

    ~str() {
        delete[] p;
    }

    str(const str &s) {
        p = new char[strlen(s.p) + 1];
        strcpy(p, s.p);
    }

    str& operator=(const str &s) {
        if (this == &s) {
            return *this;
        }
        delete[] p;
        p = new char[strlen(s.p) + 1];
        strcpy(p, s.p);
        return *this;
    }

    bool operator>(const str &b) const {
        if (strcmp(p, b.p) > 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool operator<(const str &c) const {
        if (strcmp(p, c.p) < 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool operator==(const str &c) const {
        if (strcmp(p, c.p) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void show() const {
        cout << p;
    }
};

int main() {
    char A[100];
    char B[100];
    char C[100];

    //cin >> A >> B >> C;
    cin.getline(A, 100);
    cin.getline(B, 100);
    cin.getline(C, 100);

    str a(A);
    str b(B);
    str c(C);

    if (a > b) {
        a.show();
    } else {
        b.show();
    }
    cout << endl;

    if (a < c) {
        a.show();
    } else {
        c.show();
    }
    cout << endl;

    if (b == c) {
        b.show();
    } else {
        c.show();
    }
    cout << endl;

    return 0;
}
