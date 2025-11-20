#include<iostream>
using namespace std;
int main(){
    int num;
    double smallest, largest, average, sum=0;
    cout<<"Enter the number of elements: ";
    cin>>num;
    if(num<=0){
        cout<<"enter postive valus";
        return 0;
    }
    cout<<"enter the number1: ";
    cin>>num;
    smallest=largest=num;
    sum=num;
    for(int i=2;i<=num;i++){
        cout<<"enter the number"<<i<<": ";
        cin>>num;
        sum+=num;
        if(num<smallest){
            smallest=num;
        }
        if(num>largest){
            largest=num;
        }
        sum+=num;
    }
    average=sum/num;
    cout<<"smallest: "<<smallest<<endl;
    cout<<"largest: "<<largest<<endl;
    cout<<"average: "<<average<<endl;
    return 0;

}