#include <iostream>
using namespace std;
class CRect;
class CPoint
{
public:
    CPoint(int tx = 0, int ty = 0) : x(tx), y(ty) {}
    
    friend class CRect;
    friend bool isNotOverlapped(const CRect &rect1, const CRect &rect2);
    private:
    int x;
    int y;
};

class CRect
{
private:
    CPoint p1;
    CPoint p2;

public:
    CRect(const CPoint &tp1, const CPoint &tp2) : p1(tp1), p2(tp2) {}

    friend bool isNotOverlapped(const CRect &rect1, const CRect &rect2);
};
bool isNotOverlapped(const CRect &rect1, const CRect &rect2)
{
    int x1min = min(rect1.p1.x, rect1.p2.x);
    int x1max = max(rect1.p1.x, rect1.p2.x);
    int y1min = min(rect1.p1.y, rect1.p2.y);
    int y1max = max(rect1.p1.y, rect1.p2.y);

    int x2min = min(rect2.p1.x, rect2.p2.x);
    int x2max = max(rect2.p1.x, rect2.p2.x);
    int y2min = min(rect2.p1.y, rect2.p2.y);
    int y2max = max(rect2.p1.y, rect2.p2.y);

    if (x1max < x2min || x2max < x1min || y1max < y2min || y2max < y1min)
    {
        return true; // 两个矩形不重叠
    }
    else
    {
        return false; // 两个矩形重叠
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        CPoint p1(x1, y1);
        CPoint p2(x2, y2);

        CRect rect1(p1, p2);

        cin >> x1 >> y1 >> x2 >> y2;
        CPoint p3(x1, y1);
        CPoint p4(x2, y2);

        CRect rect2(p3, p4);

        if (isNotOverlapped(rect1, rect2))
        {
            cout << "not overlapped" << endl;
        }
        else
        {
            cout << "overlapped" << endl;
        }
    }

    return 0;
}
