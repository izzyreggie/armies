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

struct monster createMonster( int maxHP, int attack, char* name )
{
    struct monster newMonster;
    newMonster.maxHP = maxHP;
    newMonster.currentHP = maxHP;
    newMonster.attack = attack;
    newMonster.identifier = UID;
    UID++;
    nameMonster( &newMonster, name );
    return newMonster;
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
    target->currentHP = target->currentHP - damage;
    return 0;
}