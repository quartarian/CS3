CC=g++ -std=c++0x
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=source/main.cpp source/person.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab9

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@
clean:
		rm -rf *o source/*o $(EXECUTABLE)
