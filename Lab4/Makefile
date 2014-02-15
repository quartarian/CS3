CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=inc/Figure.cpp inc/Square.cpp inc/Triangle.cpp src/main.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/lab4

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@
clean:
		rm -rf *o inc/*o src/*o $(EXECUTABLE)
