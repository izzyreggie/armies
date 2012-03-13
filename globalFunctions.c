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