#include <iostream>
using namespace std;

class Vector {
private:
    int *elements;
    int size;

public:
    Vector(int arr[], int n) {
        size = n;
        elements = new int[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = arr[i];
        }
    }

    ~Vector() {
        delete[] elements;
    }

    Vector operator+(const Vector &other) const {
        Vector result(elements, size);
        for (int i = 0; i < size; ++i) {
            result.elements[i] += other.elements[i];
        }
        return result;
    }

    Vector operator-(const Vector &other) const {
        Vector result(elements, size);
        for (int i = 0; i < size; ++i) {
            result.elements[i] -= other.elements[i];
        }
        return result;
    }

    friend ostream& operator<<(ostream &out, const Vector &vec) {
        for (int i = 0; i < vec.size - 1; ++i) {
            out << vec.elements[i] << " ";
        }
        out << vec.elements[vec.size - 1];
        return out;
    }
};

int main() {
    int data1[10], data2[10];
    
    for (int &val : data1) {
        cin >> val;
    }
        for (int &val : data2) {
        cin >> val;
    }
    Vector vec1(data1, 10), vec2(data2, 10);
    Vector sum = vec1 + vec2;
    cout << sum << endl;
    Vector diff = vec1 - vec2;
    cout << diff << endl;

    return 0;
}
