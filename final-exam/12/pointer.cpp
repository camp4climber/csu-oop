#include<stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
  char *p1 = "Word";
  char *p2 = (char*)malloc(5);

  cout << p1 << " " << p2 << endl;
  return 0;
}
