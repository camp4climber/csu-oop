#include<iostream>
using namespace std;

class superhero{
public:
    superhero();
    superhero(const float s, const string w);
    virtual void display() const;
protected:
    float strength;
    string weapon;
};

superhero::superhero(const float s, const string w) : strength(s), weapon(w)
{}

superhero::superhero()
{}

void superhero::display() const
{    
    cout << "This is The Super Hero Class Called" << endl;
    cout << "\t::: Super Hero :::" << endl;   
}

class Batman : superhero
{
public:
    void display() const;
    Batman();
private:
    string name;
    string supername;
};

Batman::Batman() : superhero(8,"Batterrang")
{}

void Batman::display() const
{    
    cout << "This is The Super Hero Class Called" << endl;
    cout << "\t::: Super Hero :::" << endl;
    cout << "Strength: " << strength << endl;
    cout << "Weapon: " << weapon << endl;
    cout << "The real name is Bruce Wayne." << endl;
    cout << "The super hero name is Batman " << endl;    
}

class Superman : superhero
{    
public:
    void display() const;
    Superman();
    
};

Superman::Superman() : superhero(10,"No Weapon")
{}


void Superman::display()const{
    
    cout << "This is The Super Hero Class Called" << endl;
    cout << "\t::: Super Hero :::" << endl;
    cout << "Strength: " << strength << endl;
    cout << "Weapon: " << weapon << endl;
    cout << "The real name is Clark Kent" << endl;
    cout << "The super hero name is Superman" << endl;
    
    
}

int main()
{
  
  superhero s;
  Batman b;
  Superman Super;
  cout<<"---------------------------Original Display----------------------------"<<endl;
  s.display();
  cout<<"\n-------------------------Batman calling----------------------------"<<endl;
  b.display();
  cout<<"\n-------------------------Superman calling-------------------------"<<endl;
  Super.display();

   return 0;
}