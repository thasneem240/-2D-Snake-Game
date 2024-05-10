/**************************************************************************
 * File: input.c										  		  		  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * Date Created:04/09/2021                            				      *
 * Date Modified: 10/09/2021                              				  *               
 * Purpose: Get input from user without pressing "enter key" everytime.	  *
 **************************************************************************/
 
 #include <stdio.h>
 #include "input.h"
 #include "terminal.h"
 
void getInput( int* rowOfPlayer, int* colOfPlayer, int rowOfGoal, 
			   int colOfGoal, char** array )
{
	/* variable Declarations */
	
	char ch;
	char playerCh;
	
	do
	{
		/* disable the terminal buffer temporarily */
		
		disableBuffer(); 
		
		/* get the input from user */
		
		scanf(" %c", &ch); 
		
		/* enable the terminal buffer */
		
		enableBuffer(); 
		
		if( ch == 'w')
		{
			playerCh = '^';
			
			/* moves the player one block above, 
			   ONLY if there is an empty space or Goal */
			
			if(  ( array[*(rowOfPlayer)-1][*colOfPlayer] == ' ' )
				|| ( array[*(rowOfPlayer)-1][*colOfPlayer] == 'x' ) )
			{
				/* Assign space to current position of the player */
				
				array[*rowOfPlayer][*colOfPlayer] = ' '; 
				
				/* change the player row */
				
				*rowOfPlayer = *(rowOfPlayer)-1; 
			}
			
		}
		else
		{
			if( ch == 's')
			{
				playerCh = 'v';
				
				/* moves the player one block below, 
				   ONLY if there is an empty space or Goal */
				
				if(  ( array[*(rowOfPlayer)+1][*colOfPlayer] == ' ' )
					|| ( array[*(rowOfPlayer)+1][*colOfPlayer] == 'x' ) )
				{
					array[*rowOfPlayer][*colOfPlayer] = ' '; 
					*rowOfPlayer = *(rowOfPlayer)+1; 
				}
				
			}
			else
			{
				if( ch == 'a')
				{
					playerCh = '<';
					
					/* moves the player one block left,
					   ONLY if there is an empty space or Goal */
					
					if(  ( array[*rowOfPlayer][*(colOfPlayer)-1] == ' ' )
						|| ( array[*rowOfPlayer][*(colOfPlayer)-1] == 'x' ) )
					{
						array[*rowOfPlayer][*colOfPlayer] = ' '; 
						
						/* change the player column */
						
						*colOfPlayer = *(colOfPlayer)-1;
					}
					
				}
				else
				{
					if( ch == 'd')
					{
						playerCh = '>';
						
						/* moves the player one block right,
						   ONLY if there is an empty space or Goal */
						
						if(  ( array[*rowOfPlayer][*(colOfPlayer)+1] == ' ' ) 
						  || ( array[*rowOfPlayer][*(colOfPlayer)+1] == 'x' ) )
						{
							array[*rowOfPlayer][*colOfPlayer] = ' '; 
							*colOfPlayer = *(colOfPlayer)+1;
						}
						
					}
					else
					{
						/* Output the warning message */
						
						printf("\n Please input w,s,a or d to"
						       " control this game!!\n" );
					}
				}
			}
		}
		
		/* Assign playerCh to current position of the player */
		
		array[*rowOfPlayer][*colOfPlayer] = playerCh; 
		
	/* loop until get the correct input */
	
	}while( !(ch == 'w' || ch == 's' || ch == 'a' || ch == 'd') ); 
}