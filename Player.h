//
//  Player.h
//  Armies
//
//  Created by Isaac Caldwell on 3/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "globalFunctions.h"

enum Condition {
    NORMAL = 0,
    SLOW = 1,
    WEAK = 2,
    POISONED = 3,
    CONFUSED = 4,
    STOP = 5
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
    RIGHTDOWN = 31,
    NOTHING = 11
};

int playerX, playerY;
int commanderAttack, commanderMaxHP, commanderCurrentHP, commanderStatus;
int conditionDuration;
int speed;
int companion;

int armyFilledTo;

int initPlayer( int x, int y, int maxHP, int attack, int initialSpeed );

int updatePlayer( int dir );

int drawPlayer( );

int hurtCommander( int damage );

int commanderAttackTarget( struct monster *target );

int armyAttack( );

struct monster* checkCollision( int testLocationX, int testLocationY);

int movePlayer( int *current, int check, struct monster *collideWith, int direction );

int getCommanderStatus( );

void changeCommanderStatus( int newStatus, int duration );

#endif