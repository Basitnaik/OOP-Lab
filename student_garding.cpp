#include<iostream>
using namespace std;
void entermarks(int marks[],int n){
    for(int i=0;i<n;i++){
        cout<<"enter the marks of subject"<<i+1<<": ";
        cin >>marks[i];
    }

}







int main(){
    int marks[5];
    entermarks(marks,5);
    cout<<"the marks of students are: ";
    for(int i=0;i<5;i++){
        cout<<marks[i]<<" ";
    }
    if(subject1 >=40)
return 0;
}