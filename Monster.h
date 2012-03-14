//
//  Monster.h
//  Armies
//
//  Created by Isaac Caldwell on 3/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//


#ifndef MONSTER_H
#define MONSTER_H

#include "globalFunctions.h"

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

struct monster listofMonsters[ 20 ];
int monsterListFilledTo;

void addMonsterToList( struct monster *target );

void removeMonsterFromList( int indexToRemoveFrom );

void createMonster( int maxHP, int attack, char* name, int X, int Y, char graphic );

int nameMonster( struct monster *target, char* newName );

int attackPlayerCommander( struct monster *attacker );

int hurtMonster( struct monster *target, int damage );

int drawMonster( struct monster *attacker );

int updateMonster( struct monster *target );


#endif