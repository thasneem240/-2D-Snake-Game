/**************************************************************************
 * File: main.c										  		  			  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * Date Created:04/09/2021                            				      *
 * Date Modified: 11/09/2021                              				  *               
 * Purpose: Implement a simple maze game				  				  *
 **************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include "setmap.h"
#include "printmap.h"
#include "input.h"

int main( int argc, char* argv[] )
{
	int n, i, mapRow, mapCol;
	char** array = NULL;
	int rowOfPlayer, colOfPlayer; /* Current row and column of player */ 
	int rowOfGoal, colOfGoal; /* Current row and column of Goal */ 
	
	if( argc != 2 )
	{
		printf( "\n Error!! Please input one command line parameter" 
		        " ------> %s <visibility_distance> \n\n", argv[0] );
	}
	else
	{
		/* Convert String parameter to Integer value */
		
		n = atoi( argv[1] ); 
		
		if( n < 0)
		{
			printf( "\n Error!! Please input positive number" 
			        " as a parameter \n\n" );
		}
		else
		{
			setTheMap(  &mapRow, &mapCol, &array, &rowOfPlayer, &colOfPlayer,
						&rowOfGoal, &colOfGoal  );
			
			/* clear the terminal */
			
			system("clear"); 
			
			printTheMap(  mapRow, mapCol, array, n, &rowOfPlayer,
						  &colOfPlayer  );
			
			/* get input from user until player reach the Goal */
			
			do
			{
				getInput(  &rowOfPlayer, &colOfPlayer, rowOfGoal,
					       colOfGoal, array  );
				system("clear"); 
				printTheMap(  mapRow, mapCol, array, n, &rowOfPlayer,
							  &colOfPlayer  ); 
				
				/* When player reach the Goal position 
				   print a celebratory message */
				
				if( (rowOfPlayer == rowOfGoal) && (colOfPlayer == colOfGoal) )
				{
					printf("\n You Win! \n\n");
				}
				
			}while( !( (rowOfPlayer == rowOfGoal) 
						&& (colOfPlayer == colOfGoal) ) );
			
			
			/* free malloc 2d Array from heap memory */
	
			for( i = 0 ; i < mapRow ; i++)
			{
				free( array[i] );
			}
			
			free( array );
			
			/* Assign the pointer to NULL */
			
			array = NULL; 
		}
	}
	
	return 0;
}