#include <iostream>

using namespace std;

struct Team {
    int id;
    int solved;
};

void mySwap(Team &a, Team &b) {
    Team temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    cin >> n;

    Team teams[n];
    for (int i = 0; i < n; ++i) {
        cin >> teams[i].id >> teams[i].solved;
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (teams[j].solved < teams[j + 1].solved) {
                mySwap(teams[j], teams[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << teams[i].id << " " << teams[i].solved << endl;
    }

    return 0;
}
