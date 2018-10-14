#ifndef STACKAGENT_H
#define STACKAGENT_H

#include "Maze.h" //required for the program to know about mazes
#include <stack> //required for the program to know about stacks

using namespace std;

class StackAgent
{
	private:
		struct coordinate //stores two integers: one for a row number and one for a column number
		{
			int row;
			int col;
		};
		stack<coordinate> toExplore; //creates a stack of coordinates
	public:
		StackAgent(int,int); //constructor method
		void solve(Maze &m); //solves the maze provided as a parameter
};

#endif // STACKAGENT_H