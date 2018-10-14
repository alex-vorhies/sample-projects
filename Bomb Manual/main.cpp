//verification code: 241

#include "BombManual.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	BombManual b;
	short modules, battery, buttonNumber = 0, simonNumber = 0;
	string subject, color, text, addToVector, trash;
	char serial, indicator;
	cout << "How many modules are on the bomb? ";
	cin >> modules; //gets the number of modules on the bomb
	cin.get();
	for (short i = 0; i < modules; i++)
	{
		cout << "Subjects: wire, button, simon, memory, first, sequence, password, morse\n";
		cout << "What subject do you need to refer to? ";
		getline(cin,subject);
		transform(subject.begin(),subject.end(),subject.begin(),::tolower);
		if (subject == "wire")
			b.wire(); //run the wire function in the Bomb Manual class
		else if (subject == "button")
		{
			cout << "What color is the button? "; //need the color of the button for this function
			cin >> color;
			transform(color.begin(),color.end(),color.begin(),::tolower);
			b.changeColor(color);
			cout << "What does the button say? "; //need the text on the button for this function
			cin >> text;
			transform(text.begin(),text.end(),text.begin(),::tolower);
			b.changeText(text);
			if (buttonNumber == 0) //if this is the first button on this bomb
			{
				cout << "How many batteries are on the bomb? "; //battery number will be needed on future buttons
				cin >> battery;
				b.changeBattery(battery);
				cout << "Are there lit indicators on the bomb? (y/n) "; //lit indicators will be important later
				cin >> indicator;
				tolower(indicator);
				if (indicator == 'n')
					b.addIndicators("none");
				else
				{
					while (addToVector != "done")
					{
						cout << "What is one of the indicators? When finished, type \"done.\" ";
						cin >> addToVector;
						transform(addToVector.begin(),addToVector.end(),addToVector.begin(),::tolower);
						if (addToVector != "done")
							b.addIndicators(addToVector);
					}
				}
			}
			b.button(); //run the button function
			buttonNumber++; //increment buttonNumber
		}
		else if (subject == "simon")
		{
			if (simonNumber == 0) //if this is the first simon says
			{
				cout << "Does the serial number contain a vowel? (y/n) "; //this will be important on future simon says
				cin >> serial;
				cin.get();
				tolower(serial);
				if (serial == 'y')
					b.changeSerial(true);
				else
					b.changeSerial(false);
			}
			b.simon(); //run the simon function
			simonNumber++;
		}
		else if (subject == "memory")
			b.memory();
		else if (subject == "first")
			b.first();
		else if (subject == "sequence")
			b.sequence();
		else if (subject == "password")
			b.password();
		else if (subject == "morse")
			b.morseCode();
		else //not all subjects are coded here as they are too complicated right now
			cout << "That subject is too complicated to display. Go to your manual.\n";
	}
	cout << "Congratulations! You defused the bomb in time!\n";
	return 0;		
}