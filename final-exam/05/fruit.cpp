#include<iostream>

using namespace std;

class Fruit
{
  public:
    char mColor;
    void setColor(char c){
      mColor = c;
    }

};

class Banana: public Fruit
{
  public:
    bool isRipe(){
      if (mColor == 'y'){
        return true;
      }
      else{
        return false;
      }
    }
};

main(){
  Banana banana;
  banana.setColor('y');
  if(banana.isRipe()){
    cout << "banana is ready to eat" << endl;
  }
  else{
    cout << "banana is not ready to eat" << endl;
  }
}
