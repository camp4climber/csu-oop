#include <iostream>

using namespace std;

class repeat
{
friend ostream& operator<<(ostream& os, const repeat& r);
public:
	repeat(char c, int num) : m_c(c), m_num(num) {}
private:
	char m_c;
	int m_num;
};

ostream& operator<<(ostream& os, const repeat& r)
{
	for (int i = 0; i < r.m_num; i++)
		os << r.m_c;
	return os;
}

int main()
{
	cout << repeat('*', 80) << endl;
	return 0;
}