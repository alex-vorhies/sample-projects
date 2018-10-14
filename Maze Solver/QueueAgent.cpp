#include "Maze.h"
#include "QueueAgent.h"
#include <queue>

using namespace std;

QueueAgent::QueueAgent(int startRow, int startCol) //constructor method
{
    coordinate start = {startRow,startCol}; //creates the start coordinate from the integers provided
    toExplore.push(start); //push the start coordinate to the end of the queue
}

void QueueAgent::solve(Maze &m) //passes the maze in by reference to avoid copying it
{
	int mazeHeight = m.getHeight(); //get the maze height and store it
	int mazeWidth = m.getWidth(); //get the maze width and store it
	bool finished = false;
	while (!finished) //while the AI hasn't solved the maze
	{
		coordinate exploring = toExplore.front(); //store the front value of the queue in a new coordinate variable
		toExplore.pop(); //remove the front element from the queue
        int row = exploring.row, col = exploring.col; //initialize row to be exploring's row and col to be exploring's col
		char result = m.explore(row,col); //explore the current row and col obtained from the coordinate
		cout << "The AI found a " << result << " in " << row << ", " << col << endl;
        m.display(); //display the maze
        if (result == '*') //if the AI found the finish
        {
            cout << "The AI found the finish!" << endl;
            finished = true; //stop the loop
        }
        else if (result == 'o' || result == '.') //if the AI found the start or an open space
        {
            int rowHigh = row+1, rowLow = row-1, colHigh = col+1, colLow = col-1;
            //initialize rowHigh, rowLow, colHigh, and colLow to be plus or minus 1
            if ((row < mazeHeight && row >= 0) && (col < mazeWidth && col >= 0)) //if (row is less than maze height and greater than or equal to 0)
            //and (col is less than maze width and greater than or equal to 0)
            {
                if (!m.haveVisited(rowHigh,col)) //if the AI hasn't visited this position
                {
                    coordinate addToQueue = {rowHigh,col}; //make a new coordinate for this position
                    toExplore.push(addToQueue); //add this coordinate to the queue
                }
                if (!m.haveVisited(rowLow,col)) //if the AI hasn't visited this position
                {
                    coordinate addToQueue = {rowLow,col}; //make a new coordiante for this position
                    toExplore.push(addToQueue); //add this coordinate to the queue
                }
                if (!m.haveVisited(row,colHigh)) //if the AI hasn't visited this position
                {
                    coordinate addToQueue = {row,colHigh}; //make a new coordinate for this position
                    toExplore.push(addToQueue); //add this coordinate to the queue
                }
                if (!m.haveVisited(row,colLow)) //if the AI hasn't visited this position
                {
                    coordinate addToQueue = {row,colLow}; //make a new coordinate for this position
                    toExplore.push(addToQueue); //add this coordinate to the queue
                }
            }
        }
    }
	m.displayNoFog(); //we're done, so show the maze in its entirety
}