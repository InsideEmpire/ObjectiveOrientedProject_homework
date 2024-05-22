#include <iostream>
using namespace std;

void find(int *num, int n, int &minIndex, int &maxIndex) {
    minIndex = 0;
    maxIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (num[i] < num[minIndex]) {
            minIndex = i;
        }
        if (num[i] > num[maxIndex]) {
            maxIndex = i;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int *num = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }

        int minIndex, maxIndex;
        find(num, n, minIndex, maxIndex);
        cout << "min=" << num[minIndex] << " minindex=" << minIndex << endl;
        cout << "max=" << num[maxIndex] << " maxindex=" << maxIndex << endl;

        delete[] num;

        if (t > 0) {
            cout << endl;
        }
    }

    return 0;
}
