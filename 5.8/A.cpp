#include <iostream>
#include <string>
using namespace std;

class CPeople {
protected:
    string name;
    char sex;
    int age;
public:
    CPeople(string _name, char _sex, int _age) : name(_name), sex(_sex), age(_age) {}
    void print() const {
        cout << "Name: " << name << endl;
        cout << "Sex: " << sex << endl;
        cout << "Age: " << age << endl;
    }
};

class CStudent : virtual public CPeople {
protected:
    string studentNo;
    float score;
public:
    CStudent(string _name, char _sex, int _age, string _studentNo, float _score)
        : CPeople(_name, _sex, _age), studentNo(_studentNo), score(_score) {}
    void print() const {
        cout << "Student:" << endl;
        CPeople::print();
        cout << "No.: " << studentNo << endl;
        cout << "Score: " <<score << endl;
    }
};

class CTeacher : virtual public CPeople {
protected:
    string position;
    string department;
public:
    CTeacher(string _name, char _sex, int _age, string _position, string _department)
        : CPeople(_name, _sex, _age), position(_position), department(_department) {}
    void print() const {
        cout << "Teacher:" << endl;
        CPeople::print();
        cout << "Position: " << position << endl;
        cout << "Department: " << department << endl;
    }
};

class CGradOnWork : public CStudent, public CTeacher {
protected:
    string direction;
    string tutor;
public:
    CGradOnWork(string _name, char _sex, int _age, string _studentNo, float _score,
                string _position, string _department, string _direction, string _tutor)
        : CPeople(_name, _sex, _age), CStudent(_name, _sex, _age, _studentNo, _score),
        CTeacher(_name, _sex, _age, _position, _department), direction(_direction), tutor(_tutor) {}
    void print() const {
        CPeople::print();
        cout << endl;
        CStudent::print();
        cout << endl;
        CTeacher::print();
        cout << endl;
        cout << "GradOnWork:" << endl;
        CPeople::print();
        cout << "No.: " << CStudent::studentNo << endl;
        cout << "Score: " << CStudent::score << endl;
        cout << "Position: " << CTeacher::position << endl;
        cout << "Department: " << CTeacher::department << endl;
        cout << "Direction: " << direction << endl;
        cout << "Tutor: " << tutor << endl;
    }
};

int main() {
    string name, studentNo, position, department, direction, tutor;
    char sex;
    int age;
    float score;

    cin >> name >> sex >> age;
    cin >> studentNo >> score;
    cin >> position >> department;
    cin >> direction >> tutor;
    CGradOnWork grad(name, sex, age, studentNo, score, position, department, direction, tutor);

    cout << "People:" << endl;
    
    grad.print();
    cout << endl;

    return 0;
}
