#include <iostream>
#include <fstream>
#include "SearchReplace.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		cerr << "stringsub <old> <new> <filename>" << endl;
	}
	else
	{
		string oldstr = argv[1];
		string newstr = argv[2];
		string filename = argv[3];
		
		SearchReplace sr(oldstr, newstr, filename);
		int matches = 0;
		char ch;

		while (!sr.getchar(ch).eof())
		{
			if (ch == oldstr[matches] && !sr.currently_replacing())
			{
				matches++;
				if (matches < oldstr.length()) 
				{
					continue;
				}
			}
			
			if (matches == oldstr.length())
			{
				sr.replace();
			}
			
			else if (matches > 0)
			{
				sr.partial(matches, ch);
			}
			
			else
			{
				sr.putchar(ch);
			}

			matches = 0;
		}
	}

	return 0;
}