#include<iostream>
using namespace std;
int stringlength(char string[]){
    int length =0;
    while(string[length] != 0){
        length++;
    }
    return length;
}
void reversestring(char string[]){
    int length=stringlength(string);
    for(int i=0;i<length/2;i++){
        char temp = string[i];
        string[i] = string[length-1-i];
        string[length-1-i] = temp;
    }
}
void  substring(char string[],char sub[],int start,int length ){
    int j=0;
    for(int i=start;i<start+length && string[i]!=0;i++){
        sub[j]=string[i];
        j++;
    }
    sub[j]='\0';
}











int main(){
    char string1[20],string2[30],string3[40];
    char ch;
    cout <<"enter the string:";
    cin>>string1;
    //length

    cout<<"length "<<stringlength(string1)<<endl;
    //reverse string

    cout<<"orrginal string"<<string1<<endl;
    reversestring(string1);
    cout<<"reverse string is::"<<string1<<endl;
    reversestring(string1);
    //substring
    cout << "Enter start position and length for substring: ";
    int start, len;
    cin >> start >> len;
    substring(string1, sub, start, len);
    cout << "Substring: " << sub << endl;

    return 0;
}