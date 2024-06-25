#include <iostream>
using namespace std;

class Appliance
{
protected:
    int id;
    int power;

public:
    Appliance(int i, int p) : id(i), power(p) {}
    virtual void print() const = 0;
};

class Fan : virtual public Appliance
{
protected:
    int direction;
    int speed;

public:
    Fan(int i, int p, int d, int s) : Appliance(i, p), direction(d), speed(s) {}
    void controlDirection(int d)
    {
        direction = d;
    }
    void controlSpeed(int s)
    {
        speed = s;
    }
    virtual void print() const override
    {
        cout << "编号" << id << "--功率" << power << "W\n";
        cout << (direction == 0 ? "定向吹风" : "旋转吹风") << "--风力" << speed << "级\n";
    }
};

class Humidifier : virtual public Appliance
{
protected:
    float currentWaterVolume;
    float maxWaterVolume;

public:
    Humidifier(int i, int p, float c, float m) : Appliance(i, p), currentWaterVolume(c), maxWaterVolume(m) {}
    int warn() const
    {
        if (currentWaterVolume >= maxWaterVolume * 0.5)
            return 1;
        else if (currentWaterVolume >= maxWaterVolume * 0.1)
            return 2;
        else
            return 3;
    }
    virtual void print() const override
    {
        cout << "实际水容量" << currentWaterVolume << "升";
        int warning = warn();
        if (warning == 1)
            cout << "--水量正常\n";
        else if (warning == 2)
            cout << "--水量偏低\n";
        else
            cout << "--水量不足\n";
    }
};

class HumidifierFan : public Fan, public Humidifier
{
private:
    int gear;

public:
    HumidifierFan(int i, int p, int d, int s, float c, float m, int g)
        : Appliance(i, p), Fan(i, p, d, s), Humidifier(i, p, c, m), gear(g) {}

    void adjustGear(int g)
    {
        gear = g;
        switch (g)
        {
        case 0:
            break;
        case 1:
            controlDirection(0);
            controlSpeed(1);
            break;
        case 2:
            controlDirection(1);
            controlSpeed(2);
            break;
        case 3:
            controlDirection(1);
            controlSpeed(3);
            break;
        default:
            break;
        }
    }

    void print() const override
    {
        cout << "加湿风扇--档位" << gear << "\n";
        Fan::print();
        Humidifier::print();
    }
};

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int id, power, direction, speed, gear;
        float currentWaterVolume, maxWaterVolume;

        cin >> id >> power >> direction >> speed >> currentWaterVolume >> maxWaterVolume >> gear;
        HumidifierFan hf(id, power, direction, speed, currentWaterVolume, maxWaterVolume, gear);

        int newGear;
        cin >> newGear;
        hf.adjustGear(newGear);

        hf.print();
    }

    return 0;
}
