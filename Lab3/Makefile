CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=inc/SingletonSchedule.cpp src/main.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/lab3

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@
clean:
		rm -rf *o inc/*o src/*o $(EXECUTABLE)
