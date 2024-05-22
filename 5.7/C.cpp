#include<iostream>
#include<string>
using namespace std;

class Lesson {
private:
	string id;
	double score;
	double credit;
public:
	Lesson() {}
	Lesson(string i, double c, double s)
    {	id = i;	score = s;	credit = c;	}
	double getScore() 
    {	return score;	}
	double getCredit()
    {	return credit;	}
};

class Student {
private:
	string id;
	string name;
	int type;
	int lesson_num;
	double total_credit;
	Lesson* les;
public:
	Student(string i, string n, int t);
	Student(const Student& stu);
	~Student() 
    {	delete[] les;	}
	void record();
	void count();
	void display(char op);
};
//以下填空完成类Student的5个成员函数定义（析构函数已经定义，无需再写）
//注意，类成员函数在类外实现，函数首部要带....
/********** Write your code here! **********/
Student::Student(string i, string n, int t)
{
    id = i;
    name = n;
    t = type;
}
Student::Student(const Student& stu)
{
    this->name = stu.name;
    this->type = 1;
    this->id = "2023" + stu.id;
    int passed_lessons = 0;
    for (int i = 0; i < stu.lesson_num; ++i) {
        if (stu.les[i].getScore() >= 60) {
            passed_lessons++;
        }
    }
    this->lesson_num = passed_lessons;
    this->les = new Lesson[passed_lessons];
    int index = 0;
    for (int i = 0; i < stu.lesson_num; ++i) {
        if (stu.les[i].getScore() >= 60) {
            this->les[index++] = stu.les[i];
        }
    }
}
void Student::record()
{
    cin >> lesson_num;
    les = new Lesson[lesson_num];
    string id;
    double score;
    double credit;
    for (int i = 0; i < lesson_num; i++)
    {
        cin >> id >> credit >> score;
        les[i] = Lesson(id, credit, score);
    }
}
void Student::count()
{
    total_credit = 0;
    for (int i = 0; i < lesson_num; i++)
    {
        if (les[i].getScore() >= 60)
        {
            total_credit += les[i].getCredit();
        }
    }
}
void Student::display(char op)
{
    if (op == 'D')
    {
        cout << id << " " << name << " ";
        if (type == 1)
        {
            cout << "postgraduate" << endl;
        }
        else
        {
            cout << "undergraduate" << endl;
        }
    }
    else if (op == 'C')
    {
        cout << id << " " << name << " ";
        if (type == 1)
        {
            cout << "postgraduate ";
        }
        else
        {
            cout << "undergraduate ";
        }
        cout << lesson_num << " " << total_credit << endl;
    }
}

/*******************************************/
//主函数
int main() {
	int t;
	string id, name;
	char op1, op2;
	cin >> t;
	while (t--) {
		cin >> id >> name;
		Student under_stu = Student(id, name, 0);
		under_stu.record();
		under_stu.count();
		Student post_stu = Student(under_stu);
		post_stu.count();

		cin >> op1 >> op2;
		under_stu.display(op1);
		post_stu.display(op2);
	}
	return 0;
}
