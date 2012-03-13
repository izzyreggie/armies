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
#include <string.h>

#include "Player.h"
#include "globalFunctions.h"

int row, col;

void update_scr( );
void draw_title( );
void make_box( int X, int Y, int WIDTH, int HEIGHT, char border );
void changeMessage( char* newMessage );

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
    
    initPlayer( 0, 3, 10, 1, 1 );
    initGameArea( 0, 3, 60, 20 );
    changeMessage(" ");
    UID = 0;
    
    listofMonsters[ UID ] = createMonster( 10, 5, "Orc", 20, 20, 'O' );
    listofMonsters[ UID ] = createMonster( 12, 3, "Bear", 15, 15, 'B' );
    listofMonsters[ UID ] = createMonster( 4, 7, "Kobold", 2, 4, 'K' );
    
    listofMonsters[ UID ] = createMonster( 21, 9, "Grue", 34, 19, 'G' );
    listofMonsters[ UID ] = createMonster( 6, 5, "Goblin", 17, 5, 'g' );
    listofMonsters[ UID ] = createMonster( 12, 7, "Catoblepas", 6, 9, 'C' );
    
    listofMonsters[ UID ] = createMonster( 6, 5, "Goblin", 18, 5, 'g' );
    listofMonsters[ UID ] = createMonster( 6, 5, "Goblin", 17, 6, 'g' );
    listofMonsters[ UID ] = createMonster( 6, 5, "Goblin", 18, 4, 'g' );
    
    listofMonsters[ UID ] = createMonster( 6, 5, "Goblin", 54, 17, 'g' );
    listofMonsters[ UID ] = createMonster( 6, 5, "Goblin", 55, 17, 'g' );
    listofMonsters[ UID ] = createMonster( 6, 5, "Goblin", 54, 18, 'g' );
    
    listofMonsters[ UID ] = createMonster( 6, 5, "Goblin", 53, 17, 'g' );
    listofMonsters[ UID ] = createMonster( 6, 5, "Goblin", 54, 19, 'g' );
    listofMonsters[ UID ] = createMonster( 6, 5, "Goblin", 52, 19, 'g' );
    
    listofMonsters[ UID ] = createMonster( 6, 5, "Goblin", 51, 16, 'g' );
    listofMonsters[ UID ] = createMonster( 6, 5, "Goblin", 51, 17, 'g' );
    listofMonsters[ UID ] = createMonster( 6, 5, "Goblin", 51, 18, 'g' );
    
    listofMonsters[ UID ] = createMonster( 6, 5, "Goblin", 51, 13, 'g' );
    listofMonsters[ UID ] = createMonster( 6, 5, "Gelatinous Tarrasque", 52, 16, 'T' );


	changeMessage( "It is very dark in here. You are likely to be eaten by a grue." );
    
    int runOnce = 0;
	int ch;
    srandom( ( unsigned int )time( 0 ) );
	do
	{
        if ( runOnce != 0 )
        {
            int i;
            for ( i = 0; i < ( UID - 1 ); i++ )
            {
                updateMonster( &listofMonsters[ i ] );
            }
            changeMessage( " " );
            //update monsters here, I suppose
        } 
        else
        {
            //do first loop stuff, like NOT update all the monsters
            runOnce++;
        }
        
		switch( ch )
		{
            case KEY_LEFT:
                ch = LEFT;
                break;
                
            case KEY_RIGHT:
                ch = RIGHT;
                break;
                
            case KEY_UP:
                ch = UP;
                break;
                
            case KEY_DOWN:
                ch = DOWN;
                break;
            default:
                ch = NOTHING;
                break;
		}
        updatePlayer( ch );
		update_scr( mainWindow );
	} while ( getCommanderStatus( ) == STOP || ( ch = wgetch( mainWindow ) ) != 'q' );
    
    int i;
    for ( i = 0; i != UID; i++ )
    {
        free( listofMonsters[ i ].name );
    }
    free( message );
	endwin( );
    
	return EXIT_SUCCESS;
}

void update_scr( WINDOW *local_win )
{
	clear( );
	
    draw_title( );
	make_box( getGameAreaXplusWidth( ) + 1, getGameAreaY( ), col, row - 2, 'x' );
	make_box( 0, getGameAreaYplusHeight( ) + 1, col, row, 'x' );
    drawGameArea( );
    
    int i;
    for( i = 0; i != UID; i++ )
    {
        drawMonster( &listofMonsters[ i ] );
    }
    drawPlayer( );
    
    mvprintw( getGameAreaYplusHeight( ) + 2, 1, message );
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
	mvprintw( 1, ( col/2 )-3, "ARMIES" );
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
