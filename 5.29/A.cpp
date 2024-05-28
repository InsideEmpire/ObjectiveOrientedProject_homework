#include <iostream>
#include <string>
using namespace std;

class IDCard {
private:
    string id;

public:
    IDCard(const string &id_str) : id(id_str) {}

    friend ostream& operator<<(ostream& out, const IDCard& id_card) {
        string year = id_card.id.substr(6, 4);
        string month = id_card.id.substr(10, 2);
        string day = id_card.id.substr(12, 2);


        out << "year=" << year << " month=" << month << " day=" << day << " sex=" << ((id_card.id[16] % 2 == 1) ? "男" : "女") << endl;
        return out;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string id_str;
        cin >> id_str;
        IDCard id_card(id_str);
        cout << id_card;
    }
    return 0;
}
