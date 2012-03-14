//
//  Units.c
//  Armies
//
//  Created by Isaac Caldwell on 3/13/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Units.h"

void displayUnitsInArmy( int beginDisplayX, int beginDisplayY )
{
    int i;
    for ( i = 0; i != armyFilledTo; i++ )
    {
        mvprintw( beginDisplayY + i, beginDisplayX, "%s: %d", army[ i ].name, army[ i ].number );
    }
}

void addUnitToArmy( struct unit *target )
{
    army[ armyFilledTo ] = *target;
    armyFilledTo++;
}

void removeUnitFromArmy( int indexToRemove )
{
    swapUnits( indexToRemove, armyFilledTo );
    armyFilledTo--;
}

struct unit createNewUnit( int attack, int hp, int size, int speed, char* name )
{
    struct unit newUnit;
    newUnit.attack = attack;
    newUnit.hp = hp;
    newUnit.number = size;
    newUnit.speed = speed;
    
    nameUnit( &newUnit, name );
    
    return newUnit;
}

int nameUnit ( struct unit *target, char* newName )
{
    target->name = malloc( sizeof( newName ) );
    strcpy( target->name, newName );
    return 0;
}

int calculateDamage( struct unit *attacker )
{
    return ( attacker->attack * attacker->number );
}

int determineDamageTo( struct unit *target, int damage )
{
    int unitsKilled = floor( damage / target->hp );
    int remainderDamage = ( damage % target->hp );
    
    target->number = target->number - unitsKilled;
    
    if ( target->number < 0 )
    {
        target->number = -1;
        return ( abs( target->number ) * target->hp ) + remainderDamage;   //overflow
    }
    return 0;
}