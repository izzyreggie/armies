//
//  Units.h
//  Armies
//
//  Created by Isaac Caldwell on 3/13/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef UNITS_H
#define UNITS_H

#include "globalFunctions.h"

struct unit {
    int attack;
    int hp;
    int number;
    int speed;
    
    char* name
};

struct unit createNewUnit( int attack, int hp, int size, int speed, char* name );

int nameUnit( struct unit *target, char *newName );

int calculateDamage( struct unit *attacker );

//determines how many in a unit die for a certain amount of damage
//if the unit is entirely killed, returns excess damage to spread to other units
int determineDamageTo( struct unit *target, int damage );

#endif