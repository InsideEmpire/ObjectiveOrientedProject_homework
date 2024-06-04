#include <iostream>
using namespace std;

template <class T>
class list
{
private:
    T *p = new T[100];
    int n;

public:
    list()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
    }
    void insert(int place, T value)
    {
        for (int i = n; i > place; i--)
        {
            p[i] = p[i - 1];
        }
        p[place] = value;
        n++;
    }
    void myDelete(int place)
    {
        for (int i = place; i < n - 1; i++)
        {
            p[i] = p[i + 1];
        }
        n--;
    }
    void Print()
    {
        for (int i = 0; i < n - 1; i++)
        {
            cout << p[i] << " ";
        }
        cout << p[n - 1];
        cout << endl;
    }
};

int main()
{
    list<int> integer;
    int insterPlace;
    double insertValue;
    cin >> insterPlace >> insertValue;
    integer.insert(insterPlace, insertValue);
    int deletePlace;
    cin >> deletePlace;
    integer.myDelete(deletePlace);
    integer.Print();
    list<double> doubl;
    // int insterPlace, insertValue;
    cin >> insterPlace >> insertValue;
    doubl.insert(insterPlace, insertValue);
    // int deletePlace;
    cin >> deletePlace;
    doubl.myDelete(deletePlace);
    doubl.Print();
}