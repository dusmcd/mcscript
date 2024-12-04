flags = -Wall -std=c++17
target = ../main

textparser.o: textparser.cpp textparser.h
	g++ $< $(flags) -c

console.o: console.cpp console.h
	g++ $< $(flags) -c

string.o: string.cpp string.h
	g++ $< $(flags) -c

syntax.o: syntax.cpp syntax.h
	g++ $< $(flags) -c

program.o: program.cpp program.h
	g++ $< $(flags) -c

objectcreate.o: objectcreate.cpp objectcreate.h
	g++ $< $(flags) -c

main.o: main.cpp textparser.h program.h
	g++ $< $(flags) -c

main: main.o textparser.o console.o string.o syntax.o program.o objectcreate.o
	g++ $^ $(flags) -o $(target)

clean:
	rm *.o $(target)