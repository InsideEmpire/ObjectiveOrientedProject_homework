#include <iostream>
using namespace std;
class Employee
{
protected:
    string name;
    string type;
    int level;
    int age;

public:
    Employee(string N, string T, int L, int A) : name(N), type(T), level(L), age(A) {}
    virtual void salary()
    {
        int salary = 0;
        salary = 1500 + 100 * level + 150 * age;
        cout << salary << endl;
    }
};
class Director : public Employee
{
public:
    Director(string N, string T, int L, int A) : Employee(N, T, L, A) {}
    void salary()
    {
        int salary = 0;
        salary = 5000 + 200 * level + 300 * age;
        cout << salary << endl;
    }
};
class Manager : public Employee
{
public:
    Manager(string N, string T, int L, int A) : Employee(N, T, L, A) {}
    void salary()
    {
        int salary = 0;
        salary = 10000 + 300 * level + 500 * age;
        cout << salary << endl;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string name;
        string type;
        int level;
        int age;
        cin >> name >> type >> level >> age;
        Employee *p;
        if (type == "Employee")
        {
            if (level < 0 || age < 0)
            {
                cout << "error grade or year.\n";
                continue;
            }
            Employee tem(name, type, level, age);
            p = &tem;
            p->salary();
        }
        else if (type == "Director")
        {
            if (level < 0 || age < 0)
            {
                cout << "error grade or year.\n";
                continue;
            }
            Director tem(name, type, level, age);
            p = &tem;
            p->salary();
        }
        else if (type == "Manager")
        {
            if (level < 0 || age < 0)
            {
                cout << "error grade or year.\n";
                continue;
            }
            Manager tem(name, type, level, age);
            p = &tem;
            p->salary();
        }
        else
        {
            cout << "error position.\n";
        }
    }
}