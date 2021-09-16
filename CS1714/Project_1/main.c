/*
	main.c
	Project 1
	Shane Perry

	This program is a probability game between two players. Each player will roll the dice to recieve points that are decided at random based on the type of
	round. Player 1 will recieve points if they roll evens while Player 2 will recieve points if they roll on odds. If Player 1 rolls odds they lose points and then
	Player 2 gets to roll. If Player 2 rolls evens they lose points and Player 1's turn will be next. The number of rounds is determined by the user. The player with
	the most points wins! 

	main.c is the driver for the program and contains the main logic for the game.
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"dicegame.h"



// Start the main() function with both the parameters

int main(int argc, char*argv[])

{

	// Initialize the srand() to start the random generator

	srand(time(NULL));

	// Initialize the player-1 and player-2 points to 0

	int p1 = 0;
	int p2 = 0;

	// Initialize all other required variables

	int i;
	int userRounds;
	int*  numRounds;
	int curPlayer;
	ROUNDTYPE round;
	int diceRoll;
	int points;



	// Ask the user for the number of rounds to run the game

	printf("Enter the number of rounds: ");

	scanf("%d", &userRounds);
	numRounds = (int*)malloc(userRounds * sizeof(int));

	// Call printPlayerPoints() function to print the initial player points which will be 0

	printPlayerPoints(p1, p2);

	curPlayer = getRandomNumber(1, 2);	

	// Set up the loop to go through all the rounds one at a time
	for( i = 0; i < userRounds; i++ )
	{

		printf("\nROUND %d\n--------\n", i+1);
		printf("Player\t: %d\n", curPlayer); // Print current player

		// Calls the corresponding functions to get the information for this round - type, dice, points
		round = getRoundType();
		diceRoll = getRandomNumber( 1, 6 );
		points = getRoundPoints( round );
	

		if( curPlayer == 1 )
		{
			if( diceRoll % 2 == 0 )
			{
				p1 += points;
			}
			else
			{
				p1 -= points;
				curPlayer = 2;
			}
		}
		else if( curPlayer == 2 )
		{
			if( diceRoll % 2 == 1 ) 
			{
				p2 += points;
			}
			else
			{
				p2 -= points;
				curPlayer = 1;
			}
		}



		// Call printRoundInfo() to print the round information
		printRoundInfo( round, diceRoll, points );
		
		// Call printPlayerPoints() to print the player information at the end of the round
		printPlayerPoints( p1, p2 );
		
		printf("\n");		
		
	}

	
	printf("\nGAME OVER!!\n");

	// Compare the final points for player-1 and player-2
	// Print the winner as the one with higher points
	
	if( p1 > p2 )
	{
		printf("P1 Won\n");
	}
	else
	{
		printf("P2 Won\n");
	}


	// Return from the main() function to end the program successfully

	return 0;

}
