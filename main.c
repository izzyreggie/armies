//
//  main.c
//  Armies
//
//  Created by Isaac Caldwell on 3/11/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "Player.h"

int row, col;

void update_scr( );
void draw_title( );
void make_box( int X, int Y, int WIDTH, int HEIGHT, char border );

int main( )
{
	WINDOW *mainWindow;
    
	if ( ( mainWindow = initscr( ) ) == NULL )
	{
		fprintf( stderr, "Error initializing ncurses.\n" );
		exit( EXIT_FAILURE );
	}
	
	if ( cbreak( ) != OK )
	{
		fprintf( stderr, "Error breaking c.\n" );
		exit( EXIT_FAILURE );
	}
    
	getmaxyx( stdscr, row, col );	
	keypad( mainWindow, TRUE );	
	noecho( );
    
    initPlayer( 14, 6 );
    initGameArea( 0, 3, 60, 20 );
    
    struct monster orc = createMonster( 10, 5, "Orc" );
	
	int ch;
	while( ( ch = wgetch( mainWindow ) ) != 'q' )
	{
		switch( ch )
		{
            case KEY_LEFT:
                movePlayer( LEFT );
                break;
                
            case KEY_RIGHT:
                movePlayer( RIGHT );
                break;
                
            case KEY_UP:
                movePlayer( UP );
                break;
                
            case KEY_DOWN:
                movePlayer( DOWN );
                break;
		}
        
		update_scr( mainWindow );
	}
    
	endwin( );
    
	return EXIT_SUCCESS;
}

void update_scr( WINDOW *local_win )
{
	clear( );
	
    drawGameArea( );
    drawPlayer( );
	draw_title( );
	make_box( getGameAreaXplusWidth( ) + 1, getGameAreaY( ), col, row - 2, '+' );
	make_box( 0, getGameAreaYplusHeight( ) + 1, col, row, '+' );
    move( row-1, col-1 );
	
	refresh( );
}

void draw_title( )
{	
	int i;
	move( 0, 0 );
	for( i = 0; i != col; i++)
	{
		addch( '-' );
	}
	mvprintw( 1, col/2, "ARMIES" );
	move( 2, 0 );
	for( i = 0; i != col; i++ )
	{
		addch( '-' );
	}
}

void make_box( int X, int Y, int WIDTH, int HEIGHT, char border )
{
	int hminusone = HEIGHT-1;
	int wminusone = WIDTH-1;
    int i;
	for( i = X; i != WIDTH; i++ )
	{
		mvaddch( hminusone, i, border );
		mvaddch( Y, i, border );
	}
	for( i = Y; i != HEIGHT; i++ )
	{	
		mvaddch( i, wminusone, border );
		mvaddch( i, X, border );
	}
}
