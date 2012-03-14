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
    start_color( );

	
	if ( cbreak( ) != OK )
	{
		fprintf( stderr, "Error breaking c.\n" );
		exit( EXIT_FAILURE );
	}
    
	//getmaxyx( stdscr, row, col );	
    row = 24;
    col = 80;
	keypad( mainWindow, TRUE );	
	noecho( );
    curs_set( 0 );
    init_pair( 2, COLOR_BLACK, COLOR_WHITE );
    init_pair( 1, COLOR_BLUE, COLOR_BLACK );
    
    initPlayer( 0, 3, 10, 1, 1 );
    initGameArea( 0, 3, 60, 20 );
    armyFilledTo = 0;
    monsterListFilledTo = 0;
    
    changeMessage(" ");
    
    createMonster( 10, 5, "Orc", 20, 20, 'O' );
    createMonster( 12, 3, "Bear", 15, 15, 'B' );
    createMonster( 4, 7, "Kobold", 2, 4, 'K' );
    
    createMonster( 21, 9, "Grue", 34, 19, 'G' );
    createMonster( 6, 5, "Goblin", 17, 5, 'g' );
    createMonster( 12, 7, "Catoblepas", 6, 9, 'C' );
    
    createMonster( 6, 5, "Goblin", 18, 5, 'g' );
    createMonster( 6, 5, "Goblin", 17, 6, 'g' );
    createMonster( 6, 5, "Goblin", 18, 4, 'g' );
    
    createMonster( 6, 5, "Goblin", 54, 17, 'g' );
    createMonster( 6, 5, "Goblin", 55, 17, 'g' );
    createMonster( 6, 5, "Goblin", 54, 18, 'g' );
    
    createMonster( 6, 5, "Goblin", 53, 17, 'g' );
    createMonster( 6, 5, "Goblin", 54, 19, 'g' );
    createMonster( 6, 5, "Goblin", 52, 19, 'g' );
    
    createMonster( 6, 5, "Goblin", 51, 16, 'g' );
    createMonster( 6, 5, "Goblin", 51, 17, 'g' );
    createMonster( 6, 5, "Goblin", 51, 18, 'g' );
    
    createMonster( 6, 5, "Goblin", 51, 13, 'g' );
    createMonster( 30, 9, "Tarrasque", 52, 16, 'T' );

    struct unit newUnit = createNewUnit( 1, 1, 10, 1, "Peasant" );
    addUnitToArmy( &newUnit  );
    newUnit = createNewUnit( 2, 4, 1, 2, "Knight" );
    addUnitToArmy( &newUnit );

	changeMessage( "It is very dark in here. You are likely to be eaten by a grue." );
    
    int runOnce = 0;
	int ch;
    srandom( ( unsigned int )time( 0 ) );
	do
	{
        if ( runOnce != 0 )
        {
            int i;
            //for ( i = 0; i < ( monsterListFilledTo - 1 ); i++ )
            //{
            //    updateMonster( &listofMonsters[ i ] );
            //}
            clearMessage( );
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
    for ( i = 0; i != monsterListFilledTo; i++ )
    {
        free( listofMonsters[ i ].name );
    }
    free( message );
	endwin( );
    
	return EXIT_SUCCESS;
}

void update_scr( WINDOW *local_win )
{
	//clear( );
	
    draw_title( );
	make_box( getGameAreaXplusWidth( ) + 1, getGameAreaY( ), col, row - 2, 'x' );
	make_box( 0, getGameAreaYplusHeight( ) + 1, col, row, 'x' );
    
    //attron( COLOR_PAIR( 2 ) );
    drawGameArea( );
    //attroff( COLOR_PAIR( 2 ) );
    
    int i;
    for( i = 0; i != monsterListFilledTo; i++ )
    {
        drawMonster( &listofMonsters[ i ] );
    }
    drawPlayer( );

    
//    FILE *fp;
//    if (fp = fopen("stuff.txt", "a"))
//    {
//    for( i = 0; i != 20; i++ )
//    {
//        fprintf( fp, "%s: %d ", listofMonsters[ i ].name, listofMonsters[ i ].identifier );
//    }
//        fprintf( fp, "\n" );
//        fclose( fp );
//    }
    
    //attron( COLOR_PAIR( 1 ) );
    //mvprintw( getGameAreaYplusHeight( ) + 2, 1, message );
    //attroff( COLOR_PAIR( 1 ) );

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
