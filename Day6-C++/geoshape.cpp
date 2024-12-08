#include <iostream>

using namespace std;


class GeoShape
{
protected:
    double x;
    double y;
public:
    GeoShape (double x,double y)
    {
        this->x=x;
        this->y=y;
    }
    void set_x(double x)
    {
        this->x=x;
    }
    void set_y(double y)
    {
        this->x=x;
    }
    double get_x()
    {
        return x;
    }
    double get_y()
    {
        return y;
    }
    virtual double calculateArea()=0;
};

class Rect: protected GeoShape
{
public:
    Rect(double x, double y):GeoShape(x, y)
    {

    }
    void set_x(double x)
    {
        GeoShape::set_x(x);
    }
    void set_y(double y)
    {
        GeoShape::set_y(y);
    }
    double get_x()
    {
        return GeoShape::get_x();;
    }
    double get_y()
    {
       GeoShape::get_x();
    }
    double calculateArea()
    {
        return x*y;
    }
};

class Circle:private GeoShape
{

public:
    Circle(double radius): GeoShape(radius,radius)
    {

    }
    void setRadius(double radius)
    {
        x=radius;
        y=radius;
    }
    double getRadius()
    {
        return x;
    }
    double calculateArea()
    {
        return 22.0/7*x*y;
    }
};



class Square: private Rect
{
public:
    Square(double x): Rect(x, x)
    { }
    void setSquareDim(double x)
    {
        this->x=x;
        this->y=x;
    }
    double getSquareDim()
    {
        return x;
    }
    double calculateArea()
    {
        return Rect::calculateArea();
    }
};


int main()
{
    Circle c(5);
    cout<<c.calculateArea()<<endl;

    Rect rect(5,8);
    cout<<rect.calculateArea()<<endl;

    Square square(5);
    cout<<square.calculateArea()<<endl;

    return 0;
}
