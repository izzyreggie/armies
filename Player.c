//
//  Player.c
//  Armies
//
//  Created by Isaac Caldwell on 3/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Player.h"

int initPlayer( int x, int y )
{
    playerX = x;
    playerY = y;
    
    return 0;
}


int movePlayer( int dir )
{
    switch ( dir )
    {
        case UP:
            if( playerY > gameAreaY )
            {
                playerY--;
            }
            break;
        case DOWN:
            if( playerY < gameAreaYplusHeight )
            {
                playerY++;
            }
            break;
        case LEFT:
            if( playerX > gameAreaX )
            {
                playerX--;
            }
            break;
        case RIGHT:
            if( playerX < gameAreaXplusWidth )
            {
                playerX++;
            }
            break;
        default:
            return 1;
            
    }
    return 0;
}

int drawPlayer( )
{
    return mvaddch( playerY, playerX, '@' );
}

int hurtCommander( int damage )
{
    commanderCurrentHP = commanderCurrentHP - damage;
    return 0;
}