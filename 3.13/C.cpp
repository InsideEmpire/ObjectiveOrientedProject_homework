#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int t ;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        char code[101];
        char *p = code;
        char key[101];
        char *q = key;
        char ans[101];
        char *s = ans;
        cin >> code >> key;
        for(int j = 0, k = 0;j < strlen(code);j++, k++)
        {
            if (k == strlen(key))
            {
                k = 0;
            }
            if ((int(*(p + j)) + *(q + k) - 48 <= 90&&int(*(p + j)) >= 65)||(int(*(p + j)) + *(q + k) - 48 <= 122&&int(*(p + j)) >= 97))
            {
                *(s + j) = char(int(*(p + j)) + *(q + k) - 48);
            }
            else if (int(*(p + j)) >= 65&&(int(*(p + j)) + *(q + k) - 48 > 90))
            {
                *(s + j) = char((int(*(p + j)) + *(q + k) - 48 - 90) + 64);
            }
            else
            {
                *(s + j) = char((int(*(p + j)) + *(q + k) - 48 - 122) + 96);
            }
        }
        for(int j = 0;j < strlen(code);j++)
        {
            cout << *(s + j);
        }
        cout << endl;
    }
}