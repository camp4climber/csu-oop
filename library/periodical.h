#ifndef PERIODICAL_H
#define PERIODICAL_H

#include <iostream>
#include <vector>
#include "media.h"

using namespace std;

class Periodical : public Media
{
	public:
		Periodical(vector <string> data);		
		void display() const;
		bool compare_other(const string term);
	private:
		string m_call_num;
		string m_title;
		string m_subjects;
		string m_author;
		string m_description;
		string m_publisher;
		string m_publishing_history;
		string m_series;
		string m_notes;
		string m_related;
		string m_other_title;
		string m_doc_num;
};
#endif