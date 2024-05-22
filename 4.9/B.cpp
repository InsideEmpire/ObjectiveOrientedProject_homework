#include <iostream>
#include <string.h>
using namespace std;
class Student
{
public:
    Student(char *pname)
    {
        cout << "Constructing " << pname << endl;
        name = new char[strlen(pname) + 1];
        if (name != NULL)
            strcpy(name, pname);
    }
    Student(Student &s)
    {
        name = new char[strlen(s.returnaddress()) + 1];
        if (name != NULL)
            strcpy(name, s.returnaddress());
        cout << "Copying of " << name << endl;
    }
    ~Student()
    {
        cout << "Destructing " << name << endl;
    }
    char* returnaddress()
    {
        return name;
    }
protected:
    char *name;
};
int main()
{
    char name[10];
    cin >> name;
    Student s1(name);
    Student s2 = s1;
    return 0;
}
