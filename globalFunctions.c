//
//  globalFunctions.c
//  Armies
//
//  Created by Isaac Caldwell on 3/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "globalFunctions.h"

void clearMessage( )
{
    int i;
    
    char buffer[ ( 78 ) ];
    for ( i = 0; i != ( 78 ); i++ )
    {
        buffer[ i ] = ' ';
    }
    changeMessage( buffer );
}

void changeMessage( char *newMessage )
{
    free( message );
    //clearMessage( );
    message = malloc( sizeof( newMessage ) );
    strcpy( message, newMessage );
    mvprintw( getGameAreaYplusHeight( ) + 2, 1, message );
}

void swapUnits( int indexA, int indexB )
{
    struct unit temporaryUnit = army[ indexA ];
    army[ indexA ] = army[ indexB ];
    army[ indexB ] = temporaryUnit;
    
}

void swapMonsters( int indexA, int indexB )
{
    listofMonsters[ indexB ].identifier = indexA;
    
    struct monster temporaryMonster = listofMonsters[ indexA ];
    listofMonsters[ indexA ] = listofMonsters[ indexB ];
    listofMonsters[ indexB ] = temporaryMonster;
    
}