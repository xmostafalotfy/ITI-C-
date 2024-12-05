#include <iostream>


using namespace std;
/*

constructor / des

len
= overload
cin cout << >> overload
+ concat

*/

class String
{
private:
    char *ptr = nullptr;
    int size = 0;

public:
    friend ostream &operator<<(ostream &out, const String &st);

    friend istream &operator>>(istream &in, String &st);

    String()
    {
    }

    String(const char *st)
    {
        int counter = 0;

        while (st[counter] != '\0')
        {
            counter++;
        }

        size = counter;
        ptr = new char[size + 1];

        for (int i = 0; i < size; i++)
        {
            ptr[i] = st[i];
        }
        ptr[size] = '\0';
    }

    void operator=(const char *st)
    {
        int counter = 0;

        while (st[counter] != '\0')
        {
            counter++;
        }

        size = counter;
        ptr = new char[size + 1];

        for (int i = 0; i < size; i++)
        {
            ptr[i] = st[i];
        }
        ptr[size] = '\0';
    }

    String &operator=(String &other)
    {

        if (this != &other)
        {

            delete[] ptr;
            size = other.size;
            ptr = new char[size];

            for (int i = 0; i < size; i++)
            {
                ptr[i] = other.ptr[i];
            }
        }
        return *this;
    }

    String operator+(String &other)
    {
        String result;
        int newSize = size + other.size;
        result.ptr = new char[newSize];
        result.size = newSize;
        for (int i = 0; i < size; i++)
        {
            result.ptr[i] = ptr[i];
        }
        for (int i = 0; i < other.size; i++)
        {
            result.ptr[size + i] = other.ptr[i];
        }
        result.ptr[newSize] = '\0';
        return result;
    }

    int len()
    {
        return size;
    }

    char operator[](int index)
    {
        if (index < size && index >= 0)
            return ptr[index];
        else
            throw "Out of index range";
    }

    String& slice(int startIndex=0,int endIndex=-1,int counter=1) {
        if(endIndex == -1)
        endIndex = this->size;
        if (startIndex < 0 || endIndex >= this->size || startIndex > endIndex) {
            throw "Error: out of index range";
        }
        String temp ;
        for(int i = startIndex; i < endIndex; i+=counter){
            temp.ptr[i] = this->ptr[i];
        }
        temp.size = endIndex - startIndex;
        temp.ptr[temp.size] = '\0';

        return temp;
    }

    char operator<(String &s){
        if(s.len()<this->len())
        return 0;
        else
        return 1;
    }

    char operator>(String &s){
        if(s.len()>this->len())
        return 0;
        else
        return 1;
    }

    char operator==(String &s){
        if (this->size == s.size){
            for(int i = 0; i < size; i++){
                if (this->ptr[i]!=s.ptr[i])
                    return 0;
            }
            return 1;
        }
        return 0;
    }


    ~String()
    {
        delete[] ptr;
    }
};

ostream &operator<<(ostream &out, const String &st)
{
    for (int i = 0; i < st.size; i++)
    {
        out << st.ptr[i];
    }
    return out;
};

istream &operator>>(istream &in, String &st)
{

    char buffer[1000];
    in >> buffer;

    delete[] st.ptr;
    int length = 0;
    while (buffer[length] != '\0')
    {
        length++;
    }

    st.ptr = new char[length + 1];
    st.size = length;

    for (int i = 0; i < length; i++)
    {
        st.ptr[i] = buffer[i];
    }
    st.ptr[length] = '\0';

    return in;
};

int main() {   

    return 0;
}
