#include "film.h"

Film::Film(vector <string> data) :
	Media(data[0], data[1], data[2]),
	m_call_num(data[0]),
	m_title(data[1]),
	m_subjects(data[2]),
	m_director(data[3]),
	m_notes(data[4]),
	m_year(data[5])
{}

bool Film::compare_other(const string term)
{
	if (m_director.find(term) != string::npos ||
		m_notes.find(term) != string::npos ||
		m_year.find(term) != string::npos)
		return true;
	else
		return false;
}

void Film::display() const
{
	cout << "--------------------------\n";
	cout << "Call Number: " << m_call_num << endl;
	cout << "Title: " << m_title << endl;
	cout << "Subjects: " << m_subjects << endl;
	cout << "Director: " << m_director << endl;
	cout << "Notes: " << m_notes << endl;
	cout << "Year: " << m_year << endl;
}