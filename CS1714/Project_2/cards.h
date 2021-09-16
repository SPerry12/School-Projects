/*

   cards.h
   Project 2
   Shane Perry

   This program is a card-based role-playing game between two (computer) players. Each player gets cards that will either be in ATTACK, DEFEND, or RUN position.
   The player with the higher card value will win the engagement. The primary purpose of this program is to familiarize the developer with the use of linked lists.

   This file contains the CardType enum and Card struct (linked list node) that will be used throughout the program. File also contains prototypes for the program.

*/

#ifndef CARDS_H
#define CARDS_H

typedef enum CardType{ ATTACK, DEFEND, RUN }CardType;

typedef struct Card
{
	CardType c;
	int value;
	struct Card* next;
}Card;



/*
   Function: createCard
   --------------------
   Dynamically allocates a new Card struct object. 
   Returns: A poiner to the newly created struct object.
*/  
Card* createCard();



/*
   Function: removeCard
   --------------------
   Removes and deallocates the first node in the linked list that head is pointing at. It returns the new head of the linked list.
   	Card *head: The current head of the card linked list.
   Returns: New head of linked list.
*/
Card* removeCard( Card *head );



/*
   Function: addCard
   -----------------
   Adds a new Card struct object to the linked list. This function adds the new node in descending order of its value regardless of the action.
   	Card *head: The current head of the linked list.
	Card *c: the new Card struct object
   Returns: The new card struct linked list with the new Card struct objected added to it.
*/
Card* addCard( Card *head, Card *c );



/*
   Function: getLength
   -------------------
   Gets the length of the Card linked list
   	Card *head: The current head of the linked list.
   Returns: An int representing the length of the linked list the head is pointing at.
*/
int getLength( Card *head );



/*
   Function: printCard
   -------------------
   Prints a single card with abbreviations of the CardType enum: A for ATTACK, D for DEFEND, and R for RUN along with each cards value.
   Example: A5 for ATTACK Value 5
   	Card *head: The current head of the linked list.
   Returns: void, but prints out card value to console/screen.
*/
void printCard( Card *head );



/*
   Function: printCards
   --------------------
   Prints all cards in the deck by calling printCard for each card. This function will traverse the linked list.
   	Card *head: The current head of the linked list.
   Returns: void, but enables all cards in the players deck to be printed.
*/
void printCards( Card *head );



/*
   Function: buildCards
   --------------------
   Uses a linked list to build a deck of cards. Will utilize createCard() and addCard() functions to create/add cards to the new deck. 
   	int n: Determines how many cards will be in the deck
   Returns: the head of the new linked list
*/
Card* buildCards( int n );



/*
   Function: destroyCards
   ----------------------
   This function will destroy the linked list once the game is over.
   	Card *head: The current head of the linked list
   Returns: NULL
*/
Card* destroyCards( Card *head);


#endif
