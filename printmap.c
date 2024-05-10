/**************************************************************************
 * File: printmap.c										  		  		  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * Date Created:04/09/2021                            				      *
 * Date Modified: 09/09/2021                              				  *               
 * Purpose: print the 2d char map array				  					  *
 **************************************************************************/
 
 #include <stdio.h>
 #include "printmap.h"
 
void printTheMap( int mapRow, int mapCol, char** array, int n, 
				              int* rowOfPlayer, int* colOfPlayer )
{
	int i, j;
	
	/* Start of Conditional Compilation */
	
	#ifdef DARK
	
	/* variables Declarations only declare when activate 
	   the Conditional compilation */
	
	int mapRow1, mapRow2;
	int mapCol1, mapCol2;
	char space = ' ';
	
	if( *(rowOfPlayer) - n >= 0 )
	{
		mapRow1 = *(rowOfPlayer) - n;
	}
	else
	{
		mapRow1 = 0;
	}
	
	if( *(rowOfPlayer) + n < mapRow )
	{
		mapRow2 = *(rowOfPlayer) + n;
	}
	else
	{
		/* rows are start from 0 */
		
		mapRow2 = mapRow-1; 
	}
	
	
	if( *(colOfPlayer) - n >= 0 )
	{
		mapCol1 = *(colOfPlayer) - n;
	}
	else
	{
		mapCol1 = 0;
	}
	
	if( *(colOfPlayer) + n < mapCol )
	{
		mapCol2 = *(colOfPlayer) + n;
	}
	else
	{
		/* columns are start from 0 */
		
		mapCol2 = mapCol-1;  
		
	}
	
	
	/* Activate the visibility feature */
	
	for( i = 0; i < mapRow; i++ )
	{
		for( j = 0; j < mapCol; j++)
		{
			/* when n = 0 print the whole map */
			
			if( n == 0)
			{
				printf("%c ", array[i][j]);
			}
			else
			{
				/* when n > 0 print the part of the map according to n */
				
				if( ( i >= mapRow1 && i <= mapRow2 ) 
					&& ( j >= mapCol1 && j <= mapCol2) )
				{
					printf("%c ", array[i][j]);
				}
				else
				{
					printf("%c ", space);
				}
			}
			
		}
		printf("\n");
	}
	
	/* When not activate the Conditional compilation print the whole map 
	   regardless the value of the integer */
	
	#else
		
	for( i = 0; i < mapRow; i++ )
	{
		for( j = 0; j < mapCol; j++)
		{
			printf("%c ", array[i][j]);
		}
		printf("\n");
	}
	
	#endif
	
	/* End of Conditional Compilation*/
	
}