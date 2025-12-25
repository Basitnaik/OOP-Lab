#include<iostream>
using namespace std;
 enum etype{ sectrate,manager,account,clerk};
class date{
    private:
    int day;
    int mounth;
    int year;
    public:
    date():day{0},mounth{0},year{0} {}
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
class employee{
    private:
    int id;
    float compsotion;
    date hiredate;
    etype work;
    public: 
    void getemploy() { 
        cout << "Enter employee number: "; 
        cin >> id; 
        cout << "Enter employee salary: "; 
        cin >> compsotion; 
        // Get date of employment 
        hiredate.getdate();
         // Get employee type
          char ch; 
          cout << "Enter employee type (, s=Secretary, m=Manager,a=accaount,c=clerk, ): "; 
          cin >> ch; 
          switch(ch) { 
            case 's': work = sectrate; break; 
            case 'm': work = manager; break; 
            case 'a': work = account; break;
            case 'c': work = clerk; break;
            default: cout << "Invalid type, set to clerk.\n"; work = clerk;
         } 
        }
          void putemploy() const 
          { cout << "\nEmployee Number: " << id; cout << "\nSalary: " << compsotion ;
             cout << "\nHire Date: ";
             hiredate.showdate();
              cout << "\nEmployee Type: "; 
              switch(employ_type) { 
                case laborer: cout << "Laborer"; break;
                 case secretary: cout << "Secretary"; break; 
                 case manager: 
                 cout << "Manager"; break;
                  case accountant:cout << "Accountant"; break;
                   case executive: cout << "Executive"; break; 
                   case researcher:cout << "Researcher"; break; 
                } 
                cout << endl; } };

};