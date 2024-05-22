#include <iostream>
using namespace std;
struct SRect
{
    int x1, y1;
    int x2, y2;
    void get()
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
        {
            swap(x1, x2);
        }
        if (y1 > y2)
        {
            swap(y1, y2);
        }
        
    }
};

bool isoverlap(const SRect &rect1, const SRect &rect2)
{
    if (rect1.x1 > rect2.x2||rect1.x2 < rect2.x1||rect1.y1 > rect2.y2||rect1.y2 < rect2.y1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        SRect a, b;
        a.get();
        b.get();
        if (isoverlap(a, b))
        {
            cout << "overlapped" << endl;
        }
        else
        {
            cout << "not overlapped" << endl;
        }
    }
    
}