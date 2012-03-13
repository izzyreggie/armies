//
//  Units.c
//  Armies
//
//  Created by Isaac Caldwell on 3/13/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Units.h"

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