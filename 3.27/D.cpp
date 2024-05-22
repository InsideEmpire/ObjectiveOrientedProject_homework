#include <iostream>
#include <iomanip>
using namespace std;
class Cat
{
    private:
    string name;
    int year;
    char t;
    int month;
    int day;
    float score;
    public:
    void get()
    {
        cin >> name >> year >> t >> month >> t >> day >> score;
    }
    void print()
    {
        cout << " name:" << name << " birthday:" << year << '_' << month << '_' << day << " score:" << fixed << setprecision(1) << score << endl;
    }
};
int main()
{
    int n, bok = 0;
    cin >> n;
    Cat *cats = new Cat[n + 1];
    for(int i = 0;i < n;i++)
    {
        int tem;
        cin >> tem;
        if (tem > bok)
        {
            bok = tem;
        }
        
        cats[tem].get();
    }
    for(int i = 1;i <= bok;i++)
    {
        cout << "id:" << setw(4) << setfill('0') << i;
        cats[i].print();
    }
    return 0;
}