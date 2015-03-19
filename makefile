OBJECTS = binsearch_main.o binsearch.o
CC      = g++
DEBUG   = -g
CFLAGS  = -Wall -c $(DEBUG)
LFLAGS  = -Wall $(DEBUG)

all: binsearch

binsearch: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o search

main.o: binsearch_main.cpp
	$(CC) $(CFLAGS) binsearch_main.cpp
	
binsearch.o: search_algorithms.h binsearch.cpp
	$(CC) $(CFLAGS) binsearch.cpp
