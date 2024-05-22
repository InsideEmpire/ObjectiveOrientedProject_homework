#include <iostream>
using namespace std;
class CCow
{
    private:
    int age;
    
    bool sat;
    public:
    static int TotalNum;
    CCow()
    {
        age = 0;
        sat = 0;
    }
    CCow(int Age):age(Age){};
    void passyear()
    {
        age ++;
        
    }
    int getAge()
    {
        return age;
    }
    bool getSat()
    {
        return sat;
    }
    void set()
    {
        age = 1;
        sat = 1;
    }
    void death()
    {
        sat = 0;
    }
};
int CCow::TotalNum = 1;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int year;
        cin >> year;
        CCow **p = new CCow*[31];
        for(int i = 0;i < year;i++)
        {
            p[i] = new CCow[28364];
        }
        p[0][0].set();
        for(int i = 0;i < year;i++)
        {
            int birth = 0;
            for(int j = 0;j < CCow::TotalNum;j++)
            {
                
                if (p[i][j].getSat() == 1&&p[i][j].getAge() >= 11)
                {
                    p[i][j].death();
                    CCow::TotalNum--;
                }
                
                if (p[i][j].getAge() > 4&&p[i][j].getSat() == 1)
                {
                    birth++;
                }
                p[i][j].passyear();
            }
            for(int j = 0;j < CCow::TotalNum;j++)
            {
                p[i + 1][j] = p[i][j];
            }
            if (birth == 0)
            {
                continue;
            }
            
            for(int j = CCow::TotalNum;j <= CCow::TotalNum + birth;j++)
            {
                p[i][j].set();
            }
            CCow::TotalNum += birth;
        }
        cout << CCow::TotalNum << endl;
    }
    
}