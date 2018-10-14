//Name: Alex Vorhies
//Date: 2/17/16
//Description: Analyzes temperature records stored in a file and outputs the high and low for each day

#include <fstream> //required for files to work

using namespace std; //the program uses the namespace standard

double min(double input[], int size); //defines a prototype for a function called min
double max(double input[], int size); //defines a prototype for a function called max

int main()
{
     ifstream infile; //defines infile for reading data into the program
     ofstream outfile; //defines outfile for writing data to a file
     double minimum, maximum; //defines doubles called minimum and maximum
     int size, i = 0; //defines size and i integers
     double input[24]; //defines an array called input that stores doubles
     infile.open("in.txt"); //opens in.txt for reading
     outfile.open("out.txt"); //creates out.txt for writing
     while (!infile.eof()) //while not at the end of the file
     {
          for (short o = 0; o < 24; o++) //a loop that runs 24 times, getting each value
               infile >> input[o]; //inserts the current value into input[o]
          size = sizeof(input)/sizeof(double); //computes the number of values in the array
          minimum = min(input,size); //computes the minimum of the array
          maximum = max(input,size); //computes the maximum of the array
          i++; //increments i by 1
          outfile << "day " << i << ": " << maximum << ", " << minimum << endl; //writes day i: maximum, minimum to the outfile
     }
     return 0;
}

double min(double input[], int size) //computes the minimum of the input array (takes size and the input array as arguments)
{
	double minimumreturn = 300000.0; //initializes minimum return to an impossibly low value
	for (int t = 0; t < size; t++) //a loop that processes each value in the array
	{
		if (input[t] < minimumreturn) //if the current value in the array is less than minimumreturn
			minimumreturn = input[t]; //minimumreturn = the current value in the array
	}
	return minimumreturn; //once the loop is done, return minimumreturn
}

double max(double input[], int size) //computes the maximum of the input array (takes size and the input array as arguments)
{
	double maximumreturn = -300000.0; //initializes maximumreturn to an impossibly high value
	for (int t = 0; t < size; t++) //a loop that processes each value in the array
	{
		if (input[t] > maximumreturn) //if the current value in the array is greater than maximumreturn
			maximumreturn = input[t]; //maximum return = the current value in the array
	}
	return maximumreturn; //once the loop is done, return maximumreturn
}
