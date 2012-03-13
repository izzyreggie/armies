//
//  Player.c
//  Armies
//
//  Created by Isaac Caldwell on 3/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Player.h"

int initPlayer( int x, int y, int maxHP, int attack, int initialSpeed )
{
    playerX = x;
    playerY = y;
    
    commanderMaxHP = maxHP;
    commanderCurrentHP = commanderMaxHP;
    
    commanderAttack = attack;
    
    speed = initialSpeed;
    
    return 0;
}


int movePlayer( int dir )
{
    struct monster *collideWith;
    switch ( dir )
    {
        case UP:
            reallyMove( &playerY, ( playerY > getGameAreaY( ) ), collideWith, CHKUP );
            break;
        case DOWN:
            reallyMove( &playerY, ( playerY < getGameAreaYplusHeight( ) ), collideWith, CHKDOWN );
            break;
        case LEFT:
            reallyMove( &playerX, ( playerX > getGameAreaX( ) ), collideWith, CHKLEFT );
            break;
        case RIGHT:
            reallyMove( &playerX, (playerX < getGameAreaXplusWidth( ) ), collideWith, CHKRIGHT );
            break;
        default:
            return 1;
            break;
    }
    return 0;
}

int drawPlayer( )
{
    int statsY = getGameAreaY( ) + 1;
    int statsX = getGameAreaXplusWidth( ) + 2;
    mvprintw( statsY, statsX, "HP: %d / %d", commanderCurrentHP, commanderMaxHP );
    mvprintw( statsY + 1, statsX, "Attack: %d", commanderAttack );
    mvprintw( statsY + 2, statsX, "Speed: %d", speed );

    return mvaddch( playerY, playerX, '@' );
}

int hurtCommander( int damage )
{
    commanderCurrentHP = commanderCurrentHP - damage;
    return 0;
}

int commanderAttackTarget( struct monster* target )
{
    hurtMonster( target, commanderAttack );
    char* string = malloc( sizeof( "Attack" ) );
    strcpy( string, "Attacked " );
    strcat( string, target->name );
    changeMessage( string  );
    refresh( );
    return 0;
}

struct monster* checkCollision( int testLocationX, int testLocationY )
{
    int i;
    for ( i = 0; i != UID; i++ )
    {
        if ( testLocationX == listofMonsters[ i ].X && testLocationY == listofMonsters[ i ].Y )
        {
            return &listofMonsters[ i ];
        }
        else
        {
            //don't do anything
        }
    }
    return NULL;
}

int reallyMove( int *current, int check, struct monster* collideWith, int direction )
{
    int k = direction * 1;
    collideWith = checkCollision( playerX, *current + k );
    if ( collideWith == NULL ) { collideWith = checkCollision(*current + k, playerY ); }
    if( ( check == TRUE ) && collideWith == NULL )
    {
        *current = *current + k;
    }
    else if ( collideWith != NULL)
    {
        commanderAttackTarget( collideWith );
    }
    
    return 0;
}