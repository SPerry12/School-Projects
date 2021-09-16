/*

   cards.c
   Project 2
   Shane Perry

   This program is a card-based role-playing game between two (computer) players. Each player gets cards that will either be in ATTACK, DEFEND, or RUN position.
   The player with the higher card value will win the engagement. The primary purpose of this program is to familiarize the developer with the use of linked lists.

   This file contains the major functions of the program that enable cards to be created, removed, added, and printed. The functions mainly involve interacting with a linked list.

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"cards.h"

/*
   Function: createCard
   --------------------
   Dynamically allocates a new Card struct object. 
   Returns: A poiner to the newly created struct object.
*/   
Card* createCard()
{
	int randCardType, randAttack, randDefend, randRun;

	Card *card = (Card*)malloc(sizeof(Card*));
	
	randCardType = rand() % ( 10 + 1 - 1 ) + 1;

	
	if(randCardType <= 5)
	{
		card->c = 1;

		randDefend = rand() % ( 8 + 1 - 3 ) + 3;
		card->value = randDefend;
	}
	else if(randCardType > 5 && randCardType < 10)
	{
		card->c = 0;

		randAttack = rand() % ( 5 + 1 - 1 ) + 1;
		card->value = randAttack;
	}
	else if(randCardType == 10)
	{
		card->c = 2;

		randRun = rand() % ( 8 + 1 - 1 ) + 1;
		card->value = randRun;
	}

	card->next = NULL;

	return card;
}



/*
   Function: removeCard
   --------------------
   Removes and deallocates the first node in the linked list that head is pointing at. It returns the new head of the linked list.
   	Card *head: The current head of the card linked list.
   Returns: New head of linked list.
*/
Card* removeCard( Card *head )
{
	Card *temporCards = head;
	head = head->next;

	return head;
}



/*
   Function: addCard
   -----------------
   Adds a new Card struct object to the linked list. This function adds the new node in descending order of its value regardless of the action.
   	Card *head: The current head of the linked list.
	Card *c: the new Card struct object
   Returns: The new card struct linked list with the new Card struct objected added to it.
*/
Card* addCard( Card *head, Card *c )
{
	Card *temp = head;
	Card *index = NULL;
	Card *current = head;
	Card *swapCardType = head;
	int tempValue;


	if( temp == NULL )
	{
		temp = c;
		head = temp;
	}
	else
	{
		while( temp->next != NULL )
		{
			temp = temp->next;
		}

		temp->next = c;



		while(current != NULL)
		{
			index = current->next;

			while(index != NULL)
			{
				if(current->value < index->value)
				{
					tempValue = current->value;
					swapCardType->c = current->c;
					current->value = index->value;
					index->value = tempValue;
					index->c = swapCardType->c;

				}
				index = index->next;
			}
			current = current->next;
		}
	}
	
	return head;

	
	

}



/*
   Function: getLength
   -------------------
   Gets the length of the Card linked list
   	Card *head: The current head of the linked list.
   Returns: An int representing the length of the linked list the head is pointing at.
*/
int getLength( Card *head )
{
	if ( head == NULL )
		return 0;
	else
		return 1 + getLength(head->next);
}



/*
   Function: printCard
   -------------------
   Prints a single card with abbreviations of the CardType enum: A for ATTACK, D for DEFEND, and R for RUN along with each cards value.
   Example: A5 for ATTACK Value 5
   	Card *head: The current head of the linked list.
   Returns: void, but prints out card value to console/screen.
*/
void printCard( Card *head )
{
	Card *temp = head;

	if( temp->c == 0 )
	{
		printf("A%d ", temp->value );
	}
	else if( temp->c == 1 )
	{
		printf("D%d ", temp->value);
	}
	else if( temp->c == 2 )
	{
		printf("R%d ", temp->value);
	}
}



/*
   Function: printCards
   --------------------
   Prints all cards in the deck by calling printCard for each card. This function will traverse the linked list.
   	Card *head: The current head of the linked list.
   Returns: void, but enables all cards in the players deck to be printed.
*/
void printCards( Card *head )
{
	Card *temp = head;

	while( temp != NULL )
	{
		printCard(temp);
		temp = temp->next;
	}

	printf("\n");
}



/*
   Function: buildCards
   --------------------
   Uses a linked list to build a deck of cards. Will utilize createCard() and addCard() functions to create/add cards to the new deck. 
   	int n: Determines how many cards will be in the deck
   Returns: the head of the new linked list
*/
Card* buildCards( int n )
{
	int i = 0;

	Card *head = NULL;
	Card *newCard = NULL; 

	while( i < n )
	{
		newCard = createCard();
		head = addCard(head, newCard);
		i++;
	}


	return head;
}



/*
   Function: destroyCards
   ----------------------
   This function will destroy the linked list once the game is over.
   	Card *head: The current head of the linked list
   Returns: NULL
*/
Card* destroyCards( Card *head)
{
	Card* current = head;
	Card* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	head = NULL;

	
}

