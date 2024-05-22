#include <iostream>
#include <string>
using namespace std;
class Document {
protected:
    string name;

public:
    Document(const string& n) : name(n) {
        cout << "Create Document Class" << endl;
    }

    ~Document() {
        cout << "Delete Document Class" << endl;
    }
};

class Book : public Document {
private:
    int pageCount;

public:
    Book(const string& n, int pc) : Document(n), pageCount(pc) {
        cout << "Create Book Class" << endl;
    }

    ~Book() {
        cout << "Delete Book Class" << endl;
    }

    void Print() {
        cout << "Document Name is " << name << endl;
        cout << "PageCount is " << pageCount << endl;
    }
};

int main() {
    string name;
    int pageCount;
    cin >> name >> pageCount;

    Book book(name, pageCount);
    book.Print();

    return 0;
}
