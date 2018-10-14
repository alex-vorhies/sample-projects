#ifndef QUEUEAGENT_H
#define QUEUEAGENT_H

#include "Maze.h" //required for the program to know about mazes
#include <queue> //required for the program to know about queues

using namespace std;

class QueueAgent
{
	private:
		struct coordinate //stores two integers: one for a row number and one for a column number
		{
			int row;
			int col;
		};
		queue<coordinate> toExplore; //creates a queue of coordinates
	public:
		QueueAgent(int,int); //constructor method
		void solve(Maze &m); //solves the maze provided as a parameter
};

#endif // QUEUEAGENT_H