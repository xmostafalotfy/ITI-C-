#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class list {
    T* items;
    int size;

public:
    static int listsNum;

    list() {
        this->size = 0;
        items = nullptr;
        listsNum++;
    }

    list(T arr[],int arrSize) {
        this->size = arrSize;

        if (size > 0) {
            this->items = new T[size];

            for (int i = 0; i < size; i++) {
                this->items[i] = arr[i];
            }
        } else
            this->items = nullptr;

        listsNum++;
    }


    list(const list& l) {
        this->size = l.size;

        if (size > 0) {
            this->items = new T[size];

            for (int i = 0; i < size; i++) {
                this->items[i] = l.items[i];
            }
        } else
            this->items = nullptr;

        listsNum++;
    }

    list& operator=(const list& l) {
        if (this == &l)
            return *this;

        delete[] items;
        this->size = l.size;

        if (size > 0) {
            this->items = new T[size];
            for (int i = 0; i < size; i++) {
                this->items[i] = l.items[i];
            }
        } else
            this->items = nullptr;

        return *this;
    }

    char operator==( list& l){
        if (this->size == l.size){
            for(int i = 0; i < size; i++){
                if (this->items[i]!=l.items[i])
                    return 0;
            }
            return 1;
        }
        return 0;
    }

    char operator<(const list& l)  {
        if (this->size < l.size)
            return 1;
        else
            return 0;
    }

    bool operator>(const list& l)  {
        if (this->size > l.size)
            return 1;
        else
            return 0;
    }

    list slice(int startIndex, int endIndex, int counter)  {
        if(endIndex == -1)
        endIndex = this->size;

        if (startIndex < 0 || endIndex >= this->size || startIndex > endIndex) {
            throw "Error: out of index range";
        }
        list temp ;
        for(int i = startIndex; i < endIndex; i+=counter){
            temp.items[i] = this->items[i];
        }
        temp.size = endIndex - startIndex;

        return temp;
    }

    void insert(int index, T data) {
        if (index < 0 || index > size) {
            throw "Wrong Index...!";
        }

        T* newItems = new T[size + 1];
        for (int i = 0; i < size + 1; i++) {
            if (i == index)
                newItems[i] = data;
            else if (i > index)
                newItems[i] = items[i - 1];
            else
                newItems[i] = items[i];
        }

        delete[] items;
        items = newItems;
        size++;
    }

    void push(T data) {
        T* newItems = new T[size + 1];
        for (int i = 0; i < size; i++) {
            newItems[i] = items[i];
        }
        newItems[size] = data;

        delete[] items;
        items = newItems;
        size++;
    }

    int pop() {
        if (size == 0)
            throw "Stack is Empty";

        T* newItems = new T[size - 1];
        for (int i = 0; i < size - 1; i++) {
            newItems[i] = items[i];
        }
        T value = items[size - 1];
        delete[] items;

        items = newItems;
        size--;
        return value;
    }

    int remove(int index) {
        if (index < 0 || index >= size) {
            throw "Index out of range";
        }

        T x = items[index];
        T* newItems = new T[size - 1];
        for (int i = 0; i < size - 1; i++) {
            if (i >= index)
                newItems[i] = items[i + 1];
            else
                newItems[i] = items[i];
        }

        delete[] items;
        items = newItems;
        size--;
        return x;
    }

    void display() const {
        if (size == 0)
            cout << "List is empty." << endl;

        for (int i = 0; i < size; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    int len()  {
        return size;
    }

    ~list() {
        delete[] items;
        listsNum--;
    }
};

template<class T>
int list<T>::listsNum = 0;

int main() {
    list<int> l1;
    l1.push(5.5);
    l1.display();

    list<string> l2;
    l2.push("test");
    l2.push("done");
    l2.push("aaaaaaaaaaaaaaaaah");
    l2.display();
    return 0;
}