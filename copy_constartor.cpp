#include<iostream>
using namespace std;
class Bill{
    private:
    int units;
    public:
    Bill(int u):units(u)
    { }
    int calcluatebill(){
        return units*5;
    }
    Bill(  Bill&b){
        units=b.units;
    }
    void showbill(){
    cout<<"units are"<<units<<endl;
    cout<<"total bill is"<<calcluatebill()<<endl;
    }
};
int main(){
    Bill b1(5);
    Bill b2(b1);
    b1.showbill();
    b2.showbill();
    return 0;
}