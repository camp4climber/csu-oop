#ifndef STAMPSTREAM_H
#define STAMPSTREAM_H

#include <ostream>
#include "stampbuf.h"

using namespace std;

class stampstream : public ostream 
{
  public:
    stampstream(int c, int r);
    ~stampstream();
};

class row
{
friend ostream& operator<<(ostream &os, const row& r);
public:
	row(int r);
private:
	int m_row;
};

ostream &endrow(ostream& os);

#endif