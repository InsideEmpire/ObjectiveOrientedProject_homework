#include <iostream>

using namespace std;

class Tree {
public:
    Tree(); 
    Tree(int age);
    void grow(int years);
    void age();

private:
    int ages;
};

Tree::Tree() {
    ages = 1;
}

Tree::Tree(int age) {
    ages = age;
}

void Tree::grow(int years) {
    ages += years;
}

void Tree::age() {
    cout << ages << endl;
}

int main() {
    int years1, age2, years2;
    cin >> years1 >> age2 >> years2;

    Tree tree1;
    tree1.grow(years1);
    tree1.age();

    Tree tree2(age2);
    tree2.grow(years2);
    tree2.age();

    return 0;
}
