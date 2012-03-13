//
//  GameArea.c
//  Armies
//
//  Created by Isaac Caldwell on 3/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "GameArea.h"

int initGameArea( int x, int y, int xplusw, int yplush )
{
    gameAreaX = x;  gameAreaXplusWidth = xplusw;
    gameAreaY = y; gameAreaYplusHeight = yplush;
    
    return 0;
}

int drawGameArea( )
{
    int endi = getGameAreaXplusWidth( ) + 1;
	int endj = getGameAreaYplusHeight( ) + 1;
    
    int i, j;
	for( i = getGameAreaX( ); i != endi; i++ )
    {
        for( j = getGameAreaY( ); j != endj; j++ )
        {
            mvaddch( j, i, '.' );
        }
    }
    return 0;
}

int getGameAreaX( )
{
    return gameAreaX;
}

int getGameAreaXplusWidth( )
{
    return gameAreaXplusWidth;
}

int getGameAreaWidth( )
{
    return ( gameAreaXplusWidth - gameAreaX );
}

int getGameAreaY( )
{
    return gameAreaY;
}

int getGameAreaYplusHeight( )
{
    return gameAreaYplusHeight;
}

int getGameAreaHeight( )
{
    return ( gameAreaYplusHeight - gameAreaY );
}