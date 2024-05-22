#include <iostream>
using namespace std;

class Vector {
private:
    int vec[5];

public:
    Vector(int v[]) {
        for (int i = 0; i < 5; ++i) {
            vec[i] = v[i];
        }
    }

    Vector() {
        for (int i = 0; i < 5; ++i) {
            vec[i] = 0;
        }
    }

    Vector(const Vector& obj) {
        for (int i = 0; i < 5; ++i) {
            vec[i] = obj.vec[i];
        }
    }

    Vector operator+(const Vector& obj) {
        Vector result;
        for (int i = 0; i < 5; ++i) {
            result.vec[i] = vec[i] + obj.vec[i];
        }
        return result;
    }

    Vector operator-(const Vector& obj) {
        Vector result;
        for (int i = 0; i < 5; ++i) {
            result.vec[i] = vec[i] - obj.vec[i];
        }
        return result;
    }

    void print() {
        for (int i = 0; i < 5; ++i) {
            cout << vec[i];
            if (i < 4) cout << " ";
        }
        cout << ' ' <<  endl;
    }
};

int main() {
    int v1[5], v2[5];

    for (int i = 0; i < 5; ++i) {
        cin >> v1[i];
    }

    for (int i = 0; i < 5; ++i) {
        cin >> v2[i];
    }

    Vector vec1(v1);
    Vector vec2(v2);

    Vector vecAdd = vec1 + vec2;
    Vector vecSub = vec1 - vec2;

    vecAdd.print();
    vecSub.print();

    return 0;
}
