//Name: Alex Vorhies
//Date: 3/10/16
//Description: Simulates the card game War (requires Deck.cpp and Deck.h to work properly)

#include "Deck.h" //required for Deck.cpp to work
#include <iostream> //required to print values to the console
#include <ctime> //required for the random function to output something different each time the program runs

using namespace std;

Deck::Deck() //defines variables that make the object whole
{
	cardNumber = 0;
	cardDeck = new Card[NUMCARDS]; //dynamically allocate cardDeck

	//loop through each possible rank
	for(int r = 2; r <= 14; r++)
	{
		Card c = {r, 'C'/* club */}; //each suit gets a card at this rank
		Card d = {r, 'D'}; //diamond
		Card s = {r, 'S'}; //spade
		Card h = {r, 'H'}; //heart

		int arrPos = r-2;  //adjust for array starting at 0 but ranks starting at 2

		cardDeck[arrPos] = c; //put different suits into different ranges in the array
		cardDeck[arrPos+13] = d;
		cardDeck[arrPos+26] = s;
		cardDeck[arrPos+39] = h;
	}
}

const void Deck::printDeck() //prints the deck
{
	for(int i = 0; i < NUMCARDS; i++)
	{
		//print ranks 10-14 as T, J, Q, K, or A
		if(cardDeck[i].rank == 10)
			cout << "T"; //ten
		else if(cardDeck[i].rank == 11)
			cout << "J"; //jack
		else if(cardDeck[i].rank == 12)
			cout << "Q"; //queen
		else if(cardDeck[i].rank == 13)
			cout << "K"; //king
		else if(cardDeck[i].rank == 14)
			cout << "A"; //ace
		else
			cout << cardDeck[i].rank; //outputs the card's rank
		cout << cardDeck[i].suit << " "; //outputs the card's suit
	}
	cout << endl;
}

const void Deck::shuffleDeck()
{
	srand(time(0)); //seeds random generator
	Card temp; //create a temporary home for the card that the loop is on
	for(short f = 0; f < NUMCARDS; f++)
	{
		short position = rand()%52; //generates a random number, then modular divides it by 52
		temp = cardDeck[f]; //assigns temp to the current card the loop is on
		cardDeck[f] = cardDeck[position]; //assigns the current card cardDeck[f] to cardDeck[position]
		cardDeck[position] = temp; //assigns cardDeck[position] to the card stored in temp
	}
}

const void Deck::playerDeal() //deals a card for the player
{
	if(cardDeck[cardNumber].rank == 11)
		cout << "J"; //jack
	else if(cardDeck[cardNumber].rank == 12)
		cout << "Q"; //queen
	else if(cardDeck[cardNumber].rank == 13)
		cout << "K"; //king
	else if(cardDeck[cardNumber].rank == 14)
		cout << "A"; //ace
	else
		cout << cardDeck[cardNumber].rank; //outputs the player's card's rank
	cout << cardDeck[cardNumber].suit << endl; //outputs the player's card's suit
	player = cardDeck[cardNumber]; //sets the player's card to the current card in the deck
	increaseCardNumber();
}

const void Deck::cpuDeal() //deals a card for the cpu
{
	if(cardDeck[cardNumber].rank == 11)
		cout << "J"; //jack
	else if(cardDeck[cardNumber].rank == 12)
		cout << "Q"; //queen
	else if(cardDeck[cardNumber].rank == 13)
		cout << "K"; //king
	else if(cardDeck[cardNumber].rank == 14)
		cout << "A"; //ace
	else
		cout << cardDeck[cardNumber].rank; //outputs the cpu's card's rank
	cout << cardDeck[cardNumber].suit << endl; //outputs the cpu's card's suit
	cpu = cardDeck[cardNumber]; //sets the CPU's card to the current card in the deck
	increaseCardNumber();
}

Deck::~Deck() //destructor method (runs when the program is finished running)
{
	delete[] cardDeck; //de-allocates the memory allocated by the deck array
}
