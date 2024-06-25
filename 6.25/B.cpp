#include <iostream>
using namespace std;

class Metal
{
private:
    int hardness;
    int weight;
    int volume;

public:
    Metal(int h, int w, int v) : hardness(h), weight(w), volume(v) {}

    friend Metal operator+(const Metal &m1, const Metal &m2)
    {
        int newHardness = m1.hardness + m2.hardness;
        int newWeight = m1.weight + m2.weight;
        int newVolume = m1.volume + m2.volume;
        return Metal(newHardness, newWeight, newVolume);
    }

    friend Metal operator*(const Metal &m, int n)
    {
        int newVolume = m.volume * n;
        return Metal(m.hardness, m.weight, newVolume);
    }

    Metal &operator++()
    {
        hardness++;
        weight = (weight * 11) / 10;
        volume = (volume * 11) / 10;
        return *this;
    }

    Metal operator--(int)
    {
        Metal temp = *this;
        hardness--;
        weight = (weight * 9) / 10;
        volume = (volume * 9) / 10;
        return temp;
    }

    void print() const
    {
        cout << "硬度" << hardness << "--重量" << weight << "--体积" << volume << endl;
    }
};

int main()
{
    int h1, w1, v1;
    int h2, w2, v2;
    int n;

    cin >> h1 >> w1 >> v1;
    Metal m1(h1, w1, v1);

    cin >> h2 >> w2 >> v2;
    Metal m2(h2, w2, v2);

    cin >> n;

    Metal combined = m1 + m2;
    combined.print();

    Metal enlarged = m1 * n;
    enlarged.print();

    ++m1;
    m1.print();

    m2--;
    m2.print();

    return 0;
}
