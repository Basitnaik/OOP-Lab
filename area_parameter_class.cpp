#include<iostream>
using namespace std;
class Rectangle {
    private:
    double length;
    double width;
    public:
    Rectangle(double len,double wid): length(len),width(wid){
        cout<<"genral reactangel"<<length<<"width "<<width<<endl;
    }
    Rectangle(double len): Rectangle(len, len){
        cout <<"square with side len"<<len<<endl;
    }
    double calculateArea(){
        return length *width;
    }
    double calculateparimater(){
        return 2*(length+width);
    }
};
int main() {
    // Create an object using the first constructor (rectangle)
    Rectangle rect(5.0, 3.0);

    // Create an object using the second constructor (square)
    Rectangle square(4.0);

    cout << " Rectangle Details" << std::endl;
    cout << "Area: " << rect.calculateArea() << std::endl;
    cout << "Perimeter: " << rect.calculateparimater() << std::endl;
    std::cout << "Area: " << square.calculateArea() << std::endl;
    cout << "Perimeter: " << square.calculateparimater() << std::endl;
return 0;
}
