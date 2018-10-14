//Name: Alex Vorhies
//Date: 2/29/16
//Description: Creates a virtual set of cards, prints it out, shuffles it, then prints it out again

#include <iostream>
#include <ctime> //required for the program to produce different results

using namespace std;

const int NUMCARDS = 52;

//Represents a playing card with 
//rank 2 - 14 and suit C, D, S, or H
struct Card
{
	int rank; //11=Jack, 12=Queen, etc.
	char suit;
};

//function prototypes
void printDeck(Card * deck);
Card * createDeck();
Card * shuffleDeck(Card * deck);

int main()
{
	Card * deck = createDeck();
	printDeck(deck);
	shuffleDeck(deck);
	printDeck(deck);
	delete[] deck;
	return 0;
}

//function createDeck
//dynamically allocates 52 new playing cards
//representing a standard deck of cards
//and returns a pointer to them
Card * createDeck()
{
	Card * deck = new Card[NUMCARDS]; //dynamically allocate deck

	//loop through each possible rank
	for(int r = 2; r <= 14; r++)
	{
		Card c = {r, 'C'}; //each suit gets a card at this rank
		Card d = {r, 'D'};
		Card s = {r, 'S'};
		Card h = {r, 'H'};

		int arrPos = r-2;  //adjust for array starting at 0 but ranks starting at 2

		deck[arrPos] = c; //put different suits into different ranges in the array
		deck[arrPos+13] = d;
		deck[arrPos+26] = s;
		deck[arrPos+39] = h;
	}
	return deck;
}

//function shuffleDeck
//takes a pointer to an array of cards and randomly swaps a card with different one in the array
Card * shuffleDeck(Card * deck)
{
	srand(time(0)); //seeds random generator
	Card temp; //create a temporary home for the card that the loop is on
	for(short f = 0; f < NUMCARDS; f++)
	{
		short position = rand()%52; //generates a random number, then modular divides it by 52
		temp = deck[f]; //assigns temp to the current card the loop is on
		deck[f] = deck[position]; //assigns the current card deck[f] to deck[position]
		deck[position] = temp; //assigns deck[position] to the card stored in temp
	}
	return deck;	
}

//function printDeck
//takes a pointer to an array of cards
//and prints them all with appropriate
//ranks converted to corresponding characters
void printDeck(Card * deck)
{
	for(int i = 0; i < NUMCARDS; i++)
	{
		//print ranks 10-14 as T, J, Q, K, or A
		if(deck[i].rank == 10)
		{
			cout << "T";
		}
		else if(deck[i].rank == 11)
		{
			cout << "J";
		}
		else if(deck[i].rank == 12)
		{
			cout << "Q";
		}
		else if(deck[i].rank == 13)
		{
			cout << "K";
		}
		else if(deck[i].rank == 14)
		{
			cout << "A";
		}
		else
		{
			cout << deck[i].rank; //outputs the card's rank
		}
		cout << deck[i].suit << " "; //outputs the card's suit
	}
	cout << endl;
}
