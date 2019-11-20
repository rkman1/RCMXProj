# Author:Ray Kman
# E-mail: rkman@nd.edu
#
# This is the Makefile for cornRead

# GCC is for the GCC compiler for C
CC := gcc

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror
CFLAGS := -std=c11 $(FLAGS)
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
01 := ~/Documents/RCMX_Code/Spiral01

# Command: make cornReadTest and corn1
# Use of a Linked List with a sort in C

cornReadTestObjs := $(01)/cornReadTest.o

corn1Objs := $(01)/corn1.o

cornReadTest: $(cornReadTestObjs)
		$(PP) $(CXXFLAGS) -o $(01)/cornReadTest $(cornReadTestObjs)

cornReadTest.o: $(01)/cornReadTest.cpp
		$(PP) $(CXXFLAGS) -c $(01)/cornReadTest.cpp

corn1: $(corn1Objs)
				$(PP) $(CXXFLAGS) -o $(01)/corn1 $(corn1Objs)

corn1.o: $(01)/corn1.cpp
				$(PP) $(CXXFLAGS) -c $(01)/corn1.cpp


# Make all
all: cornReadTest corn1

# Make clean
clean :
	rm -rf *.o cornReadTest
