//Name: Alex Vorhies
//Date: 4/11/16
//Description: Searches a file of tweets and adds them to a list for use later (requires main.cpp, tweet.cpp, tweetlist.h, and tweetlist.cpp to work)
//Proposed points: I feel I should receive 20 points

#ifndef TWEET_H //if the header file hasn't been defined
#define TWEET_H //define the header file

#include <fstream> //required for the header file to use other files

using namespace std;

class Tweet //defines the Tweet class
{
	private:
		double latitude, longitude; //stores latitude and longitude of the Tweet as private variables
		short year, month, day, hour, minute, second; //stores the time information of the Tweet as private variables
		string text; //stores the text of the Tweet as a private variable
	public:
		Tweet(ifstream &infile); //constructor function that runs when a Tweet is created
		void print(); //prints the Tweet
		bool textContains(string s); //checks if the Tweet has a phrase or word in it
		string getText() {return text;}; //returns the Tweet's text
		short getYear() {return year;}; //returns the Tweet's year
		short getMonth() {return month;}; //returns the Tweet's month
		short getDay() {return day;}; //returns the Tweet's day
};

#endif // TWEET_H