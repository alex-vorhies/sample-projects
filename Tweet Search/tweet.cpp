//Name: Alex Vorhies
//Date: 4/11/16
//Description: Searches a file of tweets and adds them to a list for use later (requires tweet.h, main.cpp, tweetlist.h, and tweetlist.cpp to work)
//Proposed points: I feel I should receive 20 points

#include "tweet.h" //include the Tweet header file
#include <fstream> //required for the program to use files
#include <iostream> //required for the program to output to the console and accept user input

using namespace std;

Tweet::Tweet(ifstream &infile)
{
	infile.get(); //eat [
	infile >> latitude;
	infile.get(); //eat ,
	infile >> longitude;
	infile.get(); //eat ]
	short temp; //deletes the random 6 in between the date and location
	infile >> temp;
	infile >> year;
	infile.get(); //eat -
	infile >> month;
	infile.get(); //eat -
	infile >> day;
	infile >> hour;
	infile.get(); //eat :
	infile >> minute;
	infile.get(); //eat :
	infile >> second;
	getline(infile,text); //gets the rest of the line and stores it into the text variable
}

void Tweet::print() //prints the tweet
{
	cout << "Text: " << text << endl;
	cout << "Location: " << latitude << ", " << longitude << endl;
	cout << "Date: " << month << "/" << day << "/" << year << endl;
	cout << "Time: " << hour << ":" << minute << ":" << second << endl;
}

bool Tweet::textContains(string s)
{
	if (text.find(s) == string::npos) //if the word or phrase inserted is not in the Tweet
		return false;
	else
		return true;
}