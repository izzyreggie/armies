//
//  globalFunctions.c
//  Armies
//
//  Created by Isaac Caldwell on 3/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "globalFunctions.h"

void changeMessage( char* newMessage )
{
    message = malloc( sizeof( newMessage ) );
    strcpy( message, newMessage );
}

int randInt( int from, int to )
{
    randSeed = ( randSeed % to ) + from;
    return randSeed;
}

void setSeed( int setTo )
{
    srandom( time( 0 ) );
    randSeed = setTo;
}