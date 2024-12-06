#include <iostream>  
#include <graphics.h>

using namespace std;  

class Point {  
private:  
    int x, y;  
public:  
    Point() : x(0), y(0) {}  
    Point(int x1, int y1) : x(x1), y(y1) {}  
    
    int getX() { return x; }  
    int getY() { return y; }  
};  

class Line {  
private:  
    Point start;  
    Point end;  
public:  
    Line() : start(), end() {}  
    Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2) {}  

    void draw() {  
        // Placeholder for drawing a line  
        line(start.getX(), start.getY(), end.getX(), end.getY());  
    }  
};  

class Rect {  
private:  
    Point ul; // Upper-left point  
    Point lr; // Lower-right point  
public:  
    Rect() : ul(), lr() {}  
    Rect(int x1, int y1, int x2, int y2) : ul(x1, y1), lr(x2, y2) {}  

    void draw() {  
        // Placeholder for drawing a rectangle  
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());  
    }  
};  

class Circle {  
private:  
    Point center;  
    int radius;  
public:  
    Circle() : center(), radius(0) {}  
    Circle(int m, int n, int r) : center(m, n), radius(r) {}  

    void draw() {  
        // Placeholder for drawing a circle  
        circle(center.getX(), center.getY(), radius);  
    }  
};  

class Picture {  
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
        for (int i = 0; i < lNum; i++) {  
            pLines[i].draw();  
        }  
    }  
};  


int main() {  
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, "");
    // Graphic Mode  
    Picture myPic;  

    Circle cArr[3] = { Circle(50, 50, 50), Circle(200, 100, 100), Circle(420, 50, 30) };  
    Rect rArr[2] = { Rect(30, 40, 170, 100), Rect(420, 50, 500, 300) };  
    Line lArr[2] = { Line(420, 50, 300, 300), Line(40, 500, 500, 400) };  

    myPic.setCircles(3, cArr);  
    myPic.setRects(2, rArr);  
    myPic.setLines(2, lArr);  

    myPic.paint();  
    getch();
    return 0;  
}