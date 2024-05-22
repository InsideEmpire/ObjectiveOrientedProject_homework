#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        int row, column;
        cin >> row >> column;
        int **array;
        array = new int* [row];
        for(int j = 0;j < row;j++)
        {
            array[j] = new int [column];
        }
        for(int j = 0;j < row;j++)
        {
            for(int k = 0;k < column;k++)
            {
                cin >> array[j][k];
            }
        }
        int maxx = 0, minn = 999999;
        for(int j = 0;j < row;j++)
        {
            for(int k = 0;k < column;k++)
            {
                if (array[j][k] > maxx)
                {
                    maxx = array[j][k];
                }
                if (array[j][k] < minn)
                {
                    minn = array[j][k];
                }
                
            }
        }
        cout << minn << ' ' << maxx << endl;
    }
}