flags = -Wall -std=c++17 -g
target = ../main

textparser.o: textparser.cpp textparser.h
	g++ $< $(flags) -c

console.o: console.cpp console.h
	g++ $< $(flags) -c

string.o: string.cpp string.h
	g++ $< $(flags) -c

integer.o: integer.cpp integer.h
	g++ $< $(flags) -c

syntax.o: syntax.cpp syntax.h 
	g++ $< $(flags) -c

program.o: program.cpp program.h
	g++ $< $(flags) -c

objectcreate.o: objectcreate.cpp objectcreate.h
	g++ $< $(flags) -c

u_objectcreate.o: u_objectcreate.cpp u_objectcreate.h
	g++ $< $(flags) -c

json.o: ./json_parse/json.cpp ./json_parse/json.h 
	g++ $< $(flags) -c

main.o: main.cpp textparser.h program.h
	g++ $< $(flags) -c

main: main.o textparser.o console.o string.o syntax.o program.o objectcreate.o u_objectcreate.o json.o integer.o
	g++ $^ $(flags) -o $(target)

clean:
	rm *.o $(target)