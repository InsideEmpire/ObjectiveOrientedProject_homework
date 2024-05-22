#include <iostream>
using namespace std;
struct Student
{
    string name;
    int age;
    int score;
    void get()
    {
        cin >> name >> age >> score;
    }
    void print()
    {
        cout << name << ' ' << age << ' ' << score << endl;
    }
}students[101];
void swapstudent(Student &a, Student &b)
{
    string temp;
    int tema;
    int tems;
    temp = a.name;
    a.name = b.name;
    b.name = temp;
    tema = a.age;
    a.age = b.age;
    b.age = tema;
    tems = a.score;
    a.score = b.score;
    b.score = tems;
}
int main()
{
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        students[i].get();

    }
    for(int i = 1;i <= t;i++)
    {
        for(int j = 1;j <= t - i;j++)
        {
            if (students[j].score > students[j + 1].score)
            {
                swapstudent(students[j], students[j + 1]);
            }
            else if (students[j].score == students[j + 1].score&&students[j].name > students[j + 1].name)
            {
                swapstudent(students[j], students[j + 1]);
            }
            
        }
    }
    for(int i = 1;i <= t;i++)
    {
        students[i].print();
    }
}