#include <iostream>
#include <string.h>
using namespace std;
class STR
{
    private:
    char *s;
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
    public:
    STR(char *t):s(t)
    {
        cout <<"constructing...\n";
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
    ~STR()
    {
        cout << "delete space...\n";
    }
    STR (const STR& obj)
    {
        s = new char[strlen(obj.s)];
        strcpy(s, obj.s);
        cout << "copy constructing...\n";
        fun();
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
    STR after(string);
    string.print();
    cout << " can be tranformed to " ;
    after.print();
    cout << endl;
    return 0;
}