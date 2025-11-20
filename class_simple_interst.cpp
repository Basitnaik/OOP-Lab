#include<iostream>
using namespace std;
class interest{
    private:
    double principal;
    double rate;
    int  time;
    public:
     interest(double p,double r,int t) : principal(p), rate(r), time(t) {}
    double calculatesimpleinterest() const {
        return (principal*rate*time) / 100.0 ;
    }
    void displayDetails() {
         cout << "Principal Amount: " << principal <<endl;
          cout << "Annual Interest Rate: " << rate << "%" <<endl;
          cout << "Time Period: " << time << " years" << endl;
          cout << "Simple Interest:" << calculatesimpleinterest()<<endl;
    }

};
int main(){
    interest myinterst(1000.0,5.0,3);
    myinterst.displayDetails();
    return 0;
}
