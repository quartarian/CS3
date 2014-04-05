CC=g++ -std=c++0x
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=source/main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab10

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@
clean:
		rm -rf *o source/*o $(EXECUTABLE)
