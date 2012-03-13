//
//  GameArea.h
//  Armies
//
//  Created by Isaac Caldwell on 3/12/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GAMEAREA_H
#define GAMEAREA_H

int gameAreaX, gameAreaY, gameAreaXplusWidth, gameAreaYplusHeight;

int initGameArea( int x, int y, int xplusw, int yplush );

int drawGameArea( );

int getGameAreaX( );
int getGameAreaXplusWidth( );
int getGameAreaWidth( );


int getGameAreaY( );
int getGameAreaYplusHeight( );
int getGameAreaHeight( );


#endif