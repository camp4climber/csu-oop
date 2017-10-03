#include "Report.h"

// constructor to create a report
Report::Report() : rep_date(9,10,2015), rep_time(2,30)
{
}

// write a display function
void Report::display() const
{
	rep_date.display();
	rep_time.display();
}