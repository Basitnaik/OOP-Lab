#include<iostream>
using namespace std;
class Distance{
    private:
    int meters;
    int cenitimers;
    public:
    Distance(int m){
        meters=m;
    }
    Distance(int m,int c):meters(m),cenitimers(c)
    {
        normlize();
    }
    void normlize(){
        if (cenitimers >= 100) { 
            meters += cenitimers / 100;
             cenitimers = cenitimers % 100; 
            }
    }
    Distance add(Distance d){
        int m= meters+d.meters;
        int c= cenitimers+d.cenitimers;
        return Distance(m,c);
    }
    void show() {
         cout << meters << " meters " 
         << cenitimers << " centimeters" << endl; 
        }


};
int main(){
    Distance d1(5);
    Distance d2(3,75);
    Distance d3=d1.add(d2);
    d3.show();
    return 0;
}