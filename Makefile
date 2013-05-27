CC=g++
CXXFLAGS=-ansi -pedantic -Wall -Wextra

BINNAME=program

all: ${BINNAME}


program: main.o contactbook.o
	g++ $+ -o ${BINNAME}

main.o: main.cpp contactbook.h
	g++ -c ${CXXFLAGS} $<

contactbook.o: contactbook.cpp contactbook.h
	g++ -c ${CXXFLAGS} $<



clean:
	rm -f ${BINNAME}
	rm -f *.o

.PHONY: all clean
