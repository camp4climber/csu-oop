#include "Report.h"
void func(const Report& r) //copy ctor
{
  r.display();
}


int main()
{
  // Create Report r;
  Report r;
  func(r);
}
