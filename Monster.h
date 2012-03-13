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
    
    int X;
    int Y;
    
    char* name;
    char graphic;
};

int UID;

struct monster listofMonsters[ 20 ];

struct monster createMonster( int maxHP, int attack, char* name, int X, int Y, char graphic );

int nameMonster( struct monster *target, char* newName );

int attackPlayerCommander( struct monster *attacker );

int hurtMonster( struct monster *target, int damage );

int drawMonster( struct monster *attacker );


#endif