##
 # File: Makefile
 # File Created: 04, September 2021
 # Author: A.S.M. Thasneem
 # -----
 # Last Modified: 11, September 2021
 # Modified By: A.S.M. Thasneem
 # -----
 # Purpose: A make file to compile multiple files and get an Execute file
##


# Makefile Variables
CC		 = gcc
EXEC	 = maze
CFLAGS = -Wall -ansi -pedantic -g
OBJ 	 = main.o map.o setmap.o printmap.o input.o terminal.o

# Add DARK to the CFLAGS and recompile the program
ifdef DARK
CFLAGS += -D DARK
DEBUG : clean $(EXEC)
endif


$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)
	
main.o : main.c setmap.h printmap.h input.h 
	$(CC) -c main.c $(CFLAGS)
	
map.o : map.c map.h
	$(CC) -c map.c $(CFLAGS)
	
setmap.o : setmap.c setmap.h map.h
	$(CC) -c setmap.c $(CFLAGS)
	
printmap.o : printmap.c printmap.h
	$(CC) -c printmap.c $(CFLAGS)

input.o : input.c input.h terminal.h
	$(CC) -c input.c $(CFLAGS)	
	
terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)
	
clean :
	rm -f $(EXEC) $(OBJ)