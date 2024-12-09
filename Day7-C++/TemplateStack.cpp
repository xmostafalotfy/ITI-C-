#include <iostream>
using namespace std;
template <class T>

class Stack
{
    T *items;
    int top;
    int size;

public:

    static int stacksNum;

    Stack(int size)
    {
        this->size = size;
        items = new T[size];
        top = -1;
        stacksNum++;
    }

    Stack(Stack &s)
    {
        this->size = s.size;
        this->top = s.top;
        items = new T[size];
        for(int i = 0; i <= top ; i++)
        {
            this->items[i]=(s.items)[i];
        }
        stacksNum++;
    }

    int push(T data){
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


    void display() {
        if (this->top == -1)
            cout << "Stack is empty." << endl;

        for (int i = this->top; i >= 0; i--)
        {
            cout << this->items[i] << "\t";
        }
    }



    ~Stack()
    {
        delete[] items;
        stacksNum--;
        cout << "Cya .." << endl;
    }
};

template<class T>
int Stack<T> ::stacksNum = 0;



int main()
{
    Stack<int> b(3);
    b.push(5);
    b.push(3);
    b.display();

    Stack<char> f(4);
    f.push('m');
    f.push('o');
    f.push('s');
    f.display();
    

    Stack<string> s(7);
    s.push("test");
    s.push("test2");
    s.display();


    return 0;
}
