#include<complex>
#include<iostream>
using namespace std;
int main(){
    cout<<"enter the real and imaginary patr of fisrt complex number:: ";
    double real1, imag1;
    cin>>real1>>imag1;
    complex<double> num1(real1, imag1);
    cout<<"enter the rael and iamg of numer2:";
    double real2,image2;
    cin>>real2>>image2;
    complex<double> num2(real2, image2);
    if (abs(num1)>abs(num2)){
        cout<<num1<<"is graeter then"<<num2<<endl;
    }
    else if(abs(num1)<abs(num2)){
        cout<<num2<<"is greater then"<<num1<<endl;
    }
else {
     cout<<num1<<"Equal "<<num2<<endl;
}
    return 0;

}