//
//  Player.h
//  Armies
//
//  Created by Isaac Caldwell on 3/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "GameArea.h"
#include "Monster.h"

struct unit {
    int attack;
    int hp;
    int number;
    int speed;
    char* name
};

enum Direction {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
    LEFTUP = 20,
    RIGHTUP = 30,
    LEFTDOWN = 21,
    RIGHTDOWN = 31
};

enum Condition {
    SLOW = 0,
    WEAK = 1,
    POISONED = 2,
    CONFUSED = 3
};

int playerX, playerY;
int commanderAttack, commanderMaxHP, commanderCurrentHP;
int speed;
int companion;

struct unit army[ 10 ];

int initPlayer( int x, int y );

int movePlayer( int dir );

int drawPlayer( );

int hurtCommander( int damage );

int commanderAttackTarget( struct monster *target );

int armyAttack( );

#endif