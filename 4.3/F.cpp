#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>

using namespace std;
class STR
{
    private:
    char *s;
    public:
    STR(char *t):s(t){}
    void backward (char *t1,char *t2)
    {
        char tem;
        for(int i = 0;(t1 + i) < (t2 - i);i++)
        {
            if ((t1 + i) >= (t2 - i))
            {
                return;
            }
            tem = *(t1 + i);
            *(t1 + i) = *(t2 - i);
            *(t2 - i) = tem;
        }
    }
    void fun()
    {
        char *t1 = s;
        char *t2;
        for(int i = 0;i <= strlen(s);i++)
        {
            if (s[i] == ' '||s[i] == '\0')
            {
                t2 = (s + i - 1);
                backward(t1, t2);
                t1 = (t2 + 2);
            }
            
        }
    }
    void print()
    {
        for(int i = 0;i < strlen(s);i++)
        {
            cout << s[i];
        }
    }
};
int main()
{
    string input;
    getline(cin, input);

    char *s = new char[input.length() + 1];
    strcpy(s, input.c_str());

    s[strlen(s)] = '\0';
    STR string(s);
    string.fun();
    string.print();
    return 0;
}