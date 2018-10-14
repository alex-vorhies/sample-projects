//Name: Alex Vorhies
//Date: 3/10/16
//Description: Simulates the card game War (requires Deck.cpp and Deck.h to work properly)
//Proposed points: I feel I should receive 20 points

#ifndef DECH_H //if Deck_h has not been defined
#define DECH_H //define deck.h header

struct Card //card structure
{
	int rank; //11=Jack, 12=Queen, etc.
	char suit;
};

class Deck
{
	private:
		Card * cardDeck; //creates a card pointer called cardDeck
		static const short NUMCARDS = 52; //a constant static number called NUMCARDS (static is the same for each object you create)
	 	short cardNumber;
	public:
		Card player, cpu; //defines cards for the player and cpu (have to be public or the program breaks)
		Deck(); //constructor prototype
		const void printDeck(); //prints the deck
		const void shuffleDeck(); //shuffles the deck
		const void playerDeal(); //deals a card for the player
		const void cpuDeal(); //deals a card for the cpu
		const void increaseCardNumber() {cardNumber++;}; //increments cardnumber by 1
		~Deck(); //destructor prototype
};

#endif // DECH_H