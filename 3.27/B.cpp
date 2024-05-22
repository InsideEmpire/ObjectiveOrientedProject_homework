#include <iostream>
using namespace std;
class Student
{
    private:
    string name;
    long long int ID;
    string college;
    string major;
    string gender;
    long long int phone;
    public:
    void get()
    {
        cin >> name >> ID >> college >> major >> gender >> phone;
    }
    void print()
    {
        cout << name << ' ' << ID << ' ' << college << ' ' << major << ' ' << gender << ' ' << phone << endl;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Student temp;
        temp.get();
        temp.print();
    }
    
    return 0;
}