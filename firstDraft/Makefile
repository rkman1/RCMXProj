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
01 := ~/RCMX_Code/firstDraft

# Command: make cornRead
# Use of a Linked List with a sort in C
cornReadObjs := $(01)/cornRead.o

cornRead: $(cornReadObjs)
	$(PP) $(CXXFLAGS) -o $(01)/cornRead $(cornReadObjs)

cornRead.o: $(01)/cornRead.cpp
	$(PP) $(CXXFLAGS) -c $(01)/cornRead.cpp

# Make all
all: cornRead

# Make clean
clean :
	rm -rf *.o cornRead
