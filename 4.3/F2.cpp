#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class STR {
private:
    char *s;

public:
    STR(char *t) {
        s = new char[strlen(t) + 1]; // 分配内存空间，加1是为了存储末尾的空字符 '\0'
        strcpy(s, t); // 复制字符串内容
    }

    ~STR() {
        delete[] s; // 释放内存空间
    }

    void backward(char *t1, char *t2) {
        while (t1 < t2) {
            char tem = *t1;
            *t1 = *t2;
            *t2 = tem;
            t1++;
            t2--;
        }
    }

    void fun() {
        char *t1 = s;
        char *t2;
        for (int i = 0; i <= strlen(s); i++) { // 注意循环条件，等号是为了处理字符串末尾的 '\0'
            if (s[i] == ' ' || s[i] == '\0') {
                t2 = (s + i - 1);
                backward(t1, t2);
                t1 = (t2 + 2);
            }
        }
    }

    void print() {
        cout << s;
    }
};

int main() {
    string input;
    getline(cin, input); // 使用 getline 读取一行字符串

    char *s = new char[input.length() + 1]; // 分配内存空间
    strcpy(s, input.c_str()); // 将 string 转换为 C 风格字符串

    STR string(s);
    string.fun();
    string.print();

    delete[] s; // 释放内存空间

    return 0;
}
