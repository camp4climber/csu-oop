#include "video.h"

Video::Video(vector <string> data) :
	Media(data[0], data[1], data[2]),
	m_call_num(data[0]),
	m_title(data[1]),
	m_subjects(data[2]),
	m_description(data[3]),
	m_distributor(data[4]),
	m_notes(data[5]),
	m_series(data[6]),
	m_label(data[7])
{}

bool Video::compare_other(const string term)
{
	if (m_description.find(term) != string::npos ||
		m_notes.find(term) != string::npos ||
		m_distributor.find(term) != string::npos)
		return true;
	else
		return false;
}

void Video::display() const
{
	cout << "--------------------------\n";
	cout << "Call Number: " << m_call_num << endl;
	cout << "Title: " << m_title << endl;
	cout << "Subjects: " << m_subjects << endl;
	cout << "Description: " << m_description << endl;
	cout << "Distributor: " << m_distributor << endl;
	cout << "Notes: " << m_notes << endl;
	cout << "Series: " << m_series << endl;
	cout << "Label: " << m_label << endl;
}