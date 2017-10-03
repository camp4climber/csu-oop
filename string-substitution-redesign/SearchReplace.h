#ifndef SEARCHREPLACE_H
#define SEARCHREPLACE_H

#include <iostream>
#include <fstream>
#include <unistd.h>
#include "BufferedFile.h"

using namespace std;

class SearchReplace
{
public:
	SearchReplace(string oldstr, string newstr, string filename);
	~SearchReplace();
	SearchReplace& getchar(char &ch);
	void putchar(char &ch);
	void replace();
	void partial(int matches, char ch);
	bool currently_replacing();
	bool eof();
private:
	string m_oldstr;
	string m_newstr;
	string m_filename;
	int m_oldstr_length;
	int m_new_count;
	int m_old_count;
	bool m_old_get;
	bool m_new_get;
	BufferedFile m_bf;
};

#endif