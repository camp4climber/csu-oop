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

		bool mismatch;
		int matches = 0;
		char ch;

		while (sr.getchar(ch))
		{
			//ch matches first char of oldstr
			if (sr.match(ch, oldstr[0]))
			{
				//check to see if whole string will match
				for (int i = 1; i < oldstr.length(); i++)
				{
					sr.getchar(ch);
					if (sr.match(ch, oldstr[i]))
					{
						matches++;
					}
					else
					{
						mismatch = true;
						break;
					}
				}
				if (mismatch)
				{
					for (int i = 0; i < matches; i++)
					{
						sr.putchar(oldstr[i]);
					}
				}
				else
				{
					sr.replace();
				}
			}
			else
			{
				sr.putchar(ch);
			}
			mismatch = false;
			matches = 0;
		}

		sr.trunc();
	}

	return 0;
}