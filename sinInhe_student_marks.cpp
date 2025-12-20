#include<iostream>
#include<string>
using namespace std;
class Student{
public:
string name;
int rollno;
void inputofstudent(){
cout<<"enter name of student"<<endl;
cin>>name;
cout<<"name of student is"<<name<<endl;
cout<<"enter roll no of student"<<endl;
cin>>rollno;
cout<<"roll of student is"<<rollno<<endl;
}
};
class marks:public Student{
    private: 
    int sub1, sub2, sub3;
     int total;
      float percentage; 
      public: 
      void inputMarks() {
         cout << "Enter marks for 3 subjects: "; 
         cin >> sub1 >> sub2 >> sub3; 
        } 
        void calculate() { 
             total = sub1 + sub2 + sub3; 
               percentage = (total /3.0f) ;
        }
        void display(){
            cout<<total<<"taotal marsk"<<endl;
            cout<<percentage<<"%";
        }

};
int main(){
    marks obj1;
    obj1.inputofstudent();
    obj1.inputMarks();
    obj1.calculate();
    obj1.display();
    return 0;
}