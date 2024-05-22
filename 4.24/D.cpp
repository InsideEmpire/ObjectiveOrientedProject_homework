#include <iostream>
#include <string>

class CPerson {
protected:
    std::string name;
    std::string phone;

public:
    CPerson(std::string n, std::string p) : name(n), phone(p) {}

    std::string getName() const {
        return name;
    }

    std::string getPhone() const {
        return phone;
    }
};

class Student : public CPerson {
protected:
    int Atime[12];

public:
    Student(std::string n, std::string p, int A[]) : CPerson(n, p) {
        for (int i = 0; i < 12; ++i) {
            Atime[i] = A[i];
        }
    }

    void check() const {
        int totalHours = 0;
        for (int i = 0; i < 12; ++i) {
            if (Atime[i] >= 60) {
                totalHours += 1;
            }
        }
        if (totalHours >= 10) {
            std::cout << getName() << "达到学时要求可以预约！电话" << getPhone() << std::endl;
        } else {
            std::cout << getName() << "未达到学时要求不能预约！电话" << getPhone() << std::endl;
        }
    }
};

class VIPStudent : public Student {
private:
    int Btime[12];

public:
    VIPStudent(std::string n, std::string p, int A[], int B[]) : Student(n, p, A) {
        for (int i = 0; i < 12; ++i) {
            Btime[i] = B[i];
        }
    }

    void check() const {
        int totalHours = 0;
        for (int i = 0; i < 12; ++i) {
            if (Atime[i] >= 60) {
                totalHours += 1;
            }
            if (Btime[i] >= 60) {
                totalHours += 2;
            }
        }
        if (totalHours >= 10) {
            std::cout << getName() << "达到学时要求可以预约！电话" << getPhone() << std::endl;
        } else {
            std::cout << getName() << "未达到学时要求不能预约！电话" << getPhone() << std::endl;
        }
    }
};

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        char type;
        std::string name, phone;
        std::cin >> type >> name >> phone;

        int A[12], B[12];

        if (type == 'F') {
            for (int i = 0; i < 12; ++i) {
                std::cin >> A[i];
            }
            Student student(name, phone, A);
            student.check();
        } else if (type == 'V') {
            for (int i = 0; i < 12; ++i) {
                std::cin >> A[i];
            }
            for (int i = 0; i < 12; ++i) {
                std::cin >> B[i];
            }
            VIPStudent vipStudent(name, phone, A, B);
            vipStudent.check();
        }
    }

    return 0;
}
