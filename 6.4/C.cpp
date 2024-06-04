#include <iostream>
using namespace std;

template <class T>
class Matrix
{
public:
    T **data;
    int row, col;

public:
    Matrix(int r, int c) : row(r), col(c)
    {
        data = new T *[row];
        for (int i = 0; i < row; i++)
        {
            data[i] = new T[col];
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < row; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }
    void transPrint()
    {
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row - 1; j++)
            {
                cout << data[j][i] << " ";
            }
            cout << data[row - 1][i] << endl;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string type;
        cin >> type;
        if (type == "I")
        {
            int row, col;
            cin >> row >> col;
            Matrix<int> m(row, col);
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    cin >> m.data[i][j];
                }
            }
            m.transPrint();
        }
        if (type == "D")
        {
            int row, col;
            cin >> row >> col;
            Matrix<double> m(row, col);
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    cin >> m.data[i][j];
                }
            }
            m.transPrint();
        }
        if (type == "C")
        {
            int row, col;
            cin >> row >> col;
            Matrix<char> m(row, col);
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    cin >> m.data[i][j];
                }
            }
            m.transPrint();
        }
    }
}