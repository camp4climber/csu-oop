#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include <vector>
#include "media.h"

using namespace std;

class Search_Engine
{
public:
	Search_Engine();
	void add_to_catalog(Media *item);
	vector <Media *> search(string type, string term) const;
	void display() const;
	const void free_catalog();
private:
	vector <Media *> m_catalog;
};
#endif