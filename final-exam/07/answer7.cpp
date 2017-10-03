/*
Answer is C, E and F.

Size of pointers to structs are all the same because the size of memory addresses don't vary.
*/

#include <iostream>
using namespace std;

struct A 
{
	char c;
	int i;
	double d;
};

struct B
{
	int i;
	char c;
};

struct C 
{
	int i;
	char c;
};

int main()
{
	A a;
	B b;
	C c;


	cout << sizeof(a&) << ", " << sizeof(&b) << ", " << sizeof(&c) << endl;

	return 0;
}