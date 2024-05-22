#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string no;
public:
    virtual void display() = 0;
    Vehicle(string _no):no(_no){}
};

class Car : public Vehicle
{
protected:
    int passengerCount;
    int weight;
public:
    Car(string _no, int _passengerCount, int _weight) :Vehicle(_no), passengerCount(_passengerCount), weight(_weight) {}

    virtual void display()
    {
        cout << no << " " << passengerCount * 8 + weight * 2 << endl;
    }
};

class Truck : public Vehicle
{
protected:
    int weight;
public:
    Truck(string _no, int _weight) :Vehicle(_no), weight(_weight) {}

    virtual void display()
    {
        cout << no << " " << weight * 5 << endl;
    }
};

class Bus : public Vehicle
{
protected:
    int passengerCount;
public:
    Bus(string _no, int _passengerCount) :Vehicle(_no), passengerCount(_passengerCount) {}

    virtual void display()
    {
        cout << no << " " << passengerCount * 3 << endl;
    }
};

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int type, passengerCount, weight;
        string no;
        cin >> type >> no;
        if (type == 1)
        {
            cin >> passengerCount >> weight;
            Car car(no, passengerCount, weight);
            Vehicle *pv = &car;
            pv->display();
        }
        else if (type == 2)
        {
            cin >> weight;
            Truck truck(no, weight);
            Vehicle *pv = &truck;
            pv->display();
        }
        else if (type == 3)
        {
            cin >> passengerCount;
            Bus bus(no, passengerCount);
            Vehicle *pv = &bus;
            pv->display();
        }
    }
    return 0;
}
