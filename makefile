#!/bin/sh

#  makefile.sh
#  TestProject
#
#  Created by Isaac Caldwell on 12/23/11.
#  Copyright 2011 __MyCompanyName__. All rights reserved.

CC = gcc
CCFLAGS = 
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = armies

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CCFLAGS) -o $@ $(OBJECTS) -lncurses

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

%.o : %.m
	$(CC) -c -o $@ $^}