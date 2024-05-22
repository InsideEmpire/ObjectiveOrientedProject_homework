#include <iostream>
using namespace std;
class CCow
{
    private:
    static int diffAgeCow[12];
    public:
    void passYear()
    {
        for(int i = 11;i >= 2;i--)//先过生日再生孩子
        {
            diffAgeCow[i] = diffAgeCow[i -1];
        }
        diffAgeCow[1] = 0;
        int birth = 0;
        for(int i = 10;i >= 4;i--)//11岁不生孩子死
        {
            birth += diffAgeCow[i];
        }
        diffAgeCow[1] = birth;
    }
    static int totalNum()
    {
        int ans = 0;
        for(int i = 1;i <= 10;i++)
        {
            ans += diffAgeCow[i];
        }
        return ans;
    }
    void reset()
    {
        for(int i = 0;i <12;i++)
        {
            diffAgeCow[i] = 0;
        }
        diffAgeCow[1] = 1;
    }
};
int CCow::diffAgeCow[12] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
int main()
{
    int t;
    cin >> t;
    for(int j = 0;j < t;j++)
    {
        int year;
        cin >> year;
        CCow *cow = new CCow;
        for(int i = 0;i < year - 1;i++)
        {
            cow->passYear();
        }
        cout << cow->totalNum() << endl;
        cow->reset();
        delete cow;
    }
    
}