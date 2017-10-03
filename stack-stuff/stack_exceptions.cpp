#include <iostream>
#include "Nausea.h"
using namespace std;

template <typename TYPE>
class Stack
{
  public:
    Stack();
    Stack(const Stack<TYPE>&);
    ~Stack();
    Stack<TYPE>& operator=(const Stack<TYPE>&);
    int size();
    void push(TYPE);
    TYPE pop();
  private:
    static const int chunk_size;
    unsigned maximum_size;
    int current_size;
    TYPE* base;
};

template <typename TYPE>
const int Stack<TYPE>::chunk_size=10;

template <typename TYPE>
Stack<TYPE>::Stack()
:current_size(-1),maximum_size(chunk_size),base(new TYPE[chunk_size])
{
  if(base==0)
    throw "No more memory!";
}

template <typename TYPE>
Stack<TYPE>::Stack(const Stack<TYPE>& s)
:maximum_size(s.maximum_size), base(new TYPE[s.maximum_size])
{
  if(base==0)
    throw "No more memory!";
  if(s.current_size>-1)
  {
    try {
      for(current_size=0; current_size<=s.current_size; current_size++)
        base[current_size]=s.base[current_size];
    } catch(...) {
      delete [] base;
      throw;
    }
    current_size--;
  }
}

template <typename TYPE>
Stack<TYPE>::~Stack()
{
  delete [] base;
}

template <typename TYPE>
Stack<TYPE>& Stack<TYPE>::operator=(const Stack<TYPE>& s)
{
  try {
    TYPE* tmp_base = base;
    delete [] base;
    int tmp_max_size = maximum_size;
    maximum_size=s.maximum_size;
    base=new TYPE[maximum_size];
    if(base==0)
      throw "No more memory!";
    int tmp_cur_size = current_size;
    current_size=s.current_size;
    if(current_size>-1)
    {
      for(int x=0; x<=current_size; x++)
        base[x]=s.base[x];
    }
    return *this;
  } catch (...) {
    base = tmp_base;
    maximum_size = tmp_max_size;
    current_size = tmp_cur_size;
    throw;
  }
}

template <typename TYPE>
void Stack<TYPE>::push(TYPE element)
{
  try {
    int tmp_cur_size = current_size;
    current_size++;
    if(current_size==maximum_size-1)
    {
      int tmp_max_size = maximum_size;
      maximum_size+=chunk_size;
      TYPE* new_buffer = new TYPE[maximum_size];
      if(new_buffer==0)
        throw "No more memory!";
      for(int x=0; x<current_size; x++)
        new_buffer[x]=base[x];
      delete [] base;
      base=new_buffer;
    }
    base[current_size]=element;
  } catch (...) {
    current_size = tmp_cur_size;
    maximum_size = tmp_max_size;
    delete [] new_buffer;
    throw;
  }
}

template <typename TYPE>
TYPE Stack<TYPE>::pop()
{
  if(current_size<0)
    throw "Nothing to pop!";
  return base[current_size--];
}

template <typename TYPE>
int Stack<TYPE>::size()
{
  return current_size+1;
}

int main()
{
  Nausea n1;
  Nausea n2; 
  n2 = n1;
  Nausea n3(n1);
  Stack<Nausea> s;

  s.push(n3);
  s.push(n2);
  s.push(n1);

  s.pop();
  s.pop();
  s.pop();

  return 0;
}