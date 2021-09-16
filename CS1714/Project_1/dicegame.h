/*
        dicegame.h
        Project 1
        Shane Perry

        This program is a probability game between two players. Each player will roll the dice to recieve points that are decided at random based on the type of
        round. Player 1 will recieve points if they roll evens while Player 2 will recieve points if they roll on odds. If Player 1 rolls odds they lose points and then
        Player 2 gets to roll. If Player 2 rolls evens they lose points and Player 1's turn will be next. The number of rounds is determined by the user. The player with
        the most points wins!

        dicegame.h contians all the program prototypes and the enum for the type of round.
*/



#ifndef DICEGAME_H

#define DICEGAME_H


typedef enum
{
	BONUS,
	DOUBLE,
	REGULAR
}ROUNDTYPE;


/*
        Function: getRandomNumber
        --------------------------
        Description: This function generates random numbers for the program. Used for
        dice rolls, probability for ROUNDTYPE, and to randomly select starting player.

                parameter1: minimum number that is needed to set range
                parameter2: maximum number that is needed to set range
        Returns: random number between range min-max (inclusive).
*/
int getRandomNumber( int, int );


/*
        Function: getRoundType
        ----------------------
        Description: This function determines what the type of round will be based on a certain
        probability. (60% for REGULAR, 20% BONUS, 20% DOUBLE)

        Returns: Funciton will return the enum that is randomly selected using getRandomNumber function
        ****ENUM is returned as an int**** (0 = BONUS, 1 = DOUBLE, 2 = REGULAR)
*/
ROUNDTYPE getRoundType();


/*
        Function: getRoundPoints
        ------------------------
        Description: Sets points for round based on the round type from the getRoundType function.
        Gets a random number (1-10) from getRandomNumber function and multiplies it by 10 for REGULAR and
        DOUBLE points.

                parameter1: Determined from the getRoundType function
        Returns: Points for that specific round
*/
int getRoundPoints( ROUNDTYPE );



/*
        Function: printPlayerPoints
        ---------------------------
        Description: Prints player points
                parameter1: Player1's points
                parameter2: player2's points
        Return: void, but will create a print statement
*/
void printPlayerPoints( int, int );


/*
        Function: printRoundInfo
        ------------------------
        Description: prints each round info. Round type is printed using a switch
        due to ROUNDTYPE returning an int.
                parameter1:Round type - whitch will display BONUS/DOUBLE/REGULAR
                parameter2: Shows what player rolls
                parameter3: displays points for the round.
        Returns: void, but will return a print statement

*/
void printRoundInfo( ROUNDTYPE, int, int );






#endif
