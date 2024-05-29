#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class CBigInteger;

string add(const string &num1, const string &num2);
string subtract(const string &num1, const string &num2);
string multiply(const string &num1, const string &num2);
CBigInteger operator+(const CBigInteger &a, const CBigInteger &b);
CBigInteger operator-(const CBigInteger &a, const CBigInteger &b);
CBigInteger operator*(const CBigInteger &a, const CBigInteger &b);
ostream &operator<<(ostream &os, const CBigInteger &num);
istream &operator>>(istream &is, CBigInteger &num);

class CBigInteger
{
    friend string add(const string &num1, const string &num2);
    friend string subtract(const string &num1, const string &num2);
    friend string multiply(const string &num1, const string &num2);
    friend CBigInteger operator+(const CBigInteger &a, const CBigInteger &b);
    friend CBigInteger operator-(const CBigInteger &a, const CBigInteger &b);
    friend CBigInteger operator*(const CBigInteger &a, const CBigInteger &b);
    friend ostream &operator<<(ostream &os, const CBigInteger &num);
    friend istream &operator>>(istream &is, CBigInteger &num);

private:
    string integer;

public:
    CBigInteger(string Integer = "0") : integer(Integer) 
    {
        this->integer.erase(0, this->integer.find_first_not_of('0'));
    }
};

CBigInteger operator+(const CBigInteger &a, const CBigInteger &b)
{
    if (a.integer[0] == '-' && b.integer[0] == '-')
    {
        string a_positive = a.integer.substr(1);
        string b_positive = b.integer.substr(1);
        return CBigInteger("-" + add(a_positive, b_positive));
    }
    else if (a.integer[0] == '-' && b.integer[0] != '-')
    {
        string a_positive = a.integer.substr(1);
        if (a_positive == b.integer)
        {
            return CBigInteger("0");
        }
        else if (a_positive > b.integer)
        {
            return CBigInteger("-" + subtract(a_positive, b.integer));
        }
        else
        {
            return CBigInteger(subtract(b.integer, a_positive));
        }
    }
    else if (a.integer[0] != '-' && b.integer[0] == '-')
    {
        string b_positive = b.integer.substr(1);
        if (a.integer == b_positive)
        {
            return CBigInteger("0");
        }
        else if (a.integer > b_positive)
        {
            return CBigInteger(subtract(a.integer, b_positive));
        }
        else
        {
            return CBigInteger("-" + subtract(b_positive, a.integer));
        }
    }
    else
    {
        return CBigInteger(add(a.integer, b.integer));
    }
}

CBigInteger operator-(const CBigInteger &a, const CBigInteger &b)
{
    if (a.integer[0] == '-' && b.integer[0] == '-')
    {
        string a_positive = a.integer.substr(1);
        string b_positive = b.integer.substr(1);
        if (a_positive == b_positive)
        {
            return CBigInteger("0");
        }
        else if (a_positive > b_positive)
        {
            return CBigInteger("-" + subtract(a_positive, b_positive));
        }
        else
        {
            return CBigInteger(subtract(b_positive, a_positive));
        }
    }
    else if (a.integer[0] == '-' && b.integer[0] != '-')
    {
        string a_positive = a.integer.substr(1);
        return CBigInteger("-" + add(a_positive, b.integer));
    }
    else if (a.integer[0] != '-' && b.integer[0] == '-')
    {
        string b_positive = b.integer.substr(1);
        return CBigInteger(add(a.integer, b_positive));
    }
    else
    {
        if (a.integer == b.integer)
        {
            return CBigInteger("0");
        }
        else if (a.integer > b.integer)
        {
            return CBigInteger(subtract(a.integer, b.integer));
        }
        else
        {
            return CBigInteger("-" + subtract(b.integer, a.integer));
        }
    }
}

CBigInteger operator*(const CBigInteger &a, const CBigInteger &b)
{
    if ((a.integer[0] == '-' && b.integer[0] == '-'))
    {
        string a_positive = a.integer.substr(1);
        string b_positive = b.integer.substr(1);
        return CBigInteger(multiply(a_positive, b_positive));
    }
    else if ((a.integer[0] != '-' && b.integer[0] != '-'))
    {
        return CBigInteger(multiply(a.integer, b.integer));
    }
    else
    {
        if (a.integer[0] == '-')
        {
            string a_positive = a.integer.substr(1);
            return CBigInteger("-" + multiply(a_positive, b.integer));
        }
        else
        {
            string b_positive = b.integer.substr(1);
            return CBigInteger("-" + multiply(a.integer, b_positive));
        }
    }
}

string add(const string &num1, const string &num2)
{
    string result;
    int carry = 0;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += to_string(sum % 10);
    }

    reverse(result.begin(), result.end());
    result.erase(0, result.find_first_not_of('0'));
    return result.empty() ? "0" : result;
}

string subtract(const string &num1, const string &num2)
{
    string result;
    int borrow = 0;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0)
    {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result += to_string(diff);
    }

    reverse(result.begin(), result.end());
    result.erase(0, result.find_first_not_of('0'));
    return result.empty() ? "0" : result;
}

string multiply(const string &num1, const string &num2)
{
    string result(num1.size() + num2.size(), '0');

    for (int i = num1.size() - 1; i >= 0; --i)
    {
        int carry = 0;
        for (int j = num2.size() - 1; j >= 0; --j)
        {
            int sum = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            result[i + j + 1] = sum % 10 + '0';
            carry = sum / 10;
        }
        result[i] += carry;
    }

    result.erase(0, result.find_first_not_of('0'));
    return result.empty() ? "0" : result;
}

istream &operator>>(istream &is, CBigInteger &num)
{
    is >> num.integer;
    //num.integer.erase(0, num.integer.find_first_not_of('0'));
    return is;
}

ostream &operator<<(ostream &os, const CBigInteger &num)
{
    string trimmed = num.integer;
    if (trimmed[0] == '-')
    {
        trimmed = trimmed.substr(1);
    }
    trimmed.erase(0, trimmed.find_first_not_of('0'));

    if (trimmed.empty())  // 如果结果为空字符串，说明原数是 0
    {
        os << '0';
    }
    else
    {
        if (num.integer[0] == '-')  // 如果原数是负数，在结果前加上负号
        {
            os << '(' << '-' << trimmed << ')';
        }
        else 
        {
            os << trimmed;
        }
        
    }
    return os;
}


int main()
{
    int t;
    char op;
    CBigInteger bigNum1;
    CBigInteger bigNum2;

    cin >> t;
    while (t--)
    {
        cin >> bigNum1 >> op >> bigNum2;
        cout << bigNum1 << " " << op << " " << bigNum2 << " = ";
        if (op == '+')
            cout << bigNum1 + bigNum2 << endl;
        else if (op == '-')
            cout << bigNum1 - bigNum2 << endl;
        else if (op == '*')
            cout << bigNum1 * bigNum2 << endl;
    }
    return 0;
}
