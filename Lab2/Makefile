CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=inc/WordOccurrence.cpp inc/WordList.cpp src/main.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/lab2

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@
clean:
		rm -rf *o inc/*.o src/*.o $(EXECUTABLE)
