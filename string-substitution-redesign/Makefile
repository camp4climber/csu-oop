stringsub: main.o SearchReplace.o BufferedFile.o 
	g++ -o stringsub main.o SearchReplace.o BufferedFile.o
	
main.o: main.cpp
	g++ -c main.cpp

SearchReplace.o: SearchReplace.h SearchReplace.cpp
	g++ -c SearchReplace.cpp

BufferedFile.o: BufferedFile.h BufferedFile.cpp
	g++ -c BufferedFile.cpp

clean:
	rm *.o stringsub