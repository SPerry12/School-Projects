/*
        dicegame.c
        Project 1
        Shane Perry

        This program is a probability game between two players. Each player will roll the dice to recieve points that are decided at random based on the type of
        round. Player 1 will recieve points if they roll evens while Player 2 will recieve points if they roll on odds. If Player 1 rolls odds they lose points and then
        Player 2 gets to roll. If Player 2 rolls evens they lose points and Player 1's turn will be next. The number of rounds is determined by the user. The player with
        the most points wins!

        dicegame.c contains the functions for this program that will determine probability for the program (dice rolls, starting player, round type) and will print
	to screen all the information for the program.
*/




#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"dicegame.h"


/*
	Function: getRandomNumber
	--------------------------
	Description: This function generates random numbers for the program. Used for
	dice rolls, probability for ROUNDTYPE, and to randomly select starting player.
	
		int min: minimum number that is needed to set range
		int max: maximum number that is needed to set range
	Returns: random number between range min-max (inclusive).
*/

int getRandomNumber( int min, int max )
{

	int ranNum;

	ranNum = rand() % ( max + 1 - min ) + min;
	
	return ranNum;

}


/*
	Function: getRoundType
	----------------------
	Description: This function determines what the type of round will be based on a certain
	probability. (60% for REGULAR, 20% BONUS, 20% DOUBLE)
		
	Returns: Funciton will return the enum that is randomly selected using getRandomNumber function
        ****ENUM is returned as an int**** (0 = BONUS, 1 = DOUBLE, 2 = REGULAR)
*/

ROUNDTYPE getRoundType()
{

	int rNumSelector = getRandomNumber( 0,9 );

	if( rNumSelector <= 5 )
	{
		return REGULAR;
	}

	else if( rNumSelector == 6 || rNumSelector == 7 )
	{
		return BONUS;
	}

	else if( rNumSelector == 8 || rNumSelector == 9 )
	{
		return DOUBLE;
	}
}


/*
	Function: getRoundPoints
	------------------------
	Description: Sets points for round based on the round type from the getRoundType function. 
	Gets a random number (1-10) from getRandomNumber function and multiplies it by 10 for REGULAR and 
	DOUBLE points. 
		
		roundType: Determined from the getRoundType function
	Returns: Points for that specific round
*/


int getRoundPoints( ROUNDTYPE roundType )
{

	int points;

	if( roundType == 2 )
	{
		points = (getRandomNumber( 1, 10 )) * 10;
	}

	else if( roundType == 0 )
	{
		points = 200;
	}

	else if( roundType == 1 )
	{
		points = (( getRandomNumber( 1,10 )) * 10 ) * 2;
	}

	return points;
}


/*
	Function: printPlayerPoints
	---------------------------
	Description: Prints player points
		p1: Player1's points
		p2: player2's points
	Return: void, but will create a print statement
*/

void printPlayerPoints( int p1, int p2 )
{

	printf("P1\t: %d\nP2\t: %d\n", p1, p2);

}

/*
	Function: printRoundInfo
	------------------------
	Description: prints each round info. Round type is printed using a switch
	due to ROUNDTYPE returning an int. 
		t:Round type - whitch will display BONUS/DOUBLE/REGULAR
		dice: Shows what player rolls
		points: displays points for the round.
	Returns: void, but will return a print statement
		
*/

void printRoundInfo( ROUNDTYPE t, int dice, int points )
{ 

	switch ( t )
	{
		case 0:
		 printf("Type\t: BONUS\n");
		  break;	 
		case 1: 
		 printf("Type\t: DOUBLE\n");
		  break;
		case 2: 
		 printf("Type\t: REGULAR\n");
		  break;	
	}

	printf("DICE\t: %d\nPOINTS\t: %d\n", dice, points);
}
