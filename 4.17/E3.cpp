#include <iostream>
using namespace std;
class CCow
{
private:
    static int diffAgeCow[12];

public:
    CCow() = default;
    int suan(int x)
    {
        for (int i = 1; i <= 10; i++)
        {
            diffAgeCow[i] = 0;
        }
        diffAgeCow[1] = 1;
        for (int i = 0; i < x - 1; i++)
        {
            for (int j = 11; j > 1; j--)
            {
                diffAgeCow[j] = diffAgeCow[j - 1];
            }
            int ans = 0;
            for (int j = 10; j >= 4; j--)
            {
                ans += diffAgeCow[j];
            }
            diffAgeCow[1] = ans;

            if (x - 1 != i)
                diffAgeCow[11] = 0;
        }
        int anss = 0;
        for (int i = 1; i <= 11; i++)
        {
            anss += diffAgeCow[i];
        }
        return anss;
    }
};
int CCow::diffAgeCow[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        CCow A;
        cout << A.suan(x) << endl;
    }
}