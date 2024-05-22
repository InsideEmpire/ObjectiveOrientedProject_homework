#include <iostream>
using namespace std;

class Vehicle {
protected:
    double weight;
public:
    Vehicle(){cout << "载入Vehicle类构造函数" << endl;}
    Vehicle(double _weight) : weight(_weight) {
        cout << "载入Vehicle类构造函数" << endl;
    }
    void setWeight(double _weight) {
        weight = _weight;
        cout << "重新设置重量" << endl;
    }
    void display() const {
        cout << "重量：" << weight << "吨" << endl;
    }
};

class Car : virtual public Vehicle {
protected:
    int air_displacement;
public:
    Car(){cout << "载入Car类构造函数" << endl;}
    Car(double _weight, int _air_displacement) : Vehicle(_weight), air_displacement(_air_displacement) {
        cout << "载入Car类构造函数" << endl;
    }
    void setAird(int _air_displacement) {
        air_displacement = _air_displacement;
        cout << "重新设置空气排量" << endl;
    }
    void display() const {
        Vehicle::display();
        cout << "空气排量：" << air_displacement << "CC" << endl;
    }
};

class Boat : virtual public Vehicle {
protected:
    double tonnage;
public:
    Boat(){cout << "载入Boat类构造函数" << endl;}
    Boat(double _weight, double _tonnage) : Vehicle(_weight), tonnage(_tonnage) {
        cout << "载入Boat类构造函数" << endl;
    }
    void setTonnage(double _tonnage) {
        tonnage = _tonnage;
        cout << "重新设置排水量" << endl;
    }
    void display() const {
        Vehicle::display();
        cout << "排水量：" << tonnage << "吨" << endl;
    }
};

class AmphibianCar : public Car, public Boat {
public:
    AmphibianCar(double _weight, int _air_displacement, double _tonnage)
    {
        weight = _weight;
        air_displacement = _air_displacement;
        tonnage = _tonnage;
        cout << "载入AmphibianCar类构造函数" << endl;
    }
    void display() const {
        cout << "重量：" << weight << "吨，空气排量：" << air_displacement << "CC，排水量：" << tonnage << "吨" << endl;
    }
};

int main() {
    double weight, tonnage;
    int air_displacement;

    cin >> weight >> air_displacement >> tonnage;
    AmphibianCar car(weight, air_displacement, tonnage);

    car.display();

    cin >> weight >> air_displacement >> tonnage;
    car.setWeight(weight);
    car.setAird(air_displacement);
    car.setTonnage(tonnage);

    car.display();

    return 0;
}
