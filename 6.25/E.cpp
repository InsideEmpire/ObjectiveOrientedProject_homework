#include <iostream>
using namespace std;
class CN; // 提前声明

class EN; // 提前声明

class Weight
{ // 抽象类

protected:
    string kind; // 计重类型

    int gram; // 克

public:
    Weight(string tk = "no name", int tg = 0)

    {
        kind = tk;

        gram = tg;
    }

    virtual void Print(ostream &out) = 0; // 输出不同类型的计重信息
};

class CN : public Weight
{ // 中国计重
    //....类定义自行编写
    /********** Write your code here! **********/
private:
    int jin;   // 斤
    int liang; // 两
    int qian;  // 钱
    int grams; // 剩余克数
public:
    CN(int tj = 0, int tl = 0, int tq = 0, int tg = 0, string tk = "中国计重") : Weight(tk, tg), jin(tj), liang(tl), qian(tq), grams(tg) {}

    void Convert(int grams)
    {
        this->gram = grams;
        this->jin = grams / 500;
        grams %= 500;
        this->liang = grams / 50;
        grams %= 50;
        this->qian = grams / 5;
        grams %= 5;
        this->grams = grams;
    }

    void Print(ostream &out) override
    {
        out << kind << ":" << jin << "斤" << liang << "两" << qian << "钱" << grams << "克\n";
    }

    CN &operator=(EN &en);

    /*******************************************/
};

class EN : public Weight
{ // 英国计重
    //....类定义自行编写
    /********** Write your code here! **********/
private:
    int pound; // 磅
    int ounce; // 盎司
    int dram;  // 打兰
    int grams; // 剩余克数
public:
    EN(int tp = 0, int to = 0, int td = 0, int tg = 0, string tk = "英国计重") : Weight(tk, tg), pound(tp), ounce(to), dram(td), grams(tg) {}

    void Convert(int grams)
    {
        this->gram = grams;
        this->pound = grams / 512;
        grams %= 512;
        this->ounce = grams / 32;
        grams %= 32;
        this->dram = grams / 2;
        grams %= 2;
        this->grams = grams;
    }

    void Print(ostream &out) override
    {
        out << kind << ":" << pound << "磅" << ounce << "盎司" << dram << "打兰" << grams << "克\n";
    }

    int getGram()
    {
        return this->gram;
    }
    /*******************************************/
};
// 以全局函数方式重载输出运算符，代码3-5行....自行编写

// 重载函数包含两个参数：ostream流对象、Weight类对象，参数可以是对象或对象引用

// 重载函数必须调用参数Weight对象的Print方法
/********** Write your code here! **********/
ostream &operator<<(ostream &out, Weight &w)
{
    w.Print(out);
    return out;
}
CN &CN::operator=(EN &en)
    {
        int totalGrams = en.getGram();  // 获取EN对象的总克数
        this->Convert(totalGrams); // 调用Convert方法进行转换
        return *this;
    }
/*******************************************/
int main() // 主函数

{
    int tw;

    // 创建一个中国计重类对象cn

    // 构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind

    CN cn(0, 0, 0, 0, "中国计重");

    cin >> tw;

    cn.Convert(tw); // 把输入的克数转成中国计重

    cout << cn;

    // 创建英国计重类对象en

    // 构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind

    EN en(0, 0, 0, 0, "英国计重");

    cin >> tw;

    en.Convert(tw); // 把输入的克数转成英国计重

    cout << en;

    cn = en; // 把英国计重转成中国计重

    cout << cn;

    return 0;
}