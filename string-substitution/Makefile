stringsub: main.o SearchReplace.o 
	g++ -o stringsub main.o SearchReplace.o
	
main.o: main.cpp
	g++ -c main.cpp

SearchReplace.o: SearchReplace.h SearchReplace.cpp
	g++ -c SearchReplace.cpp

clean:
	rm *.o stringsub