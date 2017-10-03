#include <iostream>
#include <deque>
using namespace std;

class FinalClass
{
    friend ostream& operator<<(ostream &os, FinalClass& c);
    friend FinalClass operator+(FinalClass& c1, FinalClass& c2);
public:
    FinalClass();
    void push(int num);
    void pop();
    int value_at_index(int i);
    int get_deque_size();
    int front();
private:
    deque<int> m_deque;
};

FinalClass::FinalClass()
{}

void FinalClass::push(int num)
{
    m_deque.push_back(num);
}

void FinalClass::pop()
{
    m_deque.pop_front();
}

int FinalClass::value_at_index(int i)
{
    return m_deque[i];
}

int FinalClass::get_deque_size()
{
    return m_deque.size();
}

int FinalClass::front()
{
  return m_deque.front();
}

ostream& operator<<(ostream &os, FinalClass& c)
{
    for (int i = 0; i < c.get_deque_size(); i++)
    {
     os << c.value_at_index(i);
    }
    for (int i = 0; i < c.get_deque_size(); i++)
    {
      c.pop();
    }
    return os;
}

FinalClass operator+(FinalClass& c1, FinalClass& c2)
{
    FinalClass result;

    for (int i = 0; i < c1.get_deque_size(); i++)
    {
     result.push(c1.value_at_index(i));
    }

    for (int i = 0; i < c2.get_deque_size(); i++)
    {
     result.push(c2.value_at_index(i));
    }

    return result;
}


int main()
{
  FinalClass a;
  FinalClass b;
  FinalClass c;

  a.push(1);
  a.push(2);
  a.push(3);
  b.push(4);
  b.push(5);
  b.push(6);

  //order matters. a+b should not return the same thing as b+a.
  c = a+b;

  //output should be 123456
  cout << c;

  return 0;
}
