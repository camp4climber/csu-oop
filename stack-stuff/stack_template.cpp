#include <iostream>
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
:maximum_size(s.maximum_size), base(new int[s.maximum_size])
{
  if(base==0)
    throw "No more memory!";
  if(s.current_size>-1)
  {
    for(current_size=0; current_size<=s.current_size; current_size++)
      base[current_size]=s.base[current_size];
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
  delete [] base;
  maximum_size=s.maximum_size;
  base=new int[maximum_size];
  if(base==0)
    throw "No more memory!";
  current_size=s.current_size;
  if(current_size>-1)
  {
    for(int x=0; x<=current_size; x++)
      base[x]=s.base[x];
  }
  return *this;
}

template <typename TYPE>
void Stack<TYPE>::push(TYPE element)
{
  current_size++;
  if(current_size==maximum_size-1)
  {
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
  Stack<float> s;
  s.push(3.14);

  cout << s.pop() << endl;
  return 0;
}