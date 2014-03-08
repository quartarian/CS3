CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=source/Process.cpp source/State.cpp source/main.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab7

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@
clean:
		rm -rf *o source/*o *.exe $(EXECUTABLE)
