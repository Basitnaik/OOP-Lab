#include<iostream>
using namespace std;
#include<conio.h>
const char ESC=27;
const double Toll=0.5;
class tollBooth {
    private:
    unsigned int totalcars;
    double totalcash;
    public:
    tollBooth():totalcars(0),totalcash(0) {}
    void payingcars(){
        totalcars++;
        totalcash += Toll;
    }
    void nopaycar(){
        totalcars++;
    }
    void display() const{
        cout<< "\ncars="<<totalcars
        <<"cash"<<totalcash
        <<endl;
    }
};
int main(){
    tollBooth booth1;
    char ch;
    cout << "\nPress 0 for each non-paying car,"
        << "\n  press 1 for each paying car,"
        << "\nEsc to exit the program.\n";
        do {
        ch = getche();           
    if( ch == '0' )      
        booth1.nopaycar();
            if( ch == '1' ) 
            booth1.payingcars();         
        }
        while( ch != ESC );    
          booth1.display();        

    return 0;
}