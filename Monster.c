//
//  Monster.c
//  Armies
//
//  Created by Isaac Caldwell on 3/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "Monster.h"

void addMonsterToList( struct monster *target )
{
    listofMonsters[ monsterListFilledTo ] = *target;
    monsterListFilledTo++;
}

void removeMonsterFromList( int indexToRemoveFrom )
{
    swapMonsters( indexToRemoveFrom, --monsterListFilledTo );
}

void createMonster( int maxHP, int attack, char* name, int X, int Y, char graphic )
{
    struct monster newMonster;
    newMonster.maxHP = maxHP;
    newMonster.currentHP = maxHP;
    newMonster.attack = attack;
    newMonster.identifier = monsterListFilledTo;
    
    newMonster.X = X;
    newMonster.Y = Y;
    newMonster.graphic = graphic;
    
    nameMonster( &newMonster, name );
    addMonsterToList( &newMonster );
}

int nameMonster ( struct monster *target, char* newName )
{
    target->name = malloc( sizeof( newName ) );
    strcpy( target->name, newName );
    return 0;
}

int attackPlayerCommander( struct monster *attacker )
{
    hurtCommander( attacker->attack );
    return 0;
}

int hurtMonster( struct monster *target, int damage )
{
    struct monster temporaryMonster = *target;
    target->currentHP = target->currentHP - damage;
    if ( target->currentHP < 1 )
    {
        target->identifier = -1;
        removeMonsterFromList( temporaryMonster.identifier );
        temporaryMonster.identifier = -1;
    }
    char string[64];
    if ( temporaryMonster.identifier == -1 )
    {
        sprintf( string, "Killed a(n) " );
    }
    else
    {
        sprintf( string, "Attacked a(n) " );
    }
    strcat( string, temporaryMonster.name );
    changeMessage( string  );
    return 0;
}

int drawMonster( struct monster *target )
{
    if ( target->identifier != -1 )
    {
        return mvaddch( target->Y, target->X, target->graphic );
    }
    else
    {
        return mvaddch( target->Y, target->X, '%' );

    }
    return 0;
}

int updateMonster( struct monster *target )
{
    int ch = random( ) % 4;
    
    switch ( ch )
    {
        case 0:
            if ( checkCollision( target->X + 1, target->Y ) == NULL )
            {
                if ( target->X < getGameAreaXplusWidth( ) )
                {
                    target->X++;
                }
            }
            break;
            
        case 1:
            if ( checkCollision( target->X - 1, target->Y ) == NULL )
            {
                if ( target->X > getGameAreaX( ) )
                {
                    target->X--;
                }
            }
            break;
            
        case 2:
            if ( checkCollision( target->X, target->Y + 1 ) == NULL )
            {
                if ( target->Y < getGameAreaYplusHeight( ) )
                {
                    target->Y++;
                }
            }
            break;
            
        case 3:
            if ( checkCollision( target->X, target->Y - 1 ) == NULL )
            {
                if ( target->Y > getGameAreaY( ) )
                {
                    target->Y--;
                }
            }
            break;
            
        default:
            target->X++;
            target->Y--;
            break;
    }
    
    return 0;
}