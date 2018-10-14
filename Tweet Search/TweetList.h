//Name: Alex Vorhies
//Date: 4/11/16
//Description: Searches a file of tweets and adds them to a list for use later (requires tweet.h, tweet.cpp, main.cpp, and tweetlist.cpp to work)
//Proposed points: I feel I should receive 20 points

#ifndef TWEETLIST_H //if the header file has not been defined
#define TWEETLIST_H //define the header file

#include "tweet.h" //required for the header file to know about Tweets

class TweetList
{
private:
	struct ListNode //a complex variable that stores Tweet pointers and pointers to other list nodes
	{
		Tweet * val;
		ListNode * next;
	};
	ListNode * head; //a node that points to the beginning of the list

public:
	TweetList(); //constructor function
	~TweetList(); //destructor function
	void prepend(Tweet * newVal); //prepends a Tweet to the list
	void print(); //prints the list
	bool search(string thingToLookFor); //searches the list for a word or phrase
	Tweet * get(short i); //gets a tweet based on the number inserted
};

#endif // TWEETLIST_H