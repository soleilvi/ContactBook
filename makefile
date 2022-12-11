hw8: main.o
	g++ -o hw8 main.o

main.o: main.cpp TreeDictionary.h
	g++ -std=c++17 -c main.cpp
	
clean:
	rm -f hw8 *.o