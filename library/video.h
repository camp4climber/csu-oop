#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <vector>
#include "media.h"

using namespace std;

class Video : public Media
{
	public:
		Video(vector <string> data);
		void display() const;
		bool compare_other(const string term);
	private:
		string m_call_num;
		string m_title;
		string m_subjects;
		string m_description;
		string m_distributor;
		string m_notes;
		string m_series;
		string m_label;
};
#endif