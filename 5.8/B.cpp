#include <iostream>
#include <string>
using namespace std;

class CVehicle {
protected:
    int max_speed;
    int speed;
    int weight;
public:
    CVehicle(int _max_speed, int _speed, int _weight) : max_speed(_max_speed), speed(_speed), weight(_weight) {}
    void display() const {
        
        cout << "max_speed:" << max_speed << endl;
        cout << "speed:" << speed << endl;
        cout << "weight:" << weight << endl;
    }
};

class CBicycle : virtual public CVehicle {
protected:
    int height;
public:
    CBicycle(int _max_speed, int _speed, int _weight, int _height)
        : CVehicle(_max_speed, _speed, _weight), height(_height) {}
    void display() const {
        
        cout << endl;
        cout << "Bicycle:" << endl;
        CVehicle::display();
        cout << "height:" << height << endl;
    }
};

class CMotocar : virtual public CVehicle {
protected:
    int seat_num;
public:
    CMotocar(int _max_speed, int _speed, int _weight, int _seat_num)
        : CVehicle(_max_speed, _speed, _weight), seat_num(_seat_num) {}
    void display() const {
        cout << endl;
        cout << "Motocar:" << endl;
        CVehicle::display();
        cout << "seat_num:" << seat_num << endl;
    }
};

class CMotocycle : public CBicycle, public CMotocar {
public:
    CMotocycle(int _max_speed, int _speed, int _weight, int _height, int _seat_num)
        : CVehicle(_max_speed, _speed, _weight), CBicycle(_max_speed, _speed, _weight, _height), CMotocar(_max_speed, _speed, _weight, _seat_num) {}
    void display() const {
        CVehicle::display();
        CBicycle::display();
        CMotocar::display();
        cout << endl;
        cout << "Motocycle:" << endl;
        cout << "max_speed:" << max_speed << endl;
        cout << "speed:" << speed << endl;
        cout << "weight:" << weight << endl;
        cout << "height:" << height << endl;
        cout << "seat_num:" << seat_num << endl;
    }
};

int main() {
    int max_speed, speed, weight, height, seat_num;

    cin >> max_speed >> speed >> weight;
    cin >> height;
    cin >> seat_num;

    CMotocycle vehicle(max_speed, speed, weight, height, seat_num);
    cout << "Vehicle:" << endl;
    vehicle.display();

    return 0;
}
