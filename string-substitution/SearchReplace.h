#ifndef SEARCHREPLACE_H
#define SEARCHREPLACE_H

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <deque>

using namespace std;

class SearchReplace : public fstream
{
public:
	SearchReplace(string oldstr, string newstr, string filename);
	bool getchar(char &ch);
	void putchar(char &ch);
	bool match(char ch1, char ch2);
	void replace();
	void trunc();
private:
	string m_oldstr;
	string m_newstr;
	string m_filename;
	streampos m_getpos;
	streampos m_putpos;
	deque<char> m_deque;
};

#endif