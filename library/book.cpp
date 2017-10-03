#include "book.h"

Book::Book(vector <string> data) :
	Media(data[0], data[1], data[2]),
	m_call_num(data[0]),
	m_title(data[1]),
	m_subjects(data[2]),
	m_author(data[3]),
	m_description(data[4]),
	m_publisher(data[5]),
	m_city(data[6]),
	m_year(data[7]),
	m_series(data[8]),
	m_notes(data[9])
{}

bool Book::compare_other(const string term)
{
	if (m_description.find(term) != string::npos ||
		m_notes.find(term) != string::npos ||
		m_year.find(term) != string::npos)
		return true;
	else
		return false;
}

void Book::display() const
{
	cout << "--------------------------\n";
	cout << "Call Number: " << m_call_num << endl;
	cout << "Title: " << m_title << endl;
	cout << "Subjects: " << m_subjects << endl;
	cout << "Author: " << m_author << endl;
	cout << "Description: " << m_description << endl;
	cout << "Publisher: " << m_publisher << endl;
	cout << "City: " << m_city << endl;
	cout << "Year: " << m_year << endl;
	cout << "Series: " << m_series << endl;
	cout << "Notes: " << m_notes << endl;
}