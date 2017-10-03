#include "BufferedFile.h"

BufferedFile::BufferedFile()
: m_getpos(0), m_putpos(0), m_eof(false)
{

}
BufferedFile::~BufferedFile()
{
}

BufferedFile& BufferedFile::get(char &ch)
{
	if (!m_deque.empty())
	{
		ch = m_deque.front();
		m_deque.pop_front();
	}
	else
	{
		seekg(m_getpos);
		fstream::get(ch);
		m_getpos += 1;
	}
	if (fstream::eof())
	{
		fstream::clear();
		m_eof = true;
	}
	return *this;
}
void BufferedFile::put(char &ch)
{
	if (m_getpos == m_putpos && !m_eof)
	{
		char temp;
		seekg(m_getpos);
		fstream::get(temp);
		m_getpos += 1;
		m_deque.push_back(temp);
	}

	seekp(m_putpos);
	if (fstream::eof())
	{
		fstream::clear();
		m_eof = true;
	}

	fstream::put(ch);
	m_putpos += 1;	
}

void BufferedFile::do_over(char ch)
{
	m_deque.push_front(ch);
}

void BufferedFile::trunc(string filename)
{
	truncate(filename.c_str(), m_putpos);
}

bool BufferedFile::eof()
{
	return (!m_deque.empty()) ? false : m_eof;
}