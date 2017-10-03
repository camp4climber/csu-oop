/*
Why would we want to use a template? It allows for better modularity of code.
This way, we can use our class with any kind of type instead of having to write
many multiple classes for different types (e.g. int_stack, float_stack, char_stack).
With a template we can write one class (stack) and instantiate any kind of type by doing
stack<int> s1; stack<float> s2; stack<char> s3;
*/

#include <iostream>
using namespace std;

template <typename TYPE>
class stack
{
    public:
            void push_back(TYPE);
            int size();
            TYPE pop_front();
    private:
            TYPE value;
}


int main()
{
	stack<float> s;
}