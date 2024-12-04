#include <iostream>
using namespace std;

class Complex {
    int real;
    int img;

    public:
    Complex(int real=0,int img = 0){
        this -> real = real;
        this -> img = img;
    }


    void set_real(int newReal) {
        real = newReal;
    }

    void set_img(int newImg) {
        img = newImg;
    }

    void set_complex(int real,int img){
        this -> real = real;
        this -> img = img;
    }

    int get_real() {
        return real;
    }

    int get_img() {
        return img;
    }

    Complex add(Complex c) {
        Complex newObj;
        newObj.set_real(real + c.get_real());
        newObj.set_img(img + c.get_img());
        return newObj;
    }

    Complex sub(Complex& c) {
        Complex newObj;
        newObj.set_real(real - c.get_real());
        newObj.set_img(img - c.get_img());
        return newObj;
    }

    void display() {
        if (real != 0)
           cout<<real;

        if (img > 0)
             cout << (real != 0 ? "+" : "") << img<<"i"<<endl;
        else if(img < 0)
            cout<<img<<"i"<<endl;
    }

    Complex operator+(Complex c){
        Complex x;
        x.real = this->real + c.real;
        x.img = this->img + c.img;
        return x;
    }

    Complex operator-(Complex c){
        Complex x;
        x.real = this->real - c.real;
        x.img = this->img - c.img;
        return x;
    }


    Complex operator++(){ // ++c
        this->real++;
        this->img++;
        return *this; 
    }

    Complex operator--(){ // --c
        this->real--;
        this->img--;
        return *this; 
    }


    Complex operator++(int n){
    Complex c =*this;
    this->real++;
    this->img++;
    return c;   
    }

    Complex operator--(int n){ 
    Complex c =*this;
    this->real--;
    this->img--;
    return c;   
    }

    Complex operator+(int x){ // c1+5
    this-> real += x;
    return *this;
    }

    Complex operator-(int x){ // c1+5
    this-> real -= x;
    return *this;
    }


    friend Complex operator+(int n,Complex c);

    friend Complex operator-(int n,Complex c);


    char operator==(Complex c){
        if(real == c.real && img == c.img)
        return 1;
        else
        return 0;
    }

    Complex operator+=(Complex c)
    {
        this->real+=c.real;
        this->img+=c.img;
        return *this;

    }

    // operator float() {
    //     i don't know what implementation to type
    // } 



    ~Complex(){
        cout<<"goodbye ;("<<endl;
    }

};

Complex operator+(int n,Complex c){
    c.real += n;
    return c;
};

Complex operator-(int n,Complex c){
    c.real -= n;
    return c;
};

int main() {
    Complex c;
    c.set_real(10);
    c.set_img(15);
    Complex x;
    x.set_real(10);
    x.set_img(15);
}





