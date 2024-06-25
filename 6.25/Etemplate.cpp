#include <iostream>
using namespace std;

class CN; // 提前声明
class EN; // 提前声明

class Weight
{ // 抽象类
protected:
    string kind; // 计重类型
    int gram;    // 克
public:
    Weight(string tk = "no name", int tg = 0) : kind(tk), gram(tg) {}
    virtual void Print(ostream &out) = 0; // 输出不同类型的计重信息
};

// 中国计重类
class CN : public Weight
{
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

    CN &operator=(const EN &en);
};

// 英国计重类
class EN : public Weight
{
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

    operator CN() const
    {
        int totalGrams = gram; // 获取总克数
        CN cn;
        cn.Convert(totalGrams);
        return cn;
    }
};

// 重载输出运算符
ostream &operator<<(ostream &out, Weight &w)
{
    w.Print(out);
    return out;
}

// CN类的赋值操作符重载，用于将EN对象转换为CN对象
CN &CN::operator=(const EN &en)
{
    int totalGrams = en.gram;  // 获取EN对象的总克数
    this->Convert(totalGrams); // 调用Convert方法进行转换
    return *this;
}

int main() // 主函数
{
    int tw;

    // 创建一个中国计重类对象cn
    CN cn(0, 0, 0, 0, "中国计重");

    cin >> tw;
    cn.Convert(tw); // 把输入的克数转成中国计重
    cout << cn;

    // 创建英国计重类对象en
    EN en(0, 0, 0, 0, "英国计重");

    cin >> tw;
    en.Convert(tw); // 把输入的克数转成英国计重
    cout << en;

    cn = en; // 把英国计重转成中国计重
    cout << cn;

    return 0;
}
