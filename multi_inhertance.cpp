#include<iostream>
using namespace std;
#include<string>
class Person{
public:
string name;
void getname(){
    cout<<"enter your name"<<endl;
    cin>>name;
}
};
class student:public Person{
    public:
    int rollno;
    int sub1,sub2,sub3;
    int total;
    float percentage;
    void getmarks(){
        cout<<"enter marks of sub1"<<endl;
        cin>>sub1;
        cout<<"enter marks of sub2"<<endl;
        cin>>sub2;
        cout<<"enter marks of sub3"<<endl;
        cin>>sub3;
       
    }
  
    };
class report: public student{
    public:
    void calculate(){
        total=sub1+sub2+sub3;
        percentage= total/3.0;
    }
    void summary(){
    
        cout<<total<<"marks"<<endl;
        cout<<percentage<<"%"<<endl;
        
    }

};
int main(){
    report student1;
    student1.getname();
    student1.getmarks();
    student1.calculate();
    student1.summary();
    return 0;
}

