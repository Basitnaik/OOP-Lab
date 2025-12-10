#include<iostream>
using namespace std;
class employee{
    private:
    int empno;
    float empcomp;
    public:
void enterdata(){
    cout<<"enter employe id";
    cin>>empno;
    cout<<"ente compastaion in dollors";
    cin>>empcomp;
    }
void displaydata(){
    cout<<"the emplo id are"<<empno;
    cout<<"the emp compastion "<<empcomp;
}
};
int main(){
    employee E1;
    E1.enterdata();
    E1.displaydata();


}

