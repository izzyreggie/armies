//
//  globalFunctions.c
//  Armies
//
//  Created by Isaac Caldwell on 3/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "globalFunctions.h"

void changeMessage( char *newMessage )
{
    free( message );
    message = malloc( sizeof( newMessage ) );
    strcpy( message, newMessage );
}

void swapUnits( int indexA, int indexB )
{
    struct unit temporaryUnit = army[ indexA ];
    army[ indexA ] = army[ indexB ];
    army[ indexB ] = temporaryUnit;
    
}

void swapMonsters( int indexA, int indexB )
{
    //listofMonsters[ indexA ].identifier = indexB;
    listofMonsters[ indexB ].identifier = indexA;
    
    struct monster temporaryMonster = listofMonsters[ indexA ];
    listofMonsters[ indexA ] = listofMonsters[ indexB ];
    listofMonsters[ indexB ] = temporaryMonster;
    
}