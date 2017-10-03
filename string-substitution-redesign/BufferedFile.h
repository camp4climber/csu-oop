#ifndef BUFFEREDFILE_H
#define BUFFEREDFILE_H

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <deque>

using namespace std;

class BufferedFile : public fstream
{
public:
	BufferedFile();
	~BufferedFile();
	BufferedFile& get(char &ch);
	void put(char &ch);
	void do_over(char ch);
	void trunc(string filename);
	bool eof();
private:
	string m_filename;
	streampos m_getpos;
	streampos m_putpos;
	bool m_eof;
	deque<char> m_deque;
};

#endif