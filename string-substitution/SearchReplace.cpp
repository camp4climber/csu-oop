#include "SearchReplace.h"

SearchReplace::SearchReplace(string oldstr, string newstr, string filename) 
: m_oldstr(oldstr), m_newstr(newstr), 
  m_filename(filename),
  m_getpos(0), m_putpos(0)
{
	open(m_filename, std::ios::out | std::ios::in);
} 

bool SearchReplace::getchar(char &ch)
{
	if (!m_deque.empty())
	{
		ch = m_deque.front();
		m_deque.pop_front();
	}
	else
	{
		seekg(m_getpos);
		ch = get();
		m_getpos += 1;
	}
	return ch != EOF ? true : false;
}

void SearchReplace::putchar(char &ch)
{
	if (m_getpos == m_putpos)
	{
		char temp;
		seekg(m_getpos);
		temp = get();
		m_getpos += 1;
		m_deque.push_back(temp);
	}
	clear();
	seekp(m_putpos);
	put(ch);
	m_putpos += 1;
}

bool SearchReplace::match(char ch1, char ch2)
{
	return ch1 == ch2 ? true : false;
}

void SearchReplace::replace()
{
	for (int i = 0; i < m_newstr.length(); i++)
	{
		putchar(m_newstr[i]);
	}
}

void SearchReplace::trunc()
{
	truncate(m_filename.c_str(), m_putpos);
}
