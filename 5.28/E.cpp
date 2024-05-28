#include <iostream>
using namespace std;

class RMB;
ostream & operator <<(ostream &, RMB &);
istream & operator >>(istream &, RMB &);

class RMB{
protected:
	int yuan, jiao, fen;
public:
	RMB(double a=0.0);
	RMB (int, int, int); 
	bool operator > (RMB &);
	friend ostream & operator <<(ostream &, RMB&); //一行输出，无换行
	friend istream & operator >>(istream &, RMB&);
	friend RMB operator +(RMB&, RMB&);
};
//完成以下类定义的填空
/********** Write your code here! **********/
RMB::RMB(double a)
{
    a += 0.005;
    a *= 100;
    int b = int(a);
    yuan = b / 100;
    jiao = (b % 100) / 10;
    fen = (b % 10);
}
RMB::RMB (int y, int j, int f):yuan(y),jiao(j),fen(f){}
bool RMB::operator > (RMB &b)
{
    int A = 0, B = 0;
    A = this->yuan * 100 + this->jiao * 10 + this->fen;
    B = b.yuan * 100 + b.jiao * 10 + b.fen;
    if (A > B)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
ostream & operator <<(ostream & cout, RMB& r)
{
    cout << r.yuan << "yuan" << r.jiao << "jiao" << r.fen << "fen";
    return cout;
}
istream & operator >>(istream & cin, RMB& r)
{
    int yuan, jiao, fen;
    cin >> yuan >> jiao >> fen;
    r.yuan = yuan;
    r.jiao = jiao;
    r.fen = fen;
    return cin;
}
RMB operator +(RMB& a, RMB& b)
{
    RMB c;
    c.yuan = a.yuan + b.yuan;
    c.jiao = a.jiao + b.jiao;
    c.fen = a.fen + b.fen;
    c.jiao += c.fen / 10;
    c.fen %= 10;
    c.yuan += c.jiao /10;
    c.jiao %= 10;
    return c;
}
/*******************************************/
//主函数
int main()
{	int t;
	double val_yuan; 
	cin>>t;
	while (t--)
	{	cin>>val_yuan;	//输入一个浮点数，例如1.23 
		RMB r1(val_yuan); //例如上一行输入1.23，则生成对象r1是1元2角3分 
		RMB r2;
		cin>>r2;	//输入一行三个整数参数，按元、角、分输入 

		if (r1>r2) 		cout<<r1<<" > "<<r2<<endl;
		else 			cout<<r1<<" <= "<<r2<<endl;
		RMB r3 =r1+r2;
		cout<<r1<<" + "<<r2<<" = "<<r3<<endl;
	}
	return 0;
}
