#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>

using namespace std;
class Media
{
public:
	Media(string call_num, string title, string subjects);
	virtual ~Media();
	virtual void display() const = 0;
	bool compare_call_num(const string term);
	bool compare_title(const string term);
	bool compare_subjects(const string term);
	virtual bool compare_other(const string term) = 0;
private:
	string m_call_num;
	string m_title;
	string m_subjects;
};
#endif