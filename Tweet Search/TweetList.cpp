//Name: Alex Vorhies
//Date: 4/11/16
//Description: Searches a file of tweets and adds them to a list for use later (requires tweet.h, tweet.cpp, tweetlist.h, and main.cpp to work)

#include "TweetList.h" //include the TweetList header file
#include <iostream> //required for the program to output to the console and accept user input
#include <cstdlib> //required for NULL to be a valid variable

using namespace std;

TweetList::TweetList()
{
	head = NULL; //head points nowhere
}

TweetList::~TweetList()
{
	ListNode * prev = NULL; //the previous listnode points nowhere
	ListNode * curr = head; //the current listnode points at the head
	while(curr != NULL) //while current is not NULL
	{
		prev = curr;
		curr = curr->next;
		delete prev; //deletes the list
	}
}


void TweetList::prepend(Tweet * newVal)
{
	ListNode * newNode;
	newNode = new ListNode; //dynamically allocates memory for a new ListNode

	newNode->val = newVal; //the Tweet equals newVal
	newNode->next = head; //the node pointer points at head
	head = newNode; //head points at the newNode
}

void TweetList::print()
{
	ListNode * curr;
	curr = head;

	while(curr != NULL) //while the current pointer isn't null
	{
		curr->val->print(); //uses the Tweet's print function to print each variable of the list
		cout << endl << endl;
		curr = curr->next;
	}

	cout << endl;
}

bool TweetList::search(string thingToLookFor)
{
	ListNode * curr = head;
	while(curr != NULL) //loops through each tweet to find a word or phrase
	{
		if(curr->val->textContains(thingToLookFor)) //if the Tweet contains the word or phrase requested
		{
			return true; //stops processing tweets if it finds a Tweet with the word or phrase
		}
		curr = curr->next;
	}
	return false;
}

Tweet * TweetList::get(short i) //gives a Tweet at a certain position in the list
{
	ListNode * curr;
	curr = head;
	short listPosition = 0;
	while(curr != NULL)
	{
		if(listPosition == i)
		{
			return curr->val;
		}
		curr = curr->next;
		listPosition++;
	}
}
