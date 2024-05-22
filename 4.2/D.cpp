#include <iostream>
using namespace std;
class ID
{
    private:
    string pastID, nowID;
    public:
    ID(){}
    ID(string id):pastID(id)
    {
        nowID = "aaaaaaaaaaaaaaaaaa\0";
        cout << "construct ID=" << pastID << endl;
    }
    ~ID()
    {
        cout << "destruct ID=";
        for(int i = 14;i < 18;i++)
        {
            cout << nowID[i];
        }
        cout << endl;
    }
    void transfer()
    {
        for(int i = 0;i < 6;i++)
        {
            nowID[i] = pastID[i];
        }
        nowID[6] = '1';
        nowID[7] = '9';
        for(int i = 8;i < 17;i++)
        {
            nowID[i] = pastID[i - 2];
        }
        int bok[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
        char key[] = {'1','0','X','9','8','7','6','5','4','3','2'};
        long long S = 0, Y;
        for(int i = 0;i < 17;i++)
        {
            S += (int(nowID[i]) - 48) * bok[i];
        }
        Y = S % 11;
        nowID[17] = key[Y];
        cout << "upgrade ID=" << nowID << endl;
    }
};
int main()
{
    int n;
    cin >> n;
    string id;
    for(int i = 0;i < n;i++)
    {
        cin >> id;
        ID ID1(id);
        ID1.transfer();
    }
    return 0;
}