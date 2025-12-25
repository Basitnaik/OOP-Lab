#include<iostream>
using namespace std;
class Shape{
    public:
    virtual void area()=0;

};
class circle:public Shape{
    public:
    float radius;
    circle(float r): radius(r){}
    void area(){
        cout << "Area of Circle = " << 3.14 * radius * radius << endl;
    }
};
class Rectangle:public Shape{
    public:
    float length, breadth;
    Rectangle(float l, float b):length(l),breadth(b){}
    void area(){
    cout << "Area of rectangle = " <<length * breadth << endl;
    }
};
class Squre:public Shape{
    public:
    float side;
    Squre (float s):side(s){}
    void area(){
    cout << "Area of squre = " <<side *side << endl;
    }
};
int main(){
    circle c(5);
    Rectangle r(3,4);
    Squre s1(3);
    Shape* s;
    s=&c;
    s->area();
    s=&r;
    s->area();
    s=&s1;
    s->area();
    return 0;
}