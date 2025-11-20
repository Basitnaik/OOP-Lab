#include<iostream>
using namespace std;
void callbyvalue( int a=80,int b=90){
    cout<<"the values of a and b:"<<a<<b<<endl;
    int temp;
    temp=a;
    a=b;
    b=temp;
    cout<<"the values:"<<a<<b<<endl;
}
void callbyrefrance( int &a,int &b){
    
    cout<<"values of a an b"<<a<<b<<endl;
    int temp=a;
    a=b;
    b=temp;
    cout<<"the values of after swap is";

}
int main(){
    int x,y;
    //int q=30,w=40;
    cout<<"enter two numbers:";
    cin>>x>>y;
    cout<<"before swap x and y is :"<<x<<y<<endl;
    callbyvalue() ;
    cout<<"after the swap x and y is \n"<<endl;
    //callbyrefrance(q,w);
   // cout<<"the values after swap call by value:"<<q<<w<<endl;
    
    return 0;
}