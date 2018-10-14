#ifndef BOMBMANUAL_H
#define BOMBMANUAL_H

#include <vector> //allows for use of the vector object
#include <string> //allows for operations on string objects
#include <map> //allows for use of maps

using namespace std;

class BombManual
{
	private:
		short battery; //tracks the number of batteries
		string text, color; //tracks the color of and the text on a button
		bool serial; //tracks if the serial number contains a vowel
		map<string,char> morseCodeKey; //adds morse code translation (not ful morse code as most letters aren't used)
		vector<string> indicators; //tracks lit indicators on the bomb
	public:
		BombManual(); //constructor function
		void wire();
		void button();
		void simon(); //simon says
		void memory();
		void first(); //who's on first
		void sequence(); //wire sequences
		void password();
		void morseCode();
		void changeBattery(short b) {battery = b;}; //changes the battery count to the number provided
		void changeText(string t) {text = t;}; //changes the button text to the string provided
		void changeColor(string c) {color = c;}; //changes the button color to the string provided
		void changeSerial(bool s) {serial = s;};
		void addIndicators(string i) {indicators.push_back(i);}; //adds the indicator provided to the vector
};

#endif // BOMBMANUAL_H