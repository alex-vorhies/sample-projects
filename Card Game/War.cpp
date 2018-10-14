//Name: Alex Vorhies
//Date: 3/10/16
//Description: Simulates the card game War (requires Deck.cpp and Deck.h to work properly)
//Proposed points: I feel I should receive 20 points

#include "Deck.h" //header file required for the game to work properly
#include <iostream> //required in order for the program to output information to the console
#include <ctime> //required for the random function to output something different each time

using namespace std;

//function prototypes
void War();
void Judge(Card player, Card cpu);

Deck Game; //define the deck object for the program

int main()
{
	bool keepPlaying = true;
	char response; //stores a single character for a response
	Game.printDeck(); //prints the deck
	Game.shuffleDeck(); //shuffles the deck
	while (keepPlaying) //while keepPlaying is true
	{
		cout << "This is your card: "; 
		Game.playerDeal(); //deal a card to the player
		cout << "Here is my card: ";
		Game.cpuDeal(); //deal a card to the cpu
		Judge(Game.player,Game.cpu);
		cout << "Would you like to play again? Enter y for yes or n for no: ";
		cin >> response; //gets the player's response for if they would like to play again
		if (response == 'y' || response == 'Y') //if the player says yes
			keepPlaying = true; //keepPlaying stays true
		else
			keepPlaying = false; //keepPlaying is false
	}
	cout << "Thanks for playing!" << endl;
	return 0;
}

void Judge(Card player, Card cpu) //makes the comparison between ranks of cards
{
	if (player.rank > cpu.rank) //if the player's rank is greater than the cpu's rank
		cout << "You won this round!" << endl;
	else if (player.rank < cpu.rank) //if the cpu's rank is greater than the player's rank
		cout << "I won this round!" << endl;
	else if (player.rank == cpu.rank) //if the ranks are the same
		War(); //runs when ranks are equal
}

void War()
{
	cout << "War!" << endl;
	cout << "Here is your new card: ";
	Game.playerDeal(); //deals a new card for the player
	cout << "Here is my new card: ";
	Game.cpuDeal(); //deals a new card for the cpu
	Judge(Game.player,Game.cpu);
}