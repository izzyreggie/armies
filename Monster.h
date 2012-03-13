//
//  Monster.h
//  Armies
//
//  Created by Isaac Caldwell on 3/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//


#ifndef MONSTER_H
#define MONSTER_H

#include "Player.h"

struct monster {
    int maxHP;
    int currentHP;
    int attack;
    int identifier;
    char* name;
};

int UID;

struct monster createMonster( int maxHP, int attack, char* name );

int nameMonster( struct monster *target, char* newName );

int attackPlayerCommander( struct monster *attacker );


#endif