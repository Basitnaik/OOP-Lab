#include<iostream>
using namespace std;
class Iteam{
    private:
    int *price;
    int *quantity;
    public:
    Iteam( int p,int q):price (new int (p)),quantity(new int (q)) // give dynamic memory by usung new
    {}
    void totalcost(){
        cout<<"total cost is"<< (*price)* (*quantity)<<endl;
    }
    ~Iteam(){
        delete price;
        delete quantity;
        cout<<"memory deleted";
    }
};
int main(){
    Iteam i1(6,3);
    i1.totalcost();

}
