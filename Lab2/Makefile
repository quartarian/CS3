# Makefile for Lab 7
# CS 23021 Separate Files Lab

# Makefile "variables", occurrences of ${CXX} are replaced with g++
CXX = g++
CXXFLAGS = -Wall

#----------------------------------------------------------------------------
# Link, make shapes executable

#target: (tab) file_1_it_needs (space) file_2_it_needs  #called dependencies
#(tab)  rule_to_make_dependencies
lab2:	WordOccurrence.o WordList.o main.o
	${CXX} ${CXXFLAGS} WordOccurrence.o WordList.o main.o -o bin/lab2

# Compile Main
main.o: src/main.cpp 
	${CXX} ${CXXFLAGS} -c src/main.cpp

# Compile WordOccurrence Class
WordOccurrence.o:   inc/WordOccurrence.h inc/WordOccurrence.cpp
	${CXX} ${CXXFLAGS} -c inc/WordOccurrence.cpp

# Compile WordList Class
WordList.o: inc/WordList.h inc/WordList.cpp 
	${CXX} ${CXXFLAGS} -c inc/WordList.cpp

#----------------------------------------------------------------------------
clean:
	rm -f lab2  # remove the executable avg file
	rm -f *.o  # remove ALL object files in the directory

