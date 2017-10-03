#include "stampbuf.h"
#include <iostream>

stampbuf::stampbuf(int c, int r) : 
m_max_row(r), m_max_col(c), 
m_cur_row(0), m_cur_col(0), 
m_buffer(new char[c])
{
  try
  {
    stamping_press::insert_plate(c, r);
    setp(m_buffer, m_buffer+(m_max_col/2));
  }
  catch (...) {}
}

stampbuf::~stampbuf()
{
  sync();
  try
  {
  	stamping_press::eject_plate();
  }
  catch (...) {}
  delete [] m_buffer;
}

int stampbuf::sync() 
{
  int size = pptr() - pbase();
  for (int i = 0; i < size; i++)
  {
  	if (m_buffer[i] != stamping_press::get_die())
  	{
  		try
  		{
			stamping_press::set_die(m_buffer[i]);
  		}
  		catch (...)
  		{
  			m_cur_col++;
  			continue;
  		}
  	}
  	try
  	{
  		stamping_press::stamp(m_cur_col, m_cur_row);
  		m_cur_col++;
  	}
  	catch (...) {}
  }

  return 0;
}

void stampbuf::end_row()
{
	sync();
	setp(m_buffer, m_buffer+(m_max_col/2));
	m_cur_row++;
	m_cur_col = 0;
}

void stampbuf::set_row(int r)
{
	sync();
	setp(m_buffer, m_buffer+(m_max_col/2));
	m_cur_row = r;
	m_cur_col = 0;
}

int stampbuf::overflow(int c)
{
	sync();
	try
	{
		stamping_press::set_die(c);
		stamping_press::stamp(m_cur_col, m_cur_row);
		m_cur_col++;
	}
	catch (...) {m_cur_col++;}
	setp(m_buffer, m_buffer+(m_max_col/2));
	return c;
}