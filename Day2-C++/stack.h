#include <iostream>

using namespace std;

typedef struct Employee {
    int id;
    string name;
    int salary;
} Employee;

class Stack {
    Employee *items;
    int top;
    int size;

public:
    static int stacksNum; 

    Stack(int size);

    int push(int id, const string& name, int salary);

    int current();

    Employee pop();

    void display();

    ~Stack();
};
