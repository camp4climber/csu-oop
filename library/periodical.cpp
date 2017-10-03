#include "periodical.h"

Periodical::Periodical(vector <string> data) :
	Media(data[0], data[1], data[2]),
	m_call_num(data[0]),
	m_title(data[1]),
	m_subjects(data[2]),
	m_author(data[3]),
	m_description(data[4]),
	m_publisher(data[5]),
	m_publishing_history(data[6]),
	m_series(data[7]),
	m_notes(data[8]),
	m_related(data[9]),
	m_other_title(data[10]),
	m_doc_num(data[11])
{}

bool Periodical::compare_other(const string term)
{
	if (m_description.find(term) != string::npos ||
		m_notes.find(term) != string::npos ||
		m_series.find(term) != string::npos ||
		m_other_title.find(term) != string::npos)
		return true;
	else
		return false;
}

void Periodical::display() const
{
	cout << "--------------------------\n";
	cout << "Call Number: " << m_call_num << endl;
	cout << "Title: " << m_title << endl;
	cout << "Subjects: " << m_subjects << endl;
	cout << "Author: " << m_author << endl;
	cout << "Description: " << m_description << endl;
	cout << "Publisher: " << m_publisher << endl;
	cout << "Publishing History: " << m_publishing_history << endl;
	cout << "Series: " << m_series << endl;
	cout << "Notes: " << m_notes << endl;
	cout << "Related: " << m_related << endl;
	cout << "Other Titles: " << m_other_title << endl;
	cout << "Document Number: " << m_doc_num << endl;
}