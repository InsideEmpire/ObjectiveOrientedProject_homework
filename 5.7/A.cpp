#include <iostream>
using namespace std;
class CExaminee
{
private:
    int no;
    int Politics;
    int English;
    int Math;
    int Computer;
    int Total;
public:
    CExaminee()
    {
        no = 0;
        Politics = 0;
        English = 0;
        Math = 0;
        Computer = 0;
        Total = 0;
    }
    void getValue()
    {
        cin >> no >> Politics >> English >> Math >> Computer;
    }
    void isPassed(int total, int hun, int fif)
    {
        Total = Politics + English + Math + Computer;
        if (Total >= total && Politics >= hun && English >= hun && Math >= fif && Computer >= fif)
        {
            cout << no << "pass\n";
        }
        else
        {
            cout << no << "fail\n";
        }
    }
};
int main()
{
    int total, hun, fif;
    cin >> total >> hun >> fif;
    int t;
    cin >> t;
    CExaminee *p;
    p = new CExaminee[t];
    while (t--)
    {
        p[t].getValue();
        p[t].isPassed(total, hun, fif);
    }
    delete[] p;
}