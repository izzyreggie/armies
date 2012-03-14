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


int updatePlayer( int dir )
{
    if ( conditionDuration != 0 )
    {
        conditionDuration--;
    }
    else
    {
        changeCommanderStatus( NORMAL, 0 );
    }
    
    struct monster *collideWith;
    switch ( dir )
    {
        case UP:
            movePlayer( &playerY, ( playerY > getGameAreaY( ) ), collideWith, CHKUP );
            break;
        case DOWN:
            movePlayer( &playerY, ( playerY < getGameAreaYplusHeight( ) ), collideWith, CHKDOWN );
            break;
        case LEFT:
            movePlayer( &playerX, ( playerX > getGameAreaX( ) ), collideWith, CHKLEFT );
            break;
        case RIGHT:
            movePlayer( &playerX, (playerX < getGameAreaXplusWidth( ) ), collideWith, CHKRIGHT );
            break;
        case NOTHING:
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

    char tmp[64];
    switch ( getCommanderStatus( ) )
    {
        case STOP:
            sprintf( tmp, "STOPPED" );
            break;
        case NORMAL:
            sprintf( tmp, "NORMAL" );
            break;
    }
    mvprintw( statsY + 3, statsX, "Status: %s", tmp );
    mvprintw( statsY + 4, statsX, "xxxxYour Armyxxxx" );
    displayUnitsInArmy( statsX, statsY + 5 );
    
    return mvaddch( playerY, playerX, '@' );
}

int hurtCommander( int damage )
{
    commanderCurrentHP = commanderCurrentHP - damage;
    return 0;
}

int commanderAttackTarget( struct monster* target )
{
    //hurtMonster( target, commanderAttack );
    return 0;
}

struct monster* checkCollision( int testLocationX, int testLocationY )
{
    int i;
    for ( i = 0; i != monsterListFilledTo; i++ )
    {
        if ( listofMonsters[ i ].identifier != -1 )
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
    }
    return NULL;
}

int movePlayer( int *current, int check, struct monster* collideWith, int direction )
{
    int k = direction * 1;
    collideWith = checkCollision( playerX, *current + k);
    if ( collideWith == NULL ) { collideWith = checkCollision(*current + k, playerY ); }
    if( ( check == TRUE ) && collideWith == NULL )
    {
        *current = *current + k;
    }
    else if ( collideWith != NULL )
    {
        hurtMonster( collideWith, commanderAttack );
    }
    else
    {
        changeMessage( "Bumped into a wall. Ouch!" );
    }

    return 0;
}

int getCommanderStatus( )
{
    return commanderStatus;
}

void changeCommanderStatus( int newStatus, int duration )
{
    conditionDuration = duration;
    commanderStatus = newStatus;
}