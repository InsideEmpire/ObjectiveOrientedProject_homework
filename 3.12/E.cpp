#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        char a[11], b[11], c[11];
        int a1, a2, b1, b2, c1, c2;
        //cin >> a >> b >> c;
        scanf("%s %s %s", a, b, c);
        cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
        char *array;
        int len = a2 - a1 + b2 - b1 + c2 - c1 + 3;
        array = new char [len];
        int k = 0;
        for(int j = a1 - 1;j < a2;j++)
        {
            *(array + k) = *(a + j);
            k++;
        }
        for(int j = b1 - 1;j < b2;j++)
        {
            *(array + k) = *(b + j);
            k++;
        }
        for(int j = c1 - 1;j < c2;j++)
        {
            *(array + k) = *(c + j);
            k++;
        }
        for(int j = 0;j < len;j++)
        {
            cout << *(array + j);
        }
        cout << endl;
    }
    return 0;
}