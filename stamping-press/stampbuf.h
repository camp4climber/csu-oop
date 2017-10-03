#ifndef STAMPBUF_H
#define STAMPBUF_H

#include <streambuf>
#include "stamp.h"

using namespace std;

class stampbuf : public streambuf {
  public:
    stampbuf(int c, int r);
    ~stampbuf();
    int sync();
    void end_row();
    void set_row(int r);

  protected:
  	virtual int overflow(int c);

  private:
    int m_max_row;
    int m_max_col;
    int m_cur_row;
    int m_cur_col;
    char* m_buffer;
};

#endif