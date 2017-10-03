#include "stampstream.h"

stampstream::stampstream(int c, int r) : ostream(new stampbuf(c,r))
{}

stampstream::~stampstream()
{
  delete rdbuf();
}

row::row(int r) : m_row(r)
{} 

ostream& operator<<(ostream& os, const row& r)
{
  stampbuf *ptr = dynamic_cast<stampbuf*>(os.rdbuf());
  ptr->set_row(r.m_row);
  return os;
}

ostream& endrow(ostream &os)
{
  stampbuf *ptr = dynamic_cast<stampbuf*>(os.rdbuf());
  ptr->end_row();
  return os;
}