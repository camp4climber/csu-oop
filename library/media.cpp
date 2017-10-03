#include "media.h"

Media::Media(string call_num, string title, string subjects) : 
	m_call_num(call_num), 
	m_title(title), 
	m_subjects(subjects)
{}

Media::~Media()
{}

bool Media::compare_call_num(const string term)
{
	if (m_call_num.find(term) != string::npos)
		return true;
	else
		return false;
}
bool Media::compare_title(const string term)
{
	if (m_title.find(term) != string::npos)
		return true;
	else
		return false;
}
bool Media::compare_subjects(const string term)
{
	if (m_subjects.find(term) != string::npos)
		return true;
	else
		return false;
}