#include <iostream>
using namespace std;

template <typename T>
T Max(T arr[], int len)
{
    T maxVal = arr[0];
    for (int i = 1; i < len; ++i)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

template <typename T>
class Cryption
{
private:
    T ptxt[100]; // 明
    T ctxt[100]; // 密
    T key;       // 钥
    int len;     // 长

public:
    Cryption(T tk, T tt[], int tl);

    void Encrypt();

    void Print()
    {
        for (int i = 0; i < len - 1; i++)
        {
            cout << ctxt[i] << " ";
        }
        cout << ctxt[len - 1] << endl;
    }
};

template <typename T>
Cryption<T>::Cryption(T tk, T tt[], int tl) : key(tk), len(tl)
{
    for (int i = 0; i < len; ++i)
    {
        ptxt[i] = tt[i];
    }
}

template <typename T>
void Cryption<T>::Encrypt()
{
    T maxVal = Max(ptxt, len);
    for (int i = 0; i < len; ++i)
    {
        ctxt[i] = (maxVal - ptxt[i]) + key;
    }
}

int main()
{
    int i;
    int length;

    int ik, itxt[100];
    cin >> ik >> length;
    for (i = 0; i < length; i++)
        cin >> itxt[i];
    Cryption<int> ic(ik, itxt, length);
    ic.Encrypt();
    ic.Print();

    double dk, dtxt[100];
    cin >> dk >> length;
    for (i = 0; i < length; i++)
        cin >> dtxt[i];
    Cryption<double> dc(dk, dtxt, length);
    dc.Encrypt();
    dc.Print();

    char ck, ctxt[100];
    cin >> ck >> length;
    for (i = 0; i < length; i++)
        cin >> ctxt[i];
    Cryption<char> cc(ck, ctxt, length);
    cc.Encrypt();
    cc.Print();

    return 0;
}
