#include <iostream>
using namespace std;
class Cat
{
    private:
    string name;
    int weight;
    public:
    void get()
    {
        cin >> name >> weight;
    }
    int getweight()
    {
        return weight;
    }
    void print()
    {
        cout << name;
    }
};
void cmp(Cat &a, Cat &b)
{
    if(a.getweight() > b.getweight())
    {
        Cat tem;
        tem = a;
        a = b;
        b = tem;
    }
}
int main()
{
    int n;
    cin >> n;
    Cat *cats = new Cat[n];
    for(int i = 0;i < n;i++)
    {
        cats[i].get();
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n - i - 1;j++)
        {
            cmp(cats[j], cats[j + 1]);
        }
    }
    for(int i = 0;i < n - 1;i++)
    {
        cats[i].print();
        cout << ' ';
    }
    cats[n - 1].print();
    cout << endl;
    return 0;
}