#include <iostream>
using namespace std;
struct Students
{
    string ID;
    string name;
    int a, b, c;
    int sum = 0;
    void get()
    {
        cin >> ID >> name >> a >> b >> c;
        sum = a + b + c;
    }
    void print()
    {
        cout << name << ' ' << ID << ' ' << sum << endl;
    }
}student[11];

int main()
{
    int t;
    cin >> t;
    int bok = 0;
    int cnt;
    for(int i = 1;i <= t;i++)
    {
        student[i].get();
        if (student[i].sum > bok)
        {
            bok = student[i].sum;
            cnt = i;
        }
        
    }
    student[cnt].print();
}