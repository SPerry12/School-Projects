#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"cards.h"


int main( int argc, char *argv[] )
{

	srand(time(NULL));
	
	int numberOfCards, i;
	int roundCount = 1;

	Card *head = NULL;
	Card *headPlayer2 = NULL;

	if( argc != 2 )
	{
		printf("ERROR: Missing number of cards\n");
		return -1;
	}

	numberOfCards = atoi(argv[1]);
	
	if( numberOfCards <= 0 )
	{
		printf("ERROR: Number of cards must be greater than 0\n");
		return -1;
	}
	
	printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN =============\n");	
	
	head = buildCards( numberOfCards );

	printf("Start size: %d\n", getLength( head ));

	printf("Player 1 starting cards: ");
	printCards( head );

	printf("Player 2 starting cards: ");
	headPlayer2 = buildCards( numberOfCards );
	printCards( headPlayer2 );
	
	printf("\n\n");

	Card *newCard = NULL;

	for(i=numberOfCards; i > 0; i--)
	{
		printf("----- ROUND %d -----\n", roundCount);
		printf("Player 1 (%d): ", getLength( head ));
		printCard( head );
		printf("\nPlayer 2 (%d): ", getLength( headPlayer2));
		printCard( headPlayer2 );
		printf("\n");

		if( head->c == 0 && headPlayer2->c == 1 )
		{
			printf("Player 1 ATTACKs and Player 2 DEFENDs.\n");

			if( head->value < headPlayer2->value )
			{
				printf("Player 1 loses and Player 2 survives.\n");
				printf("Player 1 loses their next card into the abyss.\n");
				head = removeCard( head );
				if(getLength( head ) != 0 )
				{
					head = removeCard( head );
				}
				headPlayer2 = removeCard( headPlayer2 );
			}
			else if ( head->value > headPlayer2->value )
			{
				printf("Player 1 wins.\n");
				printf("Player 1 gets a new card.\n");
				head = removeCard( head );
				headPlayer2 = removeCard( headPlayer2 );

				newCard = createCard();
				addCard( head, newCard );

			}
			else if( head->value == headPlayer2->value )
			{
				printf("Player 1 loses and Player 2 survives.\n");
				printf("Player 1 loses their next card into the abyss.");

				head = removeCard( head );
				if(getLength( head ) != 0 )
				{
					head = removeCard( head );
				}
				headPlayer2 = removeCard( headPlayer2 );
			}
		}
		else if( head->c == 1 && headPlayer2->c == 0 )
		{
			printf("Player 2 ATTACKs and Player 1 DEFENDs.\n");

				if( head->value > headPlayer2->value )
			{
				printf("Player 2 loses and Player 1 survives.\n");
				printf("Player 2 loses their next card into the abyss.\n");
				headPlayer2 = removeCard( headPlayer2 );
				if(getLength( headPlayer2 ) != 0 )
				{
					headPlayer2 = removeCard( headPlayer2 );
				}
				head = removeCard( head );
			}
			else if ( head->value < headPlayer2->value )
			{
				printf("Player 2 wins.\n");
				printf("Player 2 gets a new card.\n");
				headPlayer2 = removeCard( headPlayer2 );
				head = removeCard( head );
				newCard = createCard();
				addCard( headPlayer2, newCard );
			}
			else if( head->value == headPlayer2->value )
			{
				printf("Player 2 loses and Player 1 survives.\n");
				printf("Player 2 loses their next card into the abyss.");

				head = removeCard( head );
				headPlayer2 = removeCard( headPlayer2 );
				if(getLength( headPlayer2 ) != 0 )
				{
					headPlayer2 = removeCard( headPlayer2 );
				}
			}

		}
		else if( head->c == 2 && headPlayer2->c == 0 )
		{
			printf("Player 2 ATTACKs and Player 1 RUNs\n");
			printf("Player 1 loses their next card into the abyss.\n");
			head = removeCard( head );
			if(getLength( head ) != 0 )
				{
					head = removeCard( head );
				}
			headPlayer2 = removeCard( headPlayer2 );
		}
		else if( head->c == 2 && headPlayer2->c == 1 )
		{
			printf("Player 2 DEFENDs and Player 1 RUNs\n");
			printf("Player 2 gets a new card.\n");
			headPlayer2 = removeCard( headPlayer2 );
			
			newCard = createCard();
			addCard( headPlayer2, newCard );

			printf("Player 1 loses their next card into the abyss.\n");
			head = removeCard( head );
			if(getLength( head ) != 0 )
				{
					head = removeCard( head );
				}
		}
		else if( head->c == 0 && headPlayer2->c == 2 )
		{
			printf("Player 1 ATTACKs and Player 2 RUNs\n");
			printf("Player 2 loses their next card into the abyss.\n");
			headPlayer2 = removeCard( headPlayer2 );
			if(getLength( headPlayer2 ) != 0 )
				{
					headPlayer2 = removeCard( headPlayer2 );
				}
			head = removeCard( head );
		}
		else if( head->c == 1 && headPlayer2->c == 2 )
		{
			printf("Player 1 DEFENDs and Player 2 RUNs\n");
			printf("Player 1 gets a new card.\n");
			head = removeCard( head );
			
			newCard = createCard();
			addCard( head, newCard );

			printf("Player 2 loses their next card into the abyss.\n");
			headPlayer2 = removeCard( headPlayer2 );
			if(getLength( headPlayer2 ) != 0 )
				{
					headPlayer2 = removeCard( headPlayer2 );
				}
		}

		else if( head->c == 2 && headPlayer2->c == 2 )
		{
			printf("Both players RUN.\n");
			printf("Both players lose their next card into the abyss.\n");
			head = removeCard( head );
			if(getLength( head ) != 0 )
				{
					head = removeCard( head );
				}
			headPlayer2 = removeCard( headPlayer2 );
			if(getLength( headPlayer2 ) != 0 )
				{
					headPlayer2 = removeCard( headPlayer2 );
				}
		}
		else if( head->c == 1 && headPlayer2->c == 1 )
		{
			printf("Both players DEFEND. *YAWN*\n");
			printf("Nothing happens.\n");
			head = removeCard( head );
			headPlayer2 = removeCard( headPlayer2 );
		}
		else if( head->c == 0 && headPlayer2->c == 0 )
		{
			printf("Both players ATTACK.\n");

			if( head->value == headPlayer2->value )
			{
				printf("Nothing happens.");
				head = removeCard( head );
				headPlayer2 = removeCard( headPlayer2 );
			}
			else if( head->value > headPlayer2->value )
			{
				printf("Player 1 wins and gets a new card.\n");
				head = removeCard( head );
				
				newCard = createCard();
				addCard( head, newCard );


				printf("Player 2 loses their next card into the abyss.\n");
				headPlayer2 = removeCard( headPlayer2 );
				if(getLength( headPlayer2 ) != 0 )
				{
					headPlayer2 = removeCard( headPlayer2 );
				}
			}
			else if( head->value < headPlayer2->value )
			{
				printf("Player 2 wins and gets a new card.\n");
				headPlayer2 = removeCard( headPlayer2 );
				
				newCard = createCard();
				addCard( headPlayer2, newCard );


				printf("Player 1 loses their next card into the abyss.\n");
				head = removeCard( head );
				if(getLength( head ) != 0 )
				{
					head = removeCard( head );
				}
			}
		}


		printf("\nPlayer 1 cards: ");
		printCards( head );
		printf("Player 2 cards: ");
		printCards( headPlayer2 );
		printf("\n");
		printf("\n\n");

		if( getLength( head ) == 0 || getLength( headPlayer2 ) == 0 )
		{
			break;
		}

		roundCount++;

		
	}

	printf("============ GAME OVER  =============\n\n");

	if( getLength( head ) > getLength( headPlayer2 ))
	{
		printf("Player 2 ran out of cards. Player 1 wins.\nThe end.");
	}
	else if( getLength( head ) < getLength( headPlayer2 ))
	{
		printf("Player 1 ran out of cards. Player 2 wins.\nThe end.");
	}
	else if( getLength( head ) == getLength( headPlayer2 ))
	{
		printf("Both players ran out of cards, so both players lose.\nThe end.");
	}
	
	printf("\n");


	destroyCards( head );
	destroyCards( headPlayer2 );


	return 0;
}
