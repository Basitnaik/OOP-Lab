#include<iostream>
using namespace std;
int main(){
double percentage ,phy,chem, math,IT;
cout <<"enter the marks of math"<<endl;
cin >> math;
cout <<"enter the marks of phy"<<endl;
cin >> phy;
cout <<"enter the marks of chem"<<endl;
cin >> chem;
cout <<"enter the marks of It "<<endl;
cin >> IT;
double total_marks= math + chem + IT + phy;
cout<<"total marks="<<total_marks<<endl;
percentage=(total_marks/400) *100;
cout<<"pecentage:"<<percentage<<"%"<<endl;
if (percentage>=90){
    cout<<"your garde is A"<<endl;
}
else if (percentage>=80){
    cout<<"your garde is B"<<endl;
}
else if (percentage>=70){
    cout<<"your garde is C"<<endl;
}
else if (percentage>=60){
    cout<<"your garde is D"<<endl;
}
else if (percentage>=50){
    cout<<"your garde is E "<<endl;
}
else if (percentage>=40){
    cout<<"your garde is F"<<endl;
}
else  
cout <<"Repeat year"<<endl;


return 0;
}
