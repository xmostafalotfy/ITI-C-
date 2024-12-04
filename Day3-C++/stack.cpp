#include <iostream>
using namespace std;

class Stack
{
    int *items;
    int top;
    int size;

public:
    static int stacksNum;

    Stack(int size)
    {
        this->size = size;
        items = new int[size];
        top = -1;
        stacksNum++;
    }

    Stack(Stack &s) // infinity loop if called by value
    {
        this->size = s.size;
        this->top = s.top;
        items = new int[size];
        for(int i = 0; i <= top ; i++)
        {
            this->items[i]=(s.items)[i];
        }
        stacksNum++;
    }

    int push(int data){
        if (top == size - 1)
            return 0;

        else{
            items[++top] = data;
            return 1;
        }
    }


    double pop(){
        if (top != -1)
            return items[top--];
            
        else
            throw "Stack is Empty";
    }


    friend void display(Stack &s);


    ~Stack()
    {
        delete[] items;
        stacksNum--;
        cout << "Cya .." << endl;
    }
};

int Stack::stacksNum = 0;

void display(Stack &s) // if stack called by value destructor called twice, when fucntion end and when program end
{
    if (s.top == -1)
        cout << "Stack is empty." << endl;

    for (int i = s.top; i >= 0; i--)
    {
        cout << s.items[i] << "\t";
    }
}

int main()
{
    return 0;
}