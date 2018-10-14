//Name: Alex Vorhies
//Date: 4/11/16
//Description: Searches a file of tweets and adds them to a list for use later (requires tweet.h, tweet.cpp, tweetlist.h, and tweetlist.cpp to work)
//Proposed points: I feel I should receive 20 points

#include "tweet.h" //Includes Tweet class
#include "TweetList.h" //Includes TweetList Class
#include <iostream> //Required for the program to output to the console and access user inputs
#include <fstream> //Required for the program to use files

using namespace std;

int main()
{
	ifstream infile; //defines an input file
	string filename, searchTerm, newSearch, trash; //defines strings for filename, searchTerm, newSearch, and trash
	short listElements = 0, choice = 1, whileLoops = 0, newListElements = 0, newChoice = 0, year = 0, month = 0, day = 0;
	//initializes shorts for the values above
	TweetList list, newList; //defines two TweetList objects (the TweetList remove function doesn't work)
	cout << "What is the data file you want to search? "; //prompts the user for a filename to search
	getline(cin,filename);
	infile.open(filename.c_str()); //converts the filename to a c_str and opens it
	cout << "Enter a word or phrase to search for: ";
	getline(cin,searchTerm); //prompts the user for a term to search
	while (!infile.eof()) //while not at the end of the file
	{
		Tweet * t = new Tweet(infile); //creates a new Tweet based on the information in the infile
		if (t->textContains(searchTerm)) //if the Tweet has the text the user is looking for
			{
				list.prepend(t); //prepend the Tweet to the primary list
				listElements++; //add 1 to listElements
			}
	}
	while (choice != 0) //while the user does not say to exit
	{
		cout << "Your search returned " << listElements << " results. You can do the following:" << endl;
		cout << "0: Exit" << endl << "1: Print results" << endl << "2: Search within these results" << endl << "3: Search based on date" << endl;
		cout << "What would you like to do? ";
		cin >> choice; //prompts the user to either print the list or refine the results based on another phrase, or based on date 
		getline(cin,trash); //removes the \n character placed after the user's input
		if (choice == 1 && whileLoops == 0)
			list.print(); //if this is the first time looping and NewList has no contents, print the primary list
		else if (choice == 1 && whileLoops > 0)
			newList.print(); //if this is the second time looping and NewList has contents, print NewList
		else if (choice == 2)
		{
			newListElements = 0; //re-initialize newListElements to be 0
			cout << "Enter a word or phrase to search for: ";
			getline(cin,newSearch); //prompts the user for a new word to search for
			for (short f = 0; f < listElements; f++)
			{
				Tweet * temp = list.get(f); //utilizes the list's get function to get each Tweet in the primary list
				if (temp->textContains(searchTerm) && temp->textContains(newSearch)) //if the tweet contains the first and second search terms
				{
					newList.prepend(temp); //prepend the tweet onto the newList
					newListElements++; //increment newListElements by 1
				}
			}
			listElements = newListElements; //set ListElements equal to newListElements
			whileLoops++; //increment whileLoops by 1
		}
		else if (choice == 3)
		{
			cout << "Would you like to search based on year (0), month (1), or day (2)? ";
			cin >> newChoice; //prompts the user for search based on year, month, and day
			if (newChoice == 0)
			{
				cout << "What year would you like to search for? ";
				cin >> year; //prompts the user for a year to search for
				for (short f = 0; f < listElements; f++)
					{
						Tweet * temp = list.get(f);
						if (temp->getYear() == year) //if the Tweet's year equals the user's search
						{
							newList.prepend(temp);
							newListElements++;
						}
					}
			}
			else if (newChoice == 1)
			{
				cout << "What month would you like to search for? Enter as a number: ";
				cin >> month; //prompts the user for a month to search for
				for (short f = 0; f < listElements; f++)
				{
					Tweet * temp = list.get(f);
					if (temp->getMonth() == month) //if the Tweet's month equals the user's search
					{
						newList.prepend(temp);
						newListElements++;
					}
				}
			}
			else
			{
				cout << "What day would you like to search for? ";
				cin >> day; //prompts the user for a day to search for
				for (short f = 0; f < listElements; f++)
				{
					Tweet * temp = list.get(f);
					if (temp->getDay() == day) //if the Tweet's day equals the user's search
					{
						newList.prepend(temp);
						newListElements++;
					}
				}
			}
			listElements = newListElements;
			whileLoops++;
		}
	}
	cout << "Thank you for using this service. Have a good day!" << endl;
	return 0;
}