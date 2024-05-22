#include <iostream>
using namespace std;
class Data
{
    private:
    int value;
    public:
    Data()
    {
        value = 0;
        cout << "Constructed by default, value = 0\n";
    }
    Data(int v):value(v)
    {
        cout << "Constructed using one argument constructor, value = " << value << endl;
    }
    Data(const Data & last)
    {
        value = last.value;
        cout << "Constructed using copy constructor, value = " << value << endl;
    }

};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int bok;
        cin >> bok;
        if (bok == 0)
        {
            Data tem;
        }
        if (bok == 1)
        {
            int value;
            cin >> value;
            Data tem(value);
        }
        if (bok == 2)
        {
            int value;
            cin >> value;
            Data tem(value);
            Data tem2 = tem;
        }
        
    }
    
}