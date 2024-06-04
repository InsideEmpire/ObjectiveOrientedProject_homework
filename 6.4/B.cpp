#include <iostream>
#include <string>
using namespace std;

template <typename T>
int findIndex(T arr[], int n, T key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i + 1;
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        char type;
        int n;
        cin >> type >> n;
        switch (type) {
            case 'I': {
                int arr[n], key;
                for (int i = 0; i < n; i++) cin >> arr[i];
                cin >> key;
                cout << findIndex(arr, n, key) << endl;
                break;
            }
            case 'D': {
                double arr[n], key;
                for (int i = 0; i < n; i++) cin >> arr[i];
                cin >> key;
                cout << findIndex(arr, n, key) << endl;
                break;
            }
            case 'C': {
                char arr[n], key;
                for (int i = 0; i < n; i++) cin >> arr[i];
                cin >> key;
                cout << findIndex(arr, n, key) << endl;
                break;
            }
            case 'S': {
                string arr[n], key;
                for (int i = 0; i < n; i++) cin >> arr[i];
                cin >> key;
                cout << findIndex(arr, n, key) << endl;
                break;
            }
        }
    }
    return 0;
}