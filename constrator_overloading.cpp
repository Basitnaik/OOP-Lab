#include<iostream>
using namespace std;
class Rectangle{
    private:
    int length;
    int width;
    public:
    Rectangle( int l,int  w):length(l),width(w)
    {}
    Rectangle(int l) {
        length=l;
        width=l;
    }
    int area(){
        return length*width;
    }
    int paremeter(){
        return 2*(length+width);
    }
};
int main(){
    Rectangle rect1(2,3);
    Rectangle rect2(7);
    cout<<rect1.area()<<endl;
    cout<<rect1.paremeter()<<endl;
    cout<<rect2.area()<<endl;
    cout<<rect2.paremeter()<<endl;
    return 0;
}