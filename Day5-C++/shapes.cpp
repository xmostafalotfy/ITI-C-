#include <iostream>
#include <graphics.h>
using namespace std;

class Shape
{
    private:
        int color;
    protected:
    public:
        Shape(int color)
        {
            this-> color=color;
        }
        void set_color(int color)
        {
            this-> color=color;
        }
        int get_color()
        {
            return this-> color;
        }
        ~Shape()
        {

        }
};
class Point
{
private:
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}

    int getX() { return x; }
    int getY() { return y; }
};

class Line :Shape
{
private:
    Point start;
    Point end;
public:
    Line() :Shape(0), start(), end() {}
    Line(int x1, int y1, int x2, int y2,int color = 0) :Shape(color), start(x1, y1), end(x2, y2) {}
    void draw() {
        setcolor(this->get_color());
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

class Rect :Shape
{
private:
    Point ul; 
    Point lr; 
public:
    Rect() : Shape(0),ul(), lr() {}
    Rect(int x1, int y1, int x2, int y2,int color) :Shape(color), ul(x1, y1), lr(x2, y2) {}
    void draw() {
        setcolor(this->get_color());
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};
class Circle :Shape
{
private:
    Point center;
    int radius;
public:
    Circle() :Shape(0), center(), radius(0) {}
    Circle(int m, int n, int r,int color) :Shape(color), center(m, n), radius(r) {}
    void draw() {
        setcolor(this->get_color());
        circle(center.getX(), center.getY(), radius);
    }
};

class Picture
{
private:
    int cNum, rNum, lNum;
    Circle* pCircles;
    Rect* pRects;
    Line* pLines;
public:
    Picture() : cNum(0), rNum(0), lNum(0), pCircles(nullptr), pRects(nullptr), pLines(nullptr) {}
    void setCircles(int cn, Circle* pC) {
        cNum = cn;
        pCircles = pC;
    }
    void setRects(int rn, Rect* pR) {
        rNum = rn;
        pRects = pR;
    }
    void setLines(int ln, Line* pL) {
        lNum = ln;
        pLines = pL;
    }
    void paint() {
        for (int i = 0; i < cNum; i++) {
            pCircles[i].draw();
        }
        for (int i = 0; i < rNum; i++) {
            pRects[i].draw();
        }
        for (int i = 0; i < lNum; i++)
        {
            pLines[i].draw();
        }
    }
};
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Picture myPic;
    Circle cArr[2] = { Circle(50, 50, 50,13), Circle(50, 150, 50,13)};
    Rect rArr[2] = { Rect(100, 100, 150, 150,2), Rect(180, 180, 250, 250,2) };
    Line lArr[2] = { Line(200, 200, 200, 300,3), Line(200, 210, 300, 210,3) };
    myPic.setCircles(2, cArr);
    myPic.setRects(2, rArr);
    myPic.setLines(2, lArr);
    myPic.paint();
    getch();
    return 0;
}