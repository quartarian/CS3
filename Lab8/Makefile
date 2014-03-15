CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=source/main.cpp source/Figures.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab8

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@
clean:
		rm -rf *o source/*o *.exe $(EXECUTABLE)
