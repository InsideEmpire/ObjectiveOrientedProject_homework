#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct Merchant {
    string name;
    string terminal;
    string operator_id;
    string card_issuer;
    string validity;
    string card_number;
    string trade_date;
    double cost;
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; ++i) {
        Merchant merchant;
        cin >> merchant.name;
        cin >> merchant.terminal;
        cin >> merchant.operator_id;
        cin >> merchant.card_issuer;
        cin >> merchant.validity;
        cin >> merchant.card_number;
        cin >> merchant.trade_date;
        cin >> merchant.cost;
        cin.ignore();

        cout << "Name: " << merchant.name << endl;
        cout << "Terminal: " << merchant.terminal << " operator: " << merchant.operator_id << endl;
        cout << "Card Issuers: " << merchant.card_issuer << " Validity: " << merchant.validity << endl;
        cout << "CardNumber: " << merchant.card_number.substr(0, 4) << "********" << merchant.card_number.substr(12, 4) << endl;
        cout << "Traded: " << merchant.trade_date << endl;
        cout << "Costs: $" << fixed << setprecision(2) << merchant.cost << endl;
        cout << endl;
    }

    return 0;
}
