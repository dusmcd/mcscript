flags = -Wall -std=c++17 -g
target = ../main
test_target = ../test

textparser.o: textparser.cpp textparser.h
	g++ $< $(flags) -c

console.o: console.cpp console.h
	g++ $< $(flags) -c

string.o: string.cpp string.h
	g++ $< $(flags) -c

integer.o: integer.cpp integer.h
	g++ $< $(flags) -c

function.o: function.cpp function.h
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

my_exception.o: ./errors/my_exception.cpp ./errors/my_exception.h
	g++ $< $(flags) -c

runner.o: runner.cpp runner.h
	g++ $< $(flags) -c

main.o: main.cpp textparser.h program.h
	g++ $< $(flags) -c

string_funcs.o: ./util/string_funcs.cpp ./util/string_funcs.h
	g++ $< $(flags) -c

main: main.o textparser.o console.o string.o syntax.o program.o objectcreate.o\
 u_objectcreate.o json.o integer.o string_funcs.o function.o runner.o my_exception.o
	g++ $^ $(flags) -o $(target)

test_string_funcs.o: ./util/test_string_funcs.cpp ./util/string_funcs.h
	g++ $< $(flags) -c

test: test_string_funcs.o string_funcs.o
	g++ $^ $(flags) -o $(test_target)

clean:
	rm *.o $(target) $(test_target)