//
//  Player.h
//  Armies
//
//  Created by Isaac Caldwell on 3/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "GameArea.h"
#include "Monster.h"
#include "globalFunctions.h"

struct unit {
    int attack;
    int hp;
    int number;
    int speed;
    char* name
};

enum Condition {
    SLOW = 0,
    WEAK = 1,
    POISONED = 2,
    CONFUSED = 3
};

enum checkDirection 
{
    CHKUP = -1,
    CHKLEFT = -1,
    CHKDOWN = 1,
    CHKRIGHT = 1
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

int playerX, playerY;
int commanderAttack, commanderMaxHP, commanderCurrentHP;
int speed;
int companion;

struct unit army[ 10 ];

int initPlayer( int x, int y, int maxHP, int attack, int initialSpeed );

int movePlayer( int dir );

int drawPlayer( );

int hurtCommander( int damage );

int commanderAttackTarget( struct monster *target );

int armyAttack( );

struct monster* checkCollision( int testLocationX, int testLocationY );

int reallyMove( int *current, int check, struct monster *collideWith, int UPorLEFT );

#endif