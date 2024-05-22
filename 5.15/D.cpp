#include <iostream>
#include <string>

using namespace std;

class Student
{
protected:
    string name;
    int student_id;

public:
    Student(string n, int id) : name(n), student_id(id) {}

    virtual int calculate_tuition()
    {
        return 2000;
    }

    virtual void display()
    {
        cout << name << " " << student_id << " " << calculate_tuition() << endl;
    }
};

class GraduateStudent : public Student
{
private:
    string advisor;

public:
    GraduateStudent(string n, int id, string a) : Student(n, id), advisor(a) {}

    int calculate_tuition() override
    {
        return 1000;
    }

    void display() override
    {
        cout << name << " " << student_id << " " << advisor << " " << calculate_tuition() << endl;
    }
};

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        char s_type;
        string name, advisor;
        int student_id;
        cin >> s_type >> student_id >> name;
        if (s_type == 'S')
        {
            Student s(name, student_id);
            s.display();
        }
        else if (s_type == 'G')
        {
            cin >> advisor;
            GraduateStudent gs(name, student_id, advisor);
            gs.display();
        }
    }

    return 0;
}
