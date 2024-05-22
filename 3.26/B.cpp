#include <iostream>
using namespace std;
class Audio
{
    private:
    string category[4] = {"BF", "CD", "VCD", "DVD"};
    int type;
    string name;
    int price;
    bool state;
    int day;
    public:
    void get()
    {
        cin >> type >> name >> price >> state;
        cin >> day;
    }
    void print()
    {
        if (state == 1)
        {
            cout << category[type - 1] << '[' << name << "]rented\n";
            if (day != 0)
            {
                cout << "Rental: " << day * price << endl;
            }
        }
        else
        {
            cout << category[type - 1] << '[' << name << "]not rented\n";
            if (day != 0)
            {
                cout << "No rental" << endl;
            }
        }
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Audio temp;
        temp.get();
        temp.print();
    }
    return 0;
}