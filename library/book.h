#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>
#include "media.h"

using namespace std;

class Book : public Media
{
	public:
		Book(vector <string> data);
		void display() const;
		bool compare_other(const string term);
	private:
		string m_call_num;
		string m_title;
		string m_subjects;
		string m_author;
		string m_description;
		string m_publisher;
		string m_city;
		string m_year;
		string m_series;
		string m_notes;
};
#endif