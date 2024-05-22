#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Health
{
    private:
    string name;
    double height;
    double weight;
    double waist;
    public:
    void get()
    {
        cin >> name >> height >> weight >> waist;
    }
    void print()
    {
        double a = waist * 0.74;
        double b = weight * 0.082 + 34.89;
        cout << name << "'s BMI: " << fixed << setprecision(0) << round(weight / (height * height)) << "--BFR: " << fixed << setprecision(2) << (a - b) / weight << endl;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Health temp;
        temp.get();
        temp.print();
    }
    return 0;
}