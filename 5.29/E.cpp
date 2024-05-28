#include <iostream>
#include <string>
#include <algorithm> // For reverse

using namespace std;

// 辅助函数：字符串加法
string add(const string& num1, const string& num2) {
    string result;
    int carry = 0;
    int i = num1.size() - 1, j = num2.size() - 1;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += to_string(sum % 10);
    }
    
    reverse(result.begin(), result.end()); // 反转结果
    return result;
}

// 辅助函数：字符串减法
string subtract(const string& num1, const string& num2) {
    string result;
    int borrow = 0;
    int i = num1.size() - 1, j = num2.size() - 1;
    
    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += to_string(diff);
    }
    
    reverse(result.begin(), result.end()); // 反转结果
    // 去掉前导零
    result.erase(0, result.find_first_not_of('0'));
    return result.empty() ? "0" : result;
}

// 辅助函数：字符串乘法
string multiply(const string& num1, const string& num2) {
    string result(num1.size() + num2.size(), '0');
    
    for (int i = num1.size() - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; j >= 0; --j) {
            int sum = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            result[i + j + 1] = sum % 10 + '0';
            carry = sum / 10;
        }
        result[i] += carry;
    }
    
    // 去掉前导零
    result.erase(0, result.find_first_not_of('0'));
    return result.empty() ? "0" : result;
}

int main() {
    string num1 = "123456789";
    string num2 = "987654321";

    cout << "加法结果：" << add(num1, num2) << endl;
    cout << "减法结果：" << subtract(num1, num2) << endl;
    cout << "乘法结果：" << multiply(num1, num2) << endl;

    return 0;
}
