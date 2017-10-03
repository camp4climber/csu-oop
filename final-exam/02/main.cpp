#include<iostream>

using namespace std;

class printClass
{
public:
   class fun
   {
      public:
      int fun1;
      int fun2;
   };
   void print();
   fun send_fun();

private:
   string msg;
};

void print()
{
   cout << "HELLO PROFESSOR" << endl;
}

void printClass :: print()
{
   :: print();
   cout << "HELLO STUDENTS" << endl;
}

printClass::fun printClass::send_fun()
{
   return printClass::fun{1, 2};
   //This definition should only have a return statement. The return
   //statement should assign 1 and 2 to fun1 and fun2, respectively.
}

int main()
{
   printClass::fun funObject;
   printClass p;
   funObject = p.send_fun();
   p.print();
   cout << funObject.fun1 << endl << funObject.fun2 << endl;
   return 0;
}
