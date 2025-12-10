#include<iostream>
using namespace std;
#include<string>
class User{
    private:
    int id;
    string password;
    public:
    string username;
    User( int id ){
        this->id=id;
    }
    string getpassword(){
        return password;
    }
    void setpassword( string password){
        this-> password=password;

    }

};