//Name: Alex Vorhies
//Date: 2/10/16
//Description: Analyzes demcaucusresults.txt for Sanders' and Clinton's best precincts
//Proposed points: I feel that because the program is able to read in the data and process it at the right times, I should receive 20 points

#include <fstream> //required in order for the program to use files

using namespace std; //declares that the program is accessing entities in the namespace std

int main() //the main function
{
	string county, precinct, candidate, dummy, SandersBestPrecinct, ClintonBestPrecinct, SandersBestCounty, ClintonBestCounty; 
	//defines strings to be read in by the file and/or calculated ^
	short countyDel, countyDelAv; //defines shorts to be read in by the file
	float stateDel, ClintonStateDel = 0.0, SandersStateDel = 0.0, ClintonWin, SandersWin, ClintonBestWin = 0.0, SandersBestWin = 0.0;
	//defines floats (variables that can hold decimals) to be read in by the file and/or calculated ^
	ifstream infile; //defines the variable that is responsible for reading in data from a file
	ofstream outfile; //defines the variable to output information to a file
	infile.open("demcaucusresults.txt"); //opens demcaucusresults.txt for reading
	outfile.open("bestprecincts.txt"); //creates bestprecincts.txt to output information
	for (short i = 0; i < 6; ++i) //for loop that runs 6 times
		getline(infile,dummy); //reads the first 6 lines of infile which are not data and puts them in the dummy variable (trashes them)
	while (!infile.eof()) //while you're not at the end of the file
	{
		getline(infile,county); //get the county name
		getline(infile,precinct); //get the precinct
		getline(infile,candidate); //get the candidate
		infile >> countyDel; //gets the county delegates won
		infile >> countyDelAv; //gets the county delegates to elect
		if (candidate == "Clinton") 
			infile >> ClintonStateDel; //if Clinton was read in last, gets state delegate equivalents and stores them in ClintonStateDel
		else if (candidate == "Sanders")
			infile >> SandersStateDel; //if Sanders was read in last, gets state delegate equivalents and stores them in SandersStateDel
		else
			infile >> stateDel; //if neither candidate was read in last, gets state delegate eqivalents and stores them in stateDel
		if (ClintonStateDel != 0.0 && SandersStateDel != 0.0) //if ClintonStateDel and SandersStateDel do not equal 0.0, run this condition
		{
			if (ClintonStateDel > SandersStateDel) //if ClintonStateDel is greater than SandersStateDel
			{
				ClintonWin = ClintonStateDel - SandersStateDel; //Clinton's advantage over Sanders
				if (ClintonWin > ClintonBestWin) //if this advantage is larger than the best win
				{
					ClintonBestWin = ClintonWin; //sets best win to current advantage
					ClintonBestPrecinct = precinct; //sets best precinct to current precinct
					ClintonBestCounty = county; //sets best county to current county
				}	
			}
			else //if SandersStateDel is greater than ClintonStateDel
			{
				SandersWin = SandersStateDel - ClintonStateDel; //Sanders' advantage over Clinton
				if (SandersWin > SandersBestWin) //if this advantage is larger than the best win
				{
					SandersBestWin = SandersWin; //sets best win to current advantage
					SandersBestPrecinct = precinct; //sets best precinct to current precinct
					SandersBestCounty = county; //sets best county to current county
				}
			}
			ClintonStateDel = 0.0; //after these conditions run, set StateDel for both candidates to 0.0
			SandersStateDel = 0.0;
		}
		getline(infile,dummy); //reads in the newline character after State Delegate and stores it in the dummy variable (trashes it)
	}
	outfile << "Sanders Biggest Win: " << SandersBestWin << " state delegates from " << SandersBestPrecinct << " in " << SandersBestCounty << endl;
	outfile << "Clinton Biggest Win: " << ClintonBestWin << " state delegates from " << ClintonBestPrecinct << " in " << ClintonBestCounty << endl;
	//writes Sanders' and Clinton's best wins, precincts, and counties to bestprecincts.txt
	infile.close(); //closes the infile
	outfile.close(); //closes the outfile
	return 0;
}