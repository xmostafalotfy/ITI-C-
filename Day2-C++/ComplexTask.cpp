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

    ~Complex(){
        cout<<"goodbye ;("<<endl;
    }

};


int main() {
    Complex c;
    c.set_real(10);
    c.set_img(15);
    Complex x;
    x.set_real(10);
    x.set_img(15);
    Complex d(18,9);
    d.set_complex(12,16);
    d.display();
    Complex v = x.sub(c);
    cout << "Real: " << v.get_real() << endl;
    cout << "Imaginary: " << v.get_img() << endl;
    v.display();
    return 0;
}





