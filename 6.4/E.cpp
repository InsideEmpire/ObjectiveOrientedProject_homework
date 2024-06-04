#include <iostream>
#include <string>
using namespace std;

template <typename T>
class BoundArray {
public:
    T* arr;
    int n;

    BoundArray(int n) : n(n) {
        arr = new T[n];
    }

    void sort() {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    T temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    int search(T key) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        char type;
        int n;
        cin >> type >> n;
        switch (type) {
            case 'I': {
                BoundArray<int> ba(n);
                int key;
                for (int i = 0; i < n; i++) cin >> ba.arr[i];
                cin >> key;
                ba.sort();
                for (int i = 0; i < n; i++) cout << ba.arr[i] << " ";
                cout << "\n" << ba.search(key) << endl;
                break;
            }
            case 'D': {
                BoundArray<double> ba(n);
                double key;
                for (int i = 0; i < n; i++) cin >> ba.arr[i];
                cin >> key;
                ba.sort();
                for (int i = 0; i < n; i++) cout << ba.arr[i] << " ";
                cout << "\n" << ba.search(key) << endl;
                break;
            }
            case 'C': {
                BoundArray<char> ba(n);
                char key;
                for (int i = 0; i < n; i++) cin >> ba.arr[i];
                cin >> key;
                ba.sort();
                for (int i = 0; i < n; i++) cout << ba.arr[i] << " ";
                cout << "\n" << ba.search(key) << endl;
                break;
            }
        }
    }
    return 0;
}