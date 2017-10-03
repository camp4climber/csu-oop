main: main.o book.o film.o periodical.o video.o media.o search_engine.o
	g++ main.o book.o film.o periodical.o video.o media.o search_engine.o -o library

main.o: main.cpp search_engine.h book.h film.h periodical.h video.h
	g++ -c main.cpp

book.o: book.h book.cpp media.h
	g++ -c book.cpp

film.o: film.h film.cpp media.h
	g++ -c film.cpp

periodical.o: periodical.h periodical.cpp media.h
	g++ -c periodical.cpp

video.o: video.h video.cpp media.h
	g++ -c video.cpp

media.o: media.h media.cpp
	g++ -c media.cpp

search_engine.o: search_engine.h search_engine.cpp media.h
	g++ -c search_engine.cpp

clean: 
	rm *.o library