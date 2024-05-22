#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class Customer
{
public:
    Customer(char *name);
    // 根据用户输入的CustName和自动生成CustID生成一个Customer对象
    ~Customer();
    // 注意CustName空间的释放 
    static void changeYear(int r);//修改年份Year
    void Display(); // 输出客户信息
private:
    static int TotalCustNun; // 店现已入任的总入数，初始值为0
    static int Rent;         // 酒店每位客入的租金，初始值为158 
    static int Year;//当前年份，初始值为2014 
    int CustID;//客/ID，即上一位客人的ID+1， 1/如入住的第一位客人ID为1，第二位客人ID为2，以此类推
    char *CustHame;          // 客入姓名
};
int Customer::TotalCustNun = 0;
int Customer::Rent = 150;
int Customer::Year = 2014;
Customer::Customer(char *name):CustID(TotalCustNun + 1)
{
    TotalCustNun++;
    CustHame = new char[50];
    strcpy(CustHame, name);
}
Customer::~Customer()
{
    Rent += 150;
    delete CustHame;
}
void Customer::changeYear(int r)
{
    Year = r;
}
void Customer::Display()
{
    cout << CustHame << ' ' << Year << setfill('0') << setw(4) << CustID << ' ' << TotalCustNun << ' ' << Rent << endl;
}
int main()
{
    char name[50];
    int t;
    cin >> t;
    for(int i = 0;i < t;i++)
    {
        int year;
        cin >> year;
        while (1)
        {
            cin >> name;
            if (name[0] == '0')
            {
                break;
            }
            Customer tem(name);
            tem.changeYear(year);
            tem.Display();
        }
        
    }
}