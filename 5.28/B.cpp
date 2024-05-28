#include <iostream>
#include <string>
using namespace std;

class CXGraph
{
private:
    int size;

public:
    CXGraph(int n) : size(n) {}
    CXGraph() : size(1) {}

    void print() const
    {
        if (size == 1)
        {
            cout << "X";
        }
        else
        {
            for (int i = 0; i < size / 2 + 1; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    cout << ' ';
                }
                for (int j = 0; j < size - i * 2; j++)
                {
                    cout << 'X';
                }
                cout << endl;
            }
            for (int i = size / 2 - 1; i >= 0; i--)
            {
                for (int j = 0; j < i; j++)
                {
                    cout << ' ';
                }
                for (int j = 0; j < size - i * 2; j++)
                {
                    cout << 'X';
                }
                if (i != 0)
                {
                    cout << endl;
                }
            }
        }
        cout << endl;
    }

    friend ostream &operator<<(ostream &cout, const CXGraph &graph)
    {
        graph.print();
        return cout;
    }

    CXGraph &operator++()
    {
        if (size == 21)
            return *this;
        else
        {
            size += 2;
        }
        return *this;
    }

    CXGraph operator++(int)
    {
        CXGraph temp = *this;
        if (size == 21)
            return temp;
        else
        {
            size += 2;
        }
        return temp;
    }

    CXGraph &operator--()
    {
        if (size == 1)
            return *this;
        else
        {
            size -= 2;
        }
        return *this;
    }

    CXGraph operator--(int)
    {
        CXGraph temp = *this;
        if (size == 1)
            return temp;
        else
        {
            size -= 2;
        }
        return temp;
    }
};

int main()
{
    int n, t;
    cin >> n;
    CXGraph xGraph(n);
    cin >> t;
    while (t--)
    {
        string command;
        cin >> command;
        if (command == "show++")
            cout << xGraph++ << endl;
        else if (command == "++show")
            cout << ++xGraph << endl;
        else if (command == "show--")
            cout << xGraph-- << endl;
        else if (command == "--show")
            cout << --xGraph << endl;
        else if (command == "show")
            cout << xGraph << endl;
    }
    return 0;
}
