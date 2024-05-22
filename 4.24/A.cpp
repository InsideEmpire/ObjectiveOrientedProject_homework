#include <iostream>
#include <cmath>
using namespace std;

class Polygon
{
protected:
    int number = 0;           // 边数，最多不超过100条边
    int side_length[100]; // 边长数组

public:
    Polygon() : number(0) {}

    void get(int len)
    {
        side_length[number] = len;
        number++;
    }

    int perimeter()//计算多边形边长
    {
        int len_total = 0;
        for(int i = 0;i < number;i++)
        {
            len_total += side_length[i];
        }
        return len_total;
    }

    void display()//输出多边形边数和周长
    {
        cout << number << " " << perimeter() << endl;
    }
};

class Rectangle : public Polygon
{
private:
    int height;
    int width;

public:
    Rectangle(int h, int w) : height(h), width(w)
    {
        number = 4;
        side_length[0] = side_length[2] = height;
        side_length[1] = side_length[3] = width;
    }

    int perimeter()
    {
        return 2 * (height + width);
    }

    void display()
    {
        cout << number << " " << perimeter() << endl;
    }
};

class EqualPolygon : public Polygon
{
private:
    int side_len;

public:
    EqualPolygon(int sides, int len) : side_len(len)
    {
        number = sides;
        for (int i = 0; i < number; ++i)
        {
            side_length[i] = len;
        }
    }

    int perimeter()
    {
        return number * side_len;
    }

    void display()
    {
        cout << number << " " << perimeter() << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            Polygon tem;
            int len;
            cin >> len;
            while (len != -1)
            {
                tem.get(len);
                cin >> len;
            }
            tem.display();
        }
        if (type == 1)
        {
            int h, w;
            cin >> h >> w;
            Rectangle tem(h, w);
            tem.display();
        }
        if (type == 2)
        {
            int s, l;
            cin >> s >> l;
            EqualPolygon tem(s, l);
            tem.display();
        }
        
    }
    
    return 0;
}
