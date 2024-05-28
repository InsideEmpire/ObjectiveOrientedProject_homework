#include <iostream>
using namespace std;

class CSet {
private:
    int n;
    int *data;

public:
    CSet() : n(0), data(nullptr) {}
    CSet(int num) : n(num) {
        data = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> data[i];
        }
    }

    void set(int num, int array[]) {
        n = num;
        data = new int[n];
        for (int i = 0; i < n; ++i) {
            data[i] = array[i];
        }
    }

    friend ostream& operator<<(ostream &cout, const CSet &uni);

    friend CSet operator+(const CSet &A, const CSet &B);

    friend CSet operator-(const CSet &A, const CSet &B);

    friend CSet operator*(const CSet &A, const CSet &B);
};

ostream& operator<<(ostream &cout, const CSet &uni) {
    for (int i = 0; i < uni.n - 1; ++i) {
        cout << uni.data[i] << ' ';
    }
    cout << uni.data[uni.n - 1] << endl;
    return cout;
}

CSet operator+(const CSet &A, const CSet &B) {
    CSet result;
    int total = 0;
    int *array = new int[A.n + B.n];

    for (int i = 0; i < A.n; ++i) {
        array[total++] = A.data[i];
    }

    for (int i = 0; i < B.n; ++i) {
        bool isOverlap = false;
        for (int j = 0; j < A.n; ++j) {
            if (A.data[j] == B.data[i]) {
                isOverlap = true;
                break;
            }
        }
        if (!isOverlap) {
            array[total++] = B.data[i];
        }
    }

    result.set(total, array);
    return result;
}

CSet operator-(const CSet &A, const CSet &B) {
    CSet result;
    int total = 0;
    int *array = new int[A.n];

    bool *isSkip = new bool[A.n]{false};
    for (int i = 0; i < B.n; ++i) {
        for (int j = 0; j < A.n; ++j) {
            if (A.data[j] == B.data[i]) {
                isSkip[j] = true;
            }
        }
    }

    for (int i = 0; i < A.n; ++i) {
        if (!isSkip[i]) {
            array[total++] = A.data[i];
        }
    }

    result.set(total, array);
    delete[] isSkip;
    return result;
}

CSet operator*(const CSet &A, const CSet &B) {
    CSet result;
    int total = 0;
    int *array = new int[A.n];

    for (int i = 0; i < A.n; ++i) {
        for (int j = 0; j < B.n; ++j) {
            if (A.data[i] == B.data[j]) {
                array[total++] = A.data[i];
                break;
            }
        }
    }

    result.set(total, array);
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a;
        CSet A(a);
        cin >> b;
        CSet B(b);

        cout << "A:";
        cout << A;

        cout << "B:";
        cout << B;

        cout << "A+B:";
        cout << (A + B);

        cout << "A*B:";
        cout << (A * B);

        cout << "(A-B)+(B-A):";
        cout << (A - B) + (B - A);

        cout << endl;
    }

    return 0;
}
