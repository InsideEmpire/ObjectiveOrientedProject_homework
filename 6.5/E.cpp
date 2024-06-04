#include <iostream>
#include <iomanip>
#include <unordered_map>
using namespace std;
template <typename T>
class CNode
{
public:
    T data;
    CNode *next;
};
template <typename T>
class CList
{
private:
    CNode<T> *head;

public:
    CList();
    void append(T a);
    void insert(T a, int n);
    void remove(int n);
    T get(int n);
    void set(T a, int n);
    void print();
    ~CList();
};
template <typename T>
CList<T>::CList()
{
    head = NULL;
}
template <typename T>
void CList<T>::append(T a)
{
    CNode<T> *p = new CNode<T>;
    p->data = a;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        CNode<T> *q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}
template <typename T>
void CList<T>::insert(T a, int n)
{
    if (n < 0)
    {
        return;
    }
    if (n == 0)
    {
        CNode<T> *p = new CNode<T>;
        p->data = a;
        p->next = head;
        head = p;
        return;
    }
    CNode<T> *p = new CNode<T>;
    p->data = a;
    p->next = NULL;
    CNode<T> *q = head;
    for (int i = 1; i < n; i++)
    {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
}
template <typename T>
void CList<T>::remove(int n)
{
    if (n <= 0)
    {
        return;
    }
    if (n == 1)
    {
        head = head->next;
        return;
    }
    CNode<T> *q = head;
    for (int i = 1; i < n - 1; i++)
    {
        q = q->next;
        if (q == NULL)
        {

            return;
        }
    }
    if (q->next == NULL || q->next->next == NULL)
    {

        return;
    }
    q->next = q->next->next;
}
template <typename T>
T CList<T>::get(int n)
{

    if (n <= 0)
    {
        cout << "error" << endl;
        return NULL;
    }
    CNode<T> *q = head;
    for (int i = 1; i < n; i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout << "error" << endl;
            return NULL;
        }
    }
    cout << q->data << endl;
    return q->data;
}
template <typename T>
void CList<T>::set(T a, int n)
{
    if (n <= 0)
    {
        return;
    }
    CNode<T> *q = head;
    for (int i = 1; i < n; i++)
    {
        q = q->next;
        if (q == NULL)
        {

            return;
        }
    }
    q->data = a;
}
template <typename T>
void CList<T>::print()
{
    CNode<T> *q = head;
    while (q->next != NULL)
    {
        cout << q->data << " ";
        q = q->next;
    }
    cout << q->data << endl;
}
template <typename T>
CList<T>::~CList()
{
    CNode<T> *p = head;
    while (p != NULL)
    {
        CNode<T> *q = p;
        p = p->next;
        delete q;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char type;
        cin >> type;
        if (type == 'I')
        {
            int a;
            cin >> a;
            int num[a];
            for (int j = 0; j < a; j++)
            {
                cin >> num[j];
            }

            CList<int> list;
            for (int j = 0; j < a; j++)
            {
                list.append(num[j]);
            }
            int b, b1;
            cin >> b >> b1;
            list.insert(b1, b);
            cin >> b;
            list.get(b);
            cin >> b;
            list.remove(b);
            cin >> b >> b1;
            list.set(b1, b);
            list.print();
        }
        if (type == 'D')
        {
            int a;
            cin >> a;
            double num[a];
            for (int j = 0; j < a; j++)
            {
                cin >> num[j];
            }
            CList<double> list;
            for (int j = 0; j < a; j++)
            {
                list.append(num[j]);
            }
            int b;
            double b1;
            cin >> b >> b1;
            list.insert(b1, b);
            cin >> b;
            list.get(b);
            cin >> b;
            list.remove(b);
            cin >> b >> b1;
            list.set(b1, b);
            list.print();
        }
        if (type == 'S')
        {
            int a;
            cin >> a;
            string num[a];
            for (int j = 0; j < a; j++)
            {
                cin >> num[j];
            }
            CList<string> list;
            for (int j = 0; j < a; j++)
            {
                list.append(num[j]);
            }
            int b;
            string b1;
            cin >> b >> b1;
            list.insert(b1, b);
            cin >> b;
            list.get(b);
            cin >> b;
            list.remove(b);
            cin >> b >> b1;
            list.set(b1, b);
            list.print();
        }
    }
}