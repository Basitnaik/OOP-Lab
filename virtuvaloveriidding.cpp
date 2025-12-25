#include<iostream>
using namespace std;
class Employee{
    protected:
    string name;
    public:
    Employee(string n):name(n){}
     virtual void calculateSalary(){
        cout<<"slalry is not define"<<endl;

    }
};
class Fulltimeemployee:public Employee{
    float basic, hra, da;
    public:
    Fulltimeemployee( string n,float b,float h,float d):Employee(n) {
        basic=b;
        hra=h;
        da=d;
    }
    void calculateSalary()  {
        float salary = basic + hra + da;
        cout << "Full-Time Employee: " << name << endl;
        cout << "Salary = " << salary << endl << endl;

    }

};
int main(){
    Fulltimeemployee empy("baist",4567,976,34);
    Employee* e;
    e=&empy;
    e->calculateSalary();
    return 0 ;
}