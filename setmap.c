/**************************************************************************
 * File: setmap.c										  		  		  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * Date Created:04/09/2021                            				      *
 * Date Modified: 09/09/2021                              				  *               
 * Purpose: Set the map from metadata				  					  *
 **************************************************************************/
 
 #include <stdio.h>
 #include <stdlib.h>
 #include "setmap.h"
 #include "map.h"
 
void setTheMap(int* mapRow, int* mapCol, char*** pArray, int* rowOfPlayer, 
						int* colOfPlayer, int* rowOfGoal, int* colOfGoal   )
{
	/* variables and  pointers Declarations*/
	
	int i, j, k, l;
	char objCode;
	int** metadataTable = NULL;
	int metadataAmount;
	char** array = NULL;
	
	/* Retrieve the metadata from function getMetadata */
	
	getMetadata( &metadataTable, &metadataAmount, mapRow, mapCol); 
	
	/* generate a 2d char map Array */
	
	array = (char**)malloc(sizeof(char*) * *mapRow);
	for( i = 0; i < *mapRow; i++)
	{
		array[i] = (char*)malloc(sizeof(char) * *mapCol );
	}
	
	
	/* set the borders around the map */
	
	for( i = 0; i < *mapRow; i++ )
	{
		for( j = 0; j < *mapCol; j++)
		{
			if( i == 0 || i == *(mapRow)-1)
			{
				if( j == 0 || j == *(mapCol)-1)
				{
					array[i][j] = '#';
				}
				else
				{
					array[i][j] = '-';
				}
			}
			else
			{
				if( j == 0 || j == *(mapCol)-1 )
				{
					array[i][j] ='|';
				}
				else
				{
					array[i][j] =' ';
				}
			}
			
			
		}
		
	}
	
	
	/* set the player, goal and walls in the map */
	
	for( i = 0; i < metadataAmount; i++ )
	{
		/* metadataTable row always has 3 integers so j < 3 */
		
		for( j = 0; j < 3; j++)
		{
			if( j == 0)
			{
				/* Get the row of the object */
				
				k = metadataTable[i][j]; 
				
				/* Assume first two entries are always 
				   the player and the goal position.*/
				
				if( i == 0) 
				{
					/* Get the row of the Player */
					
					*rowOfPlayer = metadataTable[i][j]; 
				}
				
				if( i == 1) 
				{
					/* Get the row of the Goal */
					
					*rowOfGoal = metadataTable[i][j]; 
				}
			}
			else
			{
				if( j == 1)
				{
					/* Get the column of the object */
					
					l = metadataTable[i][j]; 
					
					/* Assume first two entries are always 
					   the player and the goal position.
					   Get the column of the Player */
						
					if( i == 0) 
					{
						*colOfPlayer = metadataTable[i][j]; 
					}
					
					/* Get the column of the Goal */
					
					if( i == 1) 
					{
						*colOfGoal = metadataTable[i][j]; 
					}
					
				}
				else
				{
					if( metadataTable[i][j] == 0) 
					{
						objCode = '^';
					}
					else
					{
						if( metadataTable[i][j] == 1)
						{
							objCode = 'x';
						}
						else
						{
							if( metadataTable[i][j] == 2)
							{
								objCode = 'o';
							}
						}
					}
				}
			}
			
		}
		
		array[k][l] = objCode;
	}
	
	/* pass the address of malloc 2d array to *pArray in the main function */
	
	*pArray = array; 
	
	
	/* free metadataTable malloc 2d Array from heap memory */
	
	for( i = 0 ; i < metadataAmount ; i++)
    {
        free( metadataTable[i] );
    }
	
	free( metadataTable );
	
	/* Assign the pointer to NULL */
	
	metadataTable = NULL; 
	
}