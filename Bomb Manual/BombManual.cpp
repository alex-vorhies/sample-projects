#include "BombManual.h" //include the BombManual class
#include <algorithm> //allows for the use of different algorithms
#include <iostream> //allows for use of cout and cin
#include <fstream> //allows the program to use files
#include <map>
#include <vector>

using namespace std;

BombManual::BombManual()
{ //. = dot; - = dash
	morseCodeKey["-..."] = 'b'; //the code for the letter is the key to get that letter out
	morseCodeKey["."] = 'e';
	morseCodeKey["..-."] = 'f';
	morseCodeKey["...."] = 'h';
	morseCodeKey[".."] = 'i';
	morseCodeKey[".-.."] = 'l';
	morseCodeKey["--"] = 'm';
	morseCodeKey["---"] = 'o';
	morseCodeKey[".-."] = 'r';
	morseCodeKey["..."] = 's';
	morseCodeKey["-"] = 't';
	morseCodeKey["...-"] = 'v';
	morseCodeKey["-..-"] = 'x';
}

void BombManual::wire()
{
	short numberWire, yellowWire; //tracks the number of wires and yellow wires
	char redWire, blueWire, blackWire, serialOdd, yellow; //tracks (y)es and (n)o values for different colors of wire as well as if the serial number ends in an odd number
	cout << "How many wires are there? ";
	cin >> numberWire; //gets the number of wires
	cin.get(); //trashes the character at the end of an input
	if (numberWire == 3)
	{
		cout << "Are there any red wires? (y/n) ";
		cin >> redWire;
		cin.get();
		tolower(redWire); //makes the input lowercase
		if (redWire == 'n')
			cout << "Cut the second wire\n";
		else
		{
			cout << "Is there more than one blue wire? (y/n) ";
			cin >> blueWire;
			cin.get();
			tolower(blueWire);
			if (blueWire == 'y')
				cout << "Cut the last blue wire\n";
			else
				cout << "Cut the last wire\n";
		}
	}
	else if (numberWire == 4)
	{
		cout << "Is there more than one red wire? (y/n) ";
		cin >> redWire;
		cin.get();
		tolower(redWire);
		if (redWire == 'y')
		{
			cout << "Is the last digit of the serial number odd? (y/n) ";
			cin >> serialOdd;
			cin.get();
			tolower(serialOdd);
			if (serialOdd == 'y')
				cout << "Cut the last red wire\n";
			else
			{
				short blueWireNumber;
				cout << "Is the last wire yellow? (y/n) ";
				cin >> yellow;
				cin.get();
				tolower(yellow);
				if (yellow == 'y')
				{
					cout << "Are there any red wires? (y/n) ";
					cin >> redWire;
					cin.get();
					tolower(redWire);
					if (redWire == 'n')
						cout << "Cut the first wire\n";
					else
					{
						cout << "How many blue wires are there? ";
						cin >> blueWireNumber;
						cin.get();
						if (blueWireNumber == 1)
							cout << "Cut the first wire\n";
						else
						{
							cout << "How many yellow wires are there? ";
							cin >> yellowWire;
							cin.get();
							if (yellowWire > 1)
								cout << "Cut the last wire\n";
							else
								cout << "Cut the second wire\n";
						}
					}
				}
				else
				{
					cout << "How many blue wires are there? ";
					cin >> blueWireNumber;
					cin.get();
					if (blueWireNumber == 1)
						cout << "Cut the first wire\n";
					else
					{
						cout << "How many yellow wires are there? ";
						cin >> yellowWire;
						cin.get();
						if (yellowWire > 1)
							cout << "Cut the last wire\n";
						else
							cout << "Cut the second wire\n";
					}
				}
			}
		}
		else
		{
			short blue, yellowWire;
			cout << "Is the last wire yellow? (y/n) ";
			cin >> yellow;
			cin.get();
			tolower(yellow);
			if (yellow == 'y')
			{
				cout << "Are there any red wires? (y/n) ";
				cin >> redWire;
				cin.get();
				tolower(redWire);
				if (redWire == 'n')
					cout << "Cut the first wire\n";
				else
				{
					cout << "How many blue wires are there? ";
					cin >> blue;
					cin.get();
					if (blue == 1)
						cout << "Cut the first wire\n";
					else
					{
						cout << "How many yellow wires are there? ";
						cin >> yellowWire;
						cin.get();
						if (yellowWire > 1)
							cout << "Cut the last wire\n";
						else
							cout << "Cut the second wire\n";
					}
				}
			}
			else
			{
				cout << "How many blue wires are there? ";
				cin >> blue;
				cin.get();
				if (blue == 1)
					cout << "Cut the first wire\n";
				else
				{
					cout << "How many yellow wires are there? ";
					cin >> yellowWire;
					cin.get();
					if (yellowWire > 1)
						cout << "Cut the last wire\n";
					else
						cout << "Cut the second wire\n";
				}
			}
		}
	}
	else if (numberWire == 5)
	{
		cout << "Is the last wire black? (y/n) ";
		cin >> blackWire;
		cin.get();
		tolower(blackWire);
		if (blackWire == 'y')
		{
			cout << "Is the last digit of the serial number odd? (y/n) ";
			cin >> serialOdd;
			cin.get();
			tolower(serialOdd);
			if (serialOdd == 'y')
				cout << "Cut the fourth wire\n";
			else
			{
				short red, yellowWire, black;
				cout << "How many red wires are there? ";
				cin >> red;
				cin.get();
				if (red > 0)
				{
					cout << "How many yellow wires are there? ";
					cin >> yellowWire;
					cin.get();
					if (yellowWire > 1)
						cout << "Cut the first wire\n";
					else
					{
						cout << "How many black wires are there? ";
						cin >> black;
						cin.get();
						if (black == 0)
							cout << "Cut the second wire\n";
						else
							cout << "Cut the first wire\n";
					}
				}
				else
				{
					cout << "How many black wires are there? ";
					cin >> black;
					cin.get();
					if (black == 0)
						cout << "Cut the second wire\n";
					else
						cout << "Cut the first wire\n";
				}
			}
		}
		else
		{
			short red, yellowWire, black;
			cout << "How many red wires are there? ";
			cin >> red;
			cin.get();
			if (red > 0)
			{
				cout << "How many yellow wires are there? ";
				cin >> yellowWire;
				cin.get();
				if (yellowWire > 1)
					cout << "Cut the first wire\n";
				else
				{
					cout << "How many black wires are there? ";
					cin >> black;
					cin.get();
					if (black == 0)
						cout << "Cut the second wire\n";
					else
						cout << "Cut the first wire\n";
				}
			}
			else
			{
				cout << "How many black wires are there? ";
				cin >> black;
				cin.get();
				if (black == 0)
					cout << "Cut the second wire\n";
				else
					cout << "Cut the first wire\n";
			}
		}
	}
	else
	{
		cout << "How many yellow wires are there? ";
		cin >> yellowWire;
		cin.get();
		if (yellowWire == 0)
		{
			cout << "Is the last digit of the serial number odd? (y/n) ";
			cin >> serialOdd;
			cin.get();
			tolower(serialOdd);
			if (serialOdd == 'y')
				cout << "Cut the third wire\n";
			else
			{
				short whiteWire, red;
				if (yellowWire == 1)
				{
					cout << "How many white wires are there? ";
					cin >> whiteWire;
					cin.get();
					if (whiteWire > 0)
						cout << "Cut the fourth wire\n";
					else
					{
						cout << "How many red wires are there? ";
						cin >> red;
						cin.get();
						if (red == 0)
							cout << "Cut the last wire\n";
						else
							cout << "Cut the fourth wire\n";
					}
				}
				else
				{
					cout << "How many red wires are there? ";
					cin >> red;
					cin.get();
					if (red == 0)
						cout << "Cut the last wire\n";
					else
						cout << "Cut the fourth wire\n";
				}
			}
		}
		else
		{
			short whiteWire, red;
			if (yellowWire == 1)
			{
				cout << "How many white wires are there? ";
				cin >> whiteWire;
				cin.get();
				if (whiteWire > 0)
					cout << "Cut the fourth wire\n";
				else
				{
					cout << "How many red wires are there? ";
					cin >> red;
					cin.get();
					if (red == 0)
						cout << "Cut the last wire\n";
					else
						cout << "Cut the fourth wire\n";
				}
			}
			else
			{
				cout << "How many red wires are there? ";
				cin >> red;
				cin.get();
				if (red == 0)
					cout << "Cut the last wire\n";
				else
					cout << "Cut the fourth wire\n";
			}
		}
	}
}

void BombManual::button()
{
	bool car, frk, stripNeeded; //boolean variables for the car and frk indicators and if a strip read is needed
	vector<string>::iterator i; //creates an iterator for lit indicators on the bomb
	for (i = indicators.begin(); i != indicators.end(); i++)
	{
		if (*i == "car") //if the current indicator is car
			car = true;
		if (*i == "frk") //if the current indicator is frk
			frk = true;
	}
	if (color == "blue" && text == "abort")
	{
		cout << "Hold the button\n";
		stripNeeded = true;
	}
	else if (battery > 1 && text == "detonate")
	{
		cout << "Press and immediately release the button\n";
		stripNeeded = false;
	}
	else if (color == "white" && car)
	{
		cout << "Hold the button\n";
		stripNeeded = true;
	}
	else if (battery > 2 && frk)
	{
		cout << "Press and immediately release the button\n";
		stripNeeded = false;
	}
	else if (color == "yellow")
	{
		cout << "Hold the button\n";
		stripNeeded = true;
	}
	else if (color == "red" && text == "hold")
	{
		cout << "Press and immediately release the button\n";
		stripNeeded = false;
	}
	else
	{
		cout << "Hold the button\n";
		stripNeeded = true;
	}
	if (stripNeeded) //if a strip read is needed
	{
		string strip;
		cout << "What color is the strip next to the button? \n";
		cin >> strip; //get the color
		cin.get();
		transform(strip.begin(),strip.end(),strip.begin(),::tolower); //make the input lowercase
		if (strip == "blue")
			cout << "Release when the countdown timer has a 4 in any position\n"; //this can be solved if it is 4:xx, x:4x, OR x:x4
		else if (strip == "yellow")
			cout << "Release when the countdown timer has a 5 in any position\n"; //this can be solved if it is 5:xx, x:5x, OR x:x5
		else
			cout << "Release when the countdown timer has a 1 in any position\n"; //this can be solved if it is 1:xx, x:1x, OR x:x1
	}
}

void BombManual::simon()
{
	string color, order = "";
	short strikes;
	bool solved = false;
	char response;
	if (serial) //if the serial number has a vowel
	{
		while(!solved)
		{
			cout << "What color is flashing? ";
			getline(cin,color);
			transform(color.begin(),color.end(),color.begin(),::tolower);
			cout << "How many strikes do you have? ";
			cin >> strikes;
			cin.get();
			if (strikes == 0)
			{
				if (color == "red")
					order += "Blue";
				else if (color == "blue")
					order += "Red";
				else if (color == "green")
					order += "Yellow";
				else if (color == "yellow")
					order += "Green";
			}
			else if (strikes == 1)
			{
				if (color == "red")
					order += "Yellow";
				else if (color == "blue")
					order += "Green";
				else if (color == "green")
					order += "Blue";
				else if (color == "yellow")
					order += "Red";
			}
			else if (strikes == 2)
			{
				if (color == "red")
					order += "Green";
				else if (color == "blue")
					order += "Red";
				else if (color == "green")
					order += "Yellow";
				else if (color == "yellow")
					order += "Blue";
			}
			cout << order << endl;
			order += ", ";
			cout << "Is it still flashing? (y/n) ";
			cin >> response;
			cin.get();
			if (response == 'n')
				solved = true;
			else
				solved = false;
		}
	}
	else //if the serial number does not have a vowel
	{
		while(!solved)
		{
			cout << "What color is flashing? ";
			getline(cin,color);
			transform(color.begin(),color.end(),color.begin(),::tolower);
			cout << "How many strikes do you have? ";
			cin >> strikes;
			cin.get();
			if (strikes == 0)
			{
				if (color == "red")
					order += "Blue";
				else if (color == "blue")
					order += "Yellow";
				else if (color == "green")
					order += "Green";
				else if (color == "yellow")
					order += "Red";
			}
			else if (strikes == 1)
			{
				if (color == "red")
					order += "Red";
				else if (color == "blue")
					order += "Blue";
				else if (color == "green")
					order += "Yellow";
				else if (color == "yellow")
					order += "Green";
			}
			else if (strikes == 2)
			{
				if (color == "red")
					order += "Yellow";
				else if (color == "blue")
					order += "Green";
				else if (color == "green")
					order += "Blue";
				else if (color == "yellow")
					order += "Red";
			}
			cout << order << endl;
			order += ", ";
			cout << "Is it still flashing? (y/n) ";
			cin >> response;
			cin.get();
			if (response == 'n')
				solved = true;
			else
				solved = false;
		}
	}
}

void BombManual::memory()
{
	short number, stage1num, stage2num, stage3num, stage4num; //create holding places for the numbers
	string stage1pos, stage2pos; //create holding places for positions of stage 1 and 2 numbers
	for (short i = 0; i < 5; i++)
	{
		cout << "What number is on the display? ";
		cin >> number;
		cin.get();
		if (i == 0)
		{
			if (number == 1 || number == 2)
			{
				cout << "Press the button in the second position\n";
				stage1pos = "second position";
			}
			else if (number == 3)
			{
				cout << "Press the button in the third position\n";
				stage1pos = "third position";
			}
			else
			{
				cout << "Press the button in the fourth position\n";
				stage1pos = "fourth position";
			}
			cout << "What number did you press? ";
			cin >> stage1num;
			cin.get();
		}
		else if (i == 1)
		{
			if (number == 1)
			{
				cout << "Press 4\n";
				stage2num = 4;
				cout << "What position was that button in? ";
				getline(cin,stage2pos);
			}
			else if (number == 2 || number == 4)
			{
				cout << "Press the button in the " << stage1pos << endl;
				stage2pos = stage1pos;
				cout << "What number did you press? ";
				cin >> stage2num;
				cin.get();
			}
			else
			{
				cout << "Press the button in the first position\n";
				stage2pos = "first position";
				cout << "What number did you press? ";
				cin >> stage2num;
				cin.get();
			}
		}
		else if (i == 2)
		{
			if (number == 1)
			{
				cout << "Press " << stage2num << endl;
				stage3num = stage2num;
			}
			else if (number == 2)
			{
				cout << "Press " << stage1num << endl;
				stage3num = stage1num;
			}
			else if (number == 3)
			{
				cout << "Press the button in the third position\n";
				cout << "What button did you press? ";
				cin >> stage3num;
				cin.get();
			}
			else
			{
				cout << "Press 4\n";
				stage3num = 4;
			}
		}
		else if (i == 3)
		{
			if (number == 1)
				cout << "Press the button in the " << stage1pos << endl;
			else if (number == 2)
				cout << "Press the button in the first position\n";
			else
				cout << "Press the button in the " << stage2pos << endl;
			cout << "What button did you press? ";
			cin >> stage4num;
			cin.get();
		}
		else
		{
			if (number == 1)
				cout << "Press " << stage1num;
			else if (number == 2)
				cout << "Press " << stage2num;
			else if (number == 3)
				cout << "Press " << stage4num;
			else
				cout << "Press " << stage3num;
		}
	}
}

void BombManual::first()
{
	map<string,string> whosOnFirst; //makes a map for string to string
	ifstream infile;
	string key, restOfLine, display, word;
	infile.open("WhosOnFirst.txt"); //open the WhosOnFirst file
	while (!infile.eof())
	{
		infile >> key; //the first word in the line is the key
		getline(infile,restOfLine); //the remaining words are the possibilities for buttons to press
		whosOnFirst[key] = restOfLine;
	}
	infile.close();
	for (short i = 0; i < 3; i++) //this can only run three times
	{
		cout << "What word is in the display? If the display is blank, say \"empty\": "; //the display can be blank
		getline(cin,display);
		transform(display.begin(),display.end(),display.begin(),::tolower); //make the input lowercase
		if (display == "y" || display == "nothing" || display == "led" || display == "they are")
			cout << "What does the middle left button say? ";
		else if (display == "first" || display == "okay" || display == "c")
			cout << "What does the top right button say? ";
		else if (display == "ur")
			cout << "What does the top left button say? ";
		else if (display == "empty" || display == "reed" || display == "leed" || display == "they're")
			cout << "What does the bottom left button say? ";
		else if (display == "blank" || display == "read" || display == "red" || display == "you" || display == "your" || display == "you're" || display == "their")
			cout << "What does the middle right button say? ";
		else
			cout << "What does the bottom right button say? ";
		cout << "If the button has two words, use an underscore. "; //spaces in inputs mess the program up
		getline(cin,word);
		transform(word.begin(),word.end(),word.begin(),::tolower); //make the input lowercase
		if (word == "uh_huh") //this is the only instance in which you press the button if it says this
			cout << "Press Uh Huh\n";
		else //otherwise
			cout << whosOnFirst[word] << endl;
	}
}

void BombManual::sequence()
{
	short red = 0, blue = 0, black = 0; //initialize running counters for the number of wires of each color
	string wire; //this is for the wire color
	for (short i = 1; i < 13; i++) //there is a max of 12 wires
	{
		cout << "What color is #" << i << "? \n";
		cin >> wire;
		cin.get();
		transform(wire.begin(),wire.end(),wire.begin(),::tolower);
		if (wire == "red")
		{
			red++;
			if (red == 1)
				cout << "Cut if connected to C\n";
			else if (red == 2 || red == 5 || red == 9)
				cout << "Cut if connected to B\n";
			else if (red == 3)
				cout << "Cut if connected to A\n";
			else if (red == 4 || red == 6)
				cout << "Cut if not connected to B\n"; //i.e. cut if connected to a or c
			else if (red == 7)
				cout << "Cut the wire\n";
			else
				cout << "Cut if not connected to C\n"; //i.e. cut if connected to a or b
		}
		else if (wire == "blue")
		{
			blue++;
			if (blue == 1 || blue == 3 || blue == 5)
				cout << "Cut if connected to B\n";
			else if (blue == 2 || blue == 8)
				cout << "Cut if not connected to B\n"; //i.e. cut if connected to a or c
			else if (blue == 4 || blue == 9)
				cout << "Cut if connected to A\n";
			else if (blue == 6)
				cout << "Cut if not connected to A\n"; //i.e. cut if connected to b or c
			else
				cout << "Cut if connected to C\n";
		}
		else if (wire == "black")
		{
			black++;
			if (black == 1)
				cout << "Cut the wire\n";
			else if (black == 2 || black == 4)
				cout << "Cut if not connected to B\n"; //i.e. cut if connected to a or c
			else if (black == 3 || black == 5)
				cout << "Cut if connected to B\n";
			else if (black == 6)
				cout << "Cut if not connected to A\n"; //i.e. cut if connected to b or c
			else if (black == 7)
				cout << "Cut if not connected to C\n"; //i.e. cut if connected to a or b
			else
				cout << "Cut if connected to C\n";
		}
		else //if there is no wire in that position
			cout << "No wire there? Okay.\n";
	}
}

void BombManual::password()
{
	ifstream infile;
	string wordInput;
	char response, firstLetter;
	bool solved = false;
	vector<string> possiblePassword; //vector of possible passwords
	while (!solved) //while the password is not found
	{
		infile.open("Password.txt");
		cout << "Enter one of the first letters: ";
		cin >> firstLetter; //gets the letter
		cin.get();
		tolower(firstLetter);
		while (!infile.eof())
		{
			getline(infile,wordInput);
			if (wordInput[0] == firstLetter) //scan the word for the first letter
				possiblePassword.push_back(wordInput); //put it in a vector for later reference
		}
		infile.close();
		vector<string>::iterator i; //create an indicator for the possible password vector
		for (i = possiblePassword.begin(); i != possiblePassword.end(); i++)
			cout << *i << '\n'; //print out each possible password
		possiblePassword.clear(); //delete the contents of the vector just in case
		cout << "Is the module solved? (y/n) ";
		cin >> response;
		cin.get();
		tolower(response);
		if (response == 'y')
			solved = true; //exit the loop
	}
}

void BombManual::morseCode()
{
	char letter;
	string word = "", code;
	bool solved = false;
	short i = 1;
	float value;
	while (!solved)
	{
		cout << "What is letter #" << i << "? "; //asks for the morse code of each letter (. = dot, - = dash)
		cin >> code;
		cin.get();
		letter = morseCodeKey[code]; //get the letter that corresponds to the code provided
		word += letter; //add the letter to the word
		if (word == "she") //if there are enough letters to make an accurate guess, fill it out right away
		{
			word = "shell";
			value = 3.505;
		}
		else if (word == "h") //this is the only word that starts with h
		{
			word = "halls";
			value = 3.515;
		}
		else if (word == "sl")
		{
			word = "slick";
			value = 3.522;
		}
		else if (word == "t") //this is the only word that starts with t
		{
			word = "trick";
			value = 3.532;
		}
		else if (word == "box")
		{
			word = "boxes";
			value = 3.535;
		}
		else if (word == "l") //this is the only word that starts with l
		{
			word = "leaks";
			value = 3.542;
		}
		else if (word == "str")
		{
			word = "strobe";
			value = 3.545;
		}
		else if (word == "bi")
		{
			word = "bistro";
			value = 3.552;
		}
		else if (word == "f") //this is the only word that starts with f
		{
			word = "flick";
			value = 3.555;
		}
		else if (word == "bom")
		{
			word = "bombs";
			value = 3.565;
		}
		else if (word == "bre")
		{
			word = "break";
			value = 3.572;
		}
		else if (word == "bri")
		{
			word = "brick";
			value = 3.575;
		}
		else if (word == "ste")
		{
			word = "steak";
			value = 3.582;
		}
		else if (word == "sti")
		{
			word = "sting";
			value = 3.592;
		}
		else if (word == "v") //this is the only word that starts with v
		{
			word = "vector";
			value = 3.595;
		}
		else if (word == "be")
		{
			word = "beats";
			value = 3.6;
		}
		if (word.length() > 4)
			solved = true;
		else
		{
			solved = false;
			i++;
		}
	}
	cout << word << endl << "Respond at " << value << "MHz\n";
}	
