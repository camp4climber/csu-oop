#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "search_engine.h"
#include "media.h"
#include "book.h"
#include "film.h"
#include "periodical.h"
#include "video.h"

void read_data_from_file(string filename, string type, Search_Engine *engine);

using namespace std;

int main()
{
	char option;
	string term;
	vector <Media *> results;
	Search_Engine *engine = new Search_Engine();

/********************************************************
Initializing the search engine's catalog from input files.
Type parameter can be book, film, video, or periodical.
*********************************************************/

	read_data_from_file("book.txt", "book", engine);
	read_data_from_file("film.txt", "film", engine);
	read_data_from_file("periodic.txt", "periodical", engine);
	read_data_from_file("video.txt", "video", engine);

/********************************************************
Main Search Menu
*********************************************************/
	
	cout << "1) Search by call number." << endl;
	cout << "2) Search by title." << endl;
	cout << "3) Search by subject." << endl;
	cout << "4) Search other." << endl;
	cout << "Enter an option: ";
	cin >> option;
	cout << "Enter Search Term: ";
	cin >> term;

	if (option == '1')
		results = engine->search("call_number", term);
	else if (option == '2')
		results = engine->search("title", term);
	else if (option == '3')
		results = engine->search("subject", term);
	else if (option == '4')
		results = engine->search("other", term);
	else
		cerr << "Invalid Option: " << option << endl;

	for (int i = 0; i < results.size(); i++)
	{
		results[i]->display();
	}

	engine->free_catalog();
	delete engine;
	return 0;
}

void read_data_from_file(string filename, string type, Search_Engine *engine)
{
	vector <string> data;
	string line, field;
	ifstream in;
	in.open(filename);

	if (in.is_open())
	{
		while (getline(in, line))
		{
			//Kind of a funny solution to solve || at the end of a line.
			//Append a pipe character to each line to ensure the correct number of fields are present.
			//The while loop will not execute on the last pipe as it sees only the \n char.
			//This leaves lines ending with || => ||| giving us 2 blank fields which is intended.
			//fields with data at the end of the line are not affected. 
			stringstream ss(line += '|');
			
			while (getline(ss, field, '|'))
			{
				data.push_back(field);
			}

			if (type == "book" && data.size() == 10)
			{
				Book *book = new Book(data);
				engine->add_to_catalog(book);
			}
			else if (type == "film" && data.size() == 6)
			{
				Film *film = new Film(data);
				engine->add_to_catalog(film);
			}
			else if (type == "periodical" && data.size() == 12)
			{
				Periodical *periodical = new Periodical(data);
				engine->add_to_catalog(periodical);
			}
			else if (type == "video" && data.size() == 8)
			{
				Video *video = new Video(data);
				engine->add_to_catalog(video);
			}

			data.clear();
		}
		in.close();
	}
	else
	{
		cerr << "Couldn't open file: " << filename << endl;
		exit(1);
	}
}