#include <iostream>
using namespace std;
class Song
{
private:
    string singer;
    string title;
    int length;
public:
    Song()
    {
        cout << "constructor\n";
    }
    Song(string S, string T, int L):singer(S),title(T),length(L)
    {
        cout << "constructor\n";
    }
    void set()
    {
        cin >> singer >> title >> length;
    }
    void print()
    {
        cout << singer << "'s song-" << title << " lasts for " << length << " minutes\n";
    }
    ~Song()
    {
        cout << "destructor\n";
    }
    int getLength(){return length;}
};
int Select(Song s[],int n)
{
    int longest = 0;
    int index;
    for(int i = 0;i < n;i++)
    {
        if (s[i].getLength() > longest)
        {
            longest = s[i].getLength();
            index = i;
        }
        
    }
    return index;
}
int main()
{
    int n;
    cin >> n;
    Song *s = new  Song[n];
    for (int i = 0; i < n; i++)
    {
        s[i].set();
    }
    s[Select(s, n)].print();
    delete[] s;
}