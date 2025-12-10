#include<iostream>
using namespace std;
class tempature{
    private:
    int celsius;
    public:
    tempature(int c):celsius(c){}
    float celsiustofar(){
        return (celsius*9/5)+32 ;
    }
    void getout(){
        cout<<"tempature value in celsius and the faranite:"<<celsius<<endl<<celsiustofar()<<endl;

    }
};
int main(){
    tempature t1(23);
    t1.getout();
    return 0;

}