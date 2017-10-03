#include <iostream>
#include <deque>
using namespace std;

template <typename TYPE>
class TrackingDeque: public deque<TYPE>
{
public:
	TrackingDeque();
	~TrackingDeque();
	void push_back(const TYPE& val);
	void push_front(const TYPE& val);
private:
	int m_max_size;
};
template <typename TYPE>
TrackingDeque<TYPE>::TrackingDeque() : m_max_size(0)
{}

template <typename TYPE>
TrackingDeque<TYPE>::~TrackingDeque()
{
	cout << m_max_size << endl;
}

template <typename TYPE>
void TrackingDeque<TYPE>::push_back(const TYPE& val)
{
	deque<TYPE>::push_back(val);
	
	if (deque<TYPE>::size() > m_max_size)
		m_max_size = deque<TYPE>::size();
}

template <typename TYPE>
void TrackingDeque<TYPE>::push_front(const TYPE& val)
{
	deque<TYPE>::push_front(val);

	if (deque<TYPE>::size() > m_max_size)
		m_max_size = deque<TYPE>::size();
}

int main()
{
	TrackingDeque<char> mybuffer;

	mybuffer.push_front('A');
	mybuffer.push_back('B');
	
	cout << "Front of deque is: " << mybuffer.front() << endl;
	mybuffer.pop_front();
	
	cout << "Front of deque is: " << mybuffer.front() << endl;
	mybuffer.pop_front();
	
	return 0;
}