#include <iostream>
using namespace std;
class Bulk
{
    private:
    int length;
    int width;
    int height;
    public:
    void get()
    {
        cin >> length >> width >> height;
    }
    void print()
    {
        cout << length * width * height << endl << 2 * (length * width + length * height + width * height);
    }
};
int main()
{
    Bulk tem;
    tem.get();
    tem.print();
    return 0;
}