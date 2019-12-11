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
01 := ~/Documents/RCMX_Code/Spiral03

# Command: make cornReadTest and corn1
# Use of a Linked List with a sort in C

cornRead1Objs := $(01)/cornRead1.o

cornRead1: $(cornRead1Objs)
				$(PP) $(CXXFLAGS) -o $(01)/cornRead1 $(cornRead1Objs)

cornRead1.o: $(01)/cornRead1.cpp
				$(PP) $(CXXFLAGS) -c $(01)/cornRead1.cpp


# Make all
all: cornRead1

# Make clean
clean :
	rm -rf *.o cornRead1
