stamp: stamp.o stampstream.o stampbuf.o test.o
	g++ -o stamp stamp.o stampstream.o stampbuf.o test.o

stamp.o: stamp.h stamp.cpp
	g++ -c stamp.cpp

stampstream.o: stampstream.h stampstream.cpp
	g++ -c stampstream.cpp

stampbuf.o: stampbuf.h stampbuf.cpp
	g++ -c stampbuf.cpp

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm stamp *.o