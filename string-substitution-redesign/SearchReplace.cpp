#include "SearchReplace.h"

SearchReplace::SearchReplace(string oldstr, string newstr, string filename)
: m_oldstr(oldstr), m_newstr(newstr),
  m_old_count(0), m_new_count(0), m_oldstr_length(0),
  m_old_get(false), m_new_get(true),
  m_filename(filename)
{
	m_bf.open(m_filename.c_str(), ios::out | ios::in);
} 

SearchReplace::~SearchReplace()
{
	m_bf.trunc(m_filename);
	m_bf.close();
}

SearchReplace& SearchReplace::getchar(char &ch)
{
	if (m_old_count > 0)
	{
		ch = m_oldstr[m_oldstr_length - m_old_count];
		m_old_count--;
		m_old_get = true;
	}
	else if (m_new_count > 0)
	{
		ch = m_newstr[m_newstr.length() - m_new_count];
		m_new_count--;
		m_new_get = true;
	}
	else
	{
		m_bf.get(ch);
		m_new_get = m_old_get = false;
	}
	return *this;
}

void SearchReplace::putchar(char &ch)
{
	m_bf.put(ch);
}

void SearchReplace::replace()
{
	m_new_count = m_newstr.length();
}

void SearchReplace::partial(int matches, char ch)
{
	m_old_count = matches-1;
	m_oldstr_length = matches;
	m_bf.do_over(ch);
	m_bf.put(m_oldstr[0]);
}

bool SearchReplace::currently_replacing()
{
	return m_new_count > 0;
}

bool SearchReplace::eof()
{
	return (m_new_get || m_old_get) ? false : m_bf.eof();
}