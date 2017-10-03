#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <vector>
#include "media.h"

using namespace std;

class Film : public Media
{
	public:
		Film(vector <string> data);
		void display() const;
		bool compare_other(const string term);
	private:
		string m_call_num;
		string m_title;
		string m_subjects;
		string m_director;
		string m_notes;
		string m_year;
};
#endif