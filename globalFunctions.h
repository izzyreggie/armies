//
//  globalFunctions.h
//  Armies
//
//  Created by Isaac Caldwell on 3/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GLOBALS_H
#define GLOBALS_H

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>

char* message;
int randSeed;

void changeMessage( char* newMessage );

int randInt( int from, int to );

void setSeed( int setTo );

#endif