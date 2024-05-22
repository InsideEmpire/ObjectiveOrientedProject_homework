#include <iostream>
using namespace std;
class Animal
{
protected:
    string name;
    int age;
public:
    virtual void Speak() = 0;
    Animal(string N, int A):name(N),age(A){}
    Animal(){}
};
class Tiger : public Animal
{
public:
    void Speak()
    {
        cout << "Hello,I am " << name << ",AOOO.\n";
    }
    Tiger(string N, int A):Animal(N, A){}
};
class Dog : public Animal
{
public:
    void Speak()
    {
        cout << "Hello,I am " << name << ",WangWang.\n";
    }
    Dog(string N, int A):Animal(N, A){}
};
class Duck : public Animal
{
public:
    void Speak()
    {
        cout << "Hello,I am " << name << ",GAGA.\n";
    }
    Duck(string N, int A):Animal(N, A){}
};
class Pig : public Animal
{
public:
    void Speak()
    {
        cout << "Hello,I am " << name << ",HENGHENG.\n";
    }
    Pig(string N, int A):Animal(N, A){}
};
int main()
{
    int t;
    cin >> t;
    Animal *p;
    while (t--)
    {
        int age;
        string name;
        string type;
        cin >> type;
        if (type == "Tiger")
        {
            cin >> name >> age;
            Tiger tem(name, age);
            p = &tem;
            p->Speak();
        }
        else if (type == "Dog")
        {
            cin >> name >> age;
            Dog tem(name, age);
            p = &tem;
            p->Speak();
        }
        else if (type == "Duck")
        {
            cin >> name >> age;
            Duck tem(name, age);
            p = &tem;
            p->Speak();
        }
        else if (type == "Pig")
        {
            cin >> name >> age;
            Pig tem(name, age);
            p = &tem;
            p->Speak();
        }
        else
        {
            cin >> name >> age;
            cout << "There is no " << type << " in our Zoo.\n";
        }
    }
    
}