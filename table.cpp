#include<iostream>
#include<iomanip>  
using namespace std;

int main() {
    int n,total=200,columns=10;
    cout << "Enter the starting number: ";
    cin >> n;
    for(int i = 1; i <=total; i++) {//row
        //for(int j = n; j < ; j++) {//coli
            //int multiple = n * (j + (i-1)*10 + 1);

            cout << setw(5) << n*i;
            if (i %columns==0)
            cout<<endl;
    }
    

    return 0;
}