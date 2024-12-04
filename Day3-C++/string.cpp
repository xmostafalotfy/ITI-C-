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

friend ostream& operator<<(ostream& out, const String& st);

friend istream& operator>>(istream& in, String& st);



    String(){

    }

    String(const char *st){
        int counter = 0;

        while (st[counter]!='\0'){
            counter++;
        }

        size = counter;
        ptr = new char[size+1];

        for (int i = 0;i<size;i++){
            ptr[i] = st[i];
        }
        ptr[size] = '\0';
    }

    void operator=(const char *st) {
        int counter = 0;

        while (st[counter]!='\0'){
            counter++;
        }

        size = counter;
        ptr = new char[size+1];

        for (int i = 0;i<size;i++){
            ptr[i] = st[i];
        }
        ptr[size] = '\0';
    }

    String& operator=(const String &other) {

    if (this != &other) {

        delete[] ptr;
        size = other.size;
        ptr = new char[size];

        for (int i = 0; i < size; i++) {
            ptr[i] = other.ptr[i];
        }
    }
    return *this;
    }

    String operator+(const String &other)const{
        String result;
        int newSize = size + other.size;
        result.ptr = new char[newSize];
        result.size = newSize;
        for(int i = 0; i<size;i++){
            result.ptr[i] = ptr[i];
        }
        for(int i =0;i<other.size;i++){
            result.ptr[size+i] = other.ptr[i];
        }
        result.ptr[newSize] = '\0';
        return result;
    }

    int len(){
        return size;
    }

    char operator[](int index) {
    return ptr[index];
    }


    ~String(){
        delete[] ptr;
    }
};

ostream& operator<<(ostream& out, const String& st)
{
    for(int i = 0;i<st.size;i++){
        out << st.ptr[i];
    }
    return out;
};

istream& operator>>(istream& in, String& st){

    char buffer[1000]; 
    in >> buffer;

    delete[] st.ptr;
    int length = 0;
    while (buffer[length] != '\0') {
        length++;
    }

    st.ptr = new char[length + 1];
    st.size = length;

    for (int i = 0; i < length; i++) {
        st.ptr[i] = buffer[i];
    }
    st.ptr[length] = '\0';

    return in;

};


int main(){
    // String x("test");
    // cout<<x.len();
    // cout<<x;
    // cout<<x[1];
    // String y("no");
    // cout<<endl;
    // x=y;
    // cout<<x;
    String x,y;
    // x = "123";
    // y = "456";
    // y = x+y;
    // cout<<y<<endl;
    // cout<<x<<endl;
    cin >> x;
    cout<<"\n"<<x<<endl;
    return 0;
}
