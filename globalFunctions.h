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

#include "Player.h"
#include "Monster.h"
#include "Units.h"
#include "GameArea.h"

char* message;

void clearMessage( );

void changeMessage( char *newMessage );

void swapUnits( int indexA, int indexB );

void swapMonsters( int indexA, int indexB );

#endif