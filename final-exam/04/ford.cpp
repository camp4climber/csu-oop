#include<iostream>
#include<string>

using namespace std;

class Ford{
private:
    int revenue;
    
public:
    Ford(int r):revenue(r){}
    int getRevenue(){return revenue;}

    Ford& operator++(){
    	this->revenue = this->getRevenue() + 100;
    	return *this;
    }
};


int main()
{
    Ford f(2300);
    ++f;
    cout<<"Revenue of the company incremented by 100 million is "<<f.getRevenue()<<endl; //This should print 2400
}
