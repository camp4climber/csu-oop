#include <iostream>
using namespace std;

class obj
{
public:
	obj& initiate();
	obj& show();
	obj& all();
private:
};

obj& obj::initiate()
{
	return *this;
}

obj& obj::show()
{
	return *this;
}

obj& obj::all()
{
	return *this;
}

int main()
{
	obj obj1;

	obj1
	 .initiate()
	 .show()
	 .all();

	obj1
	 .initiate()
	 .all()
	 .show();

}