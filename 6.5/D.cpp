#include <iostream>
using namespace std;

template <class T>
int repeatTime(T *arr, int n, int index)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[index])
        {
            count++;
        }
    }
    return count;
}

template <class T>
void findMost(T *arr, int n)
{
    int max = 0;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (repeatTime(arr, n, i) > max)
        {
            max = repeatTime(arr, n, i);
            index = i;
        }
    }
    cout << arr[index] << " " << max << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string type;
        cin >> type;
        int n;
        cin >> n;
        if (type == "I")
        {
            int *a = new int[n + 1];
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            findMost(a, n);
        }
        if (type == "S")
        {
            string *a = new string[n + 1];
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            findMost(a, n);
        }
        if (type == "C")
        {
            char *a = new char[n + 1];
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            findMost(a, n);
        }
    }
}