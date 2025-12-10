#include<iostream>
using namespace std;
class date{
    private:
    int day;
    int mounth;
    int year;
    public:
    void getdate(){
        cout<<"enter persent day date";
        cin>>day;
        cout<<"enter persent mounth";
        cin>>mounth;
        cout<<"enter year";
        cin>>year;
    }
        void showdate(){
            cout<<day<<"/"<<mounth<<"/"<<year<<endl;
        }

};
int main(){
    date date1;
    date1.getdate();
    date1.showdate();
    return 0;
}
