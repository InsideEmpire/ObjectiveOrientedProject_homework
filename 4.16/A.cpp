#include <iostream>
using namespace std;
class Student
{

private:
    int id; // 学号
    int score; // 成绩
    static int maxscore; // 最高分数
    static int maxid; // 最高分数学生学号
public:
    Student(int ti = 0, int ts = 0):id(ti), score(ts){}
    void get(int ti, int ts)
    {
        id = ti;
        score = ts;
    }
    static void findMax(Student &st); // 寻找最高成绩和学号
    static int getMaxScore(); // 返回最高成绩
    static int getMaxID(); // 返回最高成绩的学号
};

void Student::findMax(Student &st)
{
    if (st.score > Student::maxscore)
    {
        maxscore = st.score;
        maxid = st.id;
    }
    return;
}
int Student::getMaxScore()
{
    return maxscore;
}
int Student::getMaxID()
{
    return maxid;
}
int Student::maxscore = 0; // 最高分数
int Student::maxid = 0; // 最高分数学生学号
int main()
{
    int t;
    cin >> t;
    Student *p = new Student[t];
    for(int i = 0;i < t;i++)
    {
        int score, id;
        cin >> id >> score;
        p[i].get(id, score);
        p[i].findMax(p[i]);
    }
    cout << Student::getMaxID() << "--" << Student::getMaxScore() << endl;
}