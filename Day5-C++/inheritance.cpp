#include <iostream>
using namespace std;

class Base 
{
    private:
        int base_priv; // accessed only in class base 
    protected:
        int base_protect; // base and it's childern
    public:
        int base_pub; // by all 

    Base()
    {
        cout<<"Default Base Constructor"<<endl;
    }
    Base(int a,int b)
    {
        cout<<"Parameterized Base Constructor"<<endl;
    }
    int sum (int a,int b){
        cout<<"Base sum"<<endl;
        return a+b;
    }

    void displayb(Base *b){
        cout<<"Display Base"<<endl;
    }

    ~Base()
    {
        cout<<"Base Destructor"<<endl;
    }
};
class Derived :public Base
{
    private:
        int d_priv;
    protected:
        int d_protect;
    public:
        int d_pub;

    Derived():Base(d_priv,d_protect)
    {
        cout<<"Default Derived Constructor"<<endl;

    }
    Derived( int a,int b ,int c)
    {
        cout<<"Parameterized Derived Constructor"<<endl;
    }
    int sum (int a,int b,int c){
        cout<<"Derived sum"<<endl;
        return Base::sum(a,b)+c;//  Derived first then Base 
        // extend the parent function, override
    }
    void displayb(Base b){
        cout<<"Display Base"<<endl;
    }

    void displayd(Derived b){
        cout<<"Derived Base"<<endl;
    } 

    ~Derived()
    {
        cout<<"Derived Destructor"<<endl;
    }

};
class SecondDerived :public Derived
{
    private:
        int sd_priv;
    protected:
        int sd_protect;
    public:
        int sd_pub;

    SecondDerived()
    {
        cout<<"Default SecondDerived Constructor"<<endl;

    }
    ~SecondDerived()
    {
        cout<<"SecondDerived Destructor"<<endl;
    }

};
 
void sum(float x);
void sum(float x,int y = 0);// error default parameter are not counted in function seg
void sum(double x,int y = 0);// always call double due to something i don't remember it's name, which always call the largest one


int main()
{
    Base b;
    Derived d,d2;
    SecondDerived sd;
    // Derived(): 
    // Calls Default constructors for Derived and Base 
    // Derived():Base(d_priv,d_protect)
    // Calls Default constructors for Derived, Parameterized Constructor for Base

    d.sum(1,2,3); // Derived sum called inside it we call Base sum

    Derived d1(1,2,3); // defaul constructor called 
    SecondDerived sd; //  base parameterized(we call it with derived default) -> derived default -> second default
    // Destructor called in reverse order 

    // No errors  
    d.displayb(b);
    d.displayb(d2);
    d.displayd(d);
    b.displayb(&d);

    //d.displayd(b); // error

    Derived c;
    Base *ptr = &c;
    ptr -> sum(1,2) ;// parent sum
    // ptr -> sum(1,2,3) ;// Error
    // ptr -> d_pub // Error
    ptr -> base_pub;


    return 0;
}