#include <iostream>
using namespace std;
int main()
{
    int t ;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        int array[2][3];
        int *p = &array[0][0];
        //int **p = array;
        for(int j = 0;j < 2;j++)
        {
            for(int k = 0;k < 3;k++)
            {
                cin >> array[j][k];
            }
        }
        for(int j = 2;j >= 0;j--)
        {
            for(int k = 0;k < 2;k++)
            {
                cout << *(p + j + k * 3) << ' ';
            }
            cout << endl;
        }
    }
}