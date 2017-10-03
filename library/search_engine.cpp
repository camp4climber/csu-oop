#include "search_engine.h"

Search_Engine::Search_Engine()
{}

void Search_Engine::add_to_catalog(Media *item)
{
	m_catalog.push_back(item);
}

vector <Media *> Search_Engine::search(string type, string term) const
{
	vector <Media *> results;

	for (int i = 0; i < m_catalog.size(); i++)
	{
		if (type == "call_number")
		{
			if(m_catalog[i]->compare_call_num(term))
			{
				results.push_back(m_catalog[i]);
			}
		}
		else if (type == "title")
		{
			if (m_catalog[i]->compare_title(term))
			{
				results.push_back(m_catalog[i]);
			}
		}
		else if (type == "subject")
		{
			if (m_catalog[i]->compare_subjects(term))
			{
				results.push_back(m_catalog[i]);
			}
		}
		else if (type == "other")
		{
			if (m_catalog[i]->compare_other(term))
			{
				results.push_back(m_catalog[i]);
			}
		}
	}
	return results;
}

const void Search_Engine::free_catalog()
{
	for (int i = 0; i < m_catalog.size(); i++)
	{
		delete m_catalog[i];
	}
}

void Search_Engine::display() const
{
	for  (int i = 0; i < m_catalog.size(); i++)
	{
		m_catalog[i]->display();
	}
}