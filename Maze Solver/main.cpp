//Name: Alex Vorhies
//Date: 4/27/16
//Description: A maze solving game. Can have a human player or an AI solve the maze
//Proposed points: I feel I should receive 19 points

#include <iostream> //required for the program to output information to the console
#include <fstream> //required for the program to use files
#include "Maze.h" //required for the program to know about mazes
#include "QueueAgent.h" //required for the program to know about the queue agent
#include "StackAgent.h" //required for the program to know about the stack agent

using namespace std;

/*
    Parameter: a maze to use with the one-player game
    Return: none
    User output: the maze at various points in the user's search
    User input: the position in the maze to explore
*/
void humanPlayer(Maze &m)
{
    m.display();
    //create the maze, display the maze and the starting position
    cout << "Starting in " << m.getStartRow() << ", " << m.getStartCol() << endl;
    bool finished = false;
    //the game loop
    while(!finished)
    {
        cout << "Enter the row and column you want to explore: " << endl;
        int r, c;
        cin >> r >> c; //read input
        char result = m.explore(r,c); //explores the given spot in the maze
        cout << "You found a " << result << " in " << r << ", " << c << endl;
        m.display(); //display our current view of the maze
        if(result == '*') //check if the goal has been found
        {
            cout << "You found the finish!" << endl;
            finished = true;
        }
    }
    //we're done, so we can display the whole maze - even unexplored territory
    m.displayNoFog();
}

bool RecursiveAI(int row, int col, Maze &m)
{
    int mazeHeight = m.getHeight(), mazeWidth = m.getWidth(); //get the maze height and width and store them
    bool exitFound = false; //true if it found the exit
    char result = m.explore(row,col); //explore the current row and col obtained from the coordinate
    cout << "The AI found a " << result << " in " << row << ", " << col << endl;
    m.display(); //display the maze
    if (result == 'o' || result == '.') //if the AI found the start or an open space
    {
        if ((row < mazeHeight && row >= 0) && (col < mazeWidth && col >= 0)) //if (row is less than maze height and greater than or equal to 0)
        //and (col is less than maze width and greater than or equal to 0)
        {
            if (!m.haveVisited(row+1,col) && !exitFound) //if the AI hasn't visited this position
                exitFound = RecursiveAI(row+1,col,m); //search the new position  
            if (!m.haveVisited(row-1,col) && !exitFound) //if the AI hasn't visited this position
                exitFound = RecursiveAI(row-1,col,m); //search the new position
            if (!m.haveVisited(row,col+1) && !exitFound) //if the AI hasn't visited this position
                exitFound = RecursiveAI(row,col+1,m); //search the new position
            if (!m.haveVisited(row,col-1) && !exitFound) //if the AI hasn't visited this position
                exitFound = RecursiveAI(row,col-1,m); //search the new position
            return exitFound; //return exitFound once all if statements have been checked
        }
    }
    else if (result == '*') //if the AI found the finish
    {
        cout << "The AI found the finish!" << endl;
        m.displayNoFog(); //show the maze
        return true;
    }
    else if (result == '#') //if the AI hit a wall
        return false;
}

/* Entry point of the program. Simply gets the filename from the user and then
    launches the one-player game. When you write your AIs for this, you should
    set up a menu in here to allow the user to say which AI (or human game) they'd
    like to run.
*/
int main()
{
    string mazeFileName; //stores the file name of the maze the user would like to use
    short solver = 6; //selector for what the user wants to do
    cout << "Enter a maze file name: ";
    cin >> mazeFileName; //reads input
    while (solver != 0)
    {
        cout << "1. Solve the maze yourself" << endl << "2. Queue AI" << endl << "3. Stack AI" << endl << "4. Recursive AI" << endl;
        cout << "5: Change maze file" << endl << "0: Exit" << endl << "What would you like to do? ";
        cin >> solver; //read input for what the user wants to do
        Maze m(mazeFileName); //create the maze from the file name provided
        if (solver == 1)
            humanPlayer(m);
        else if (solver == 2)
        {
            m.display(); //display the maze
            QueueAgent q(m.getStartRow(),m.getStartCol()); //create the AI using the starting row and column
            q.solve(m); //solve the maze
        }
        else if (solver == 3)
        {
            m.display(); //display the maze
            StackAgent s(m.getStartRow(),m.getStartCol()); //create the AI using the starting row and column
            s.solve(m); //solve the maze
        }
        else if (solver == 4)
        {
            m.display(); //display the maze
            int row = m.getStartRow(), col = m.getStartCol(); //gets the starting position
            bool result = RecursiveAI(row,col,m); //starts recursion based on the row and column provided (maze is passed in as well)
        }
        else if (solver == 5)
        {
            cout << "Enter a maze file name: ";
            cin >> mazeFileName; //reads input
        } 
    }
    cout << "Thank you for using this service. Have a great day!" << endl;
    return 0;
}