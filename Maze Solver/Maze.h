/* File: Maze.h
    This file contains the specification for a Maze class.
    The Maze is stored as a two-dimensional character array
    in which each character has the following meaning:

        # - wall
        o - starting position
        * - goal position
        . - open space

    Initially, all positions in the maze are unexplored and
    will be displayed as a question mark (?) - i.e. the fog
    of war. The position of start is available with public
    member functions. Non-start positions can only be explored
    after a vertically or horizontally adjacent position has
    already been explored.

    This maze is designed to be solved interactively by a user
    or automatically by an automated method (AI).
*/

#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <iostream>

using namespace std;

class Maze
{
    private:
        char **mazeArray; //our maze representation
        bool **visited; //whether or not the corresponding position in mazeArray has been explored
        int startc;     //The column of the starting positions
        int startr;     //The row of the starting positions
        int finishc;    //The column of the goal
        int finishr;    //The row of the goal
        int width;      //The number of columns in the map
        int height;     //The number of rows in the map
        void display(bool);

    public:
        Maze(string);   //constructor
        ~Maze();        //destructor
        void display(); //display the maze - unexplored represented by ?
        void displayNoFog(); //display the full maze without ? - use for debugging
        char explore(int,int); //for exploring a particular positions

        //accessor member functions
        int getWidth(){return width;}
        int getHeight(){return height;}
        int getStartRow(){return startr;}
        int getStartCol(){return startc;}
        bool haveVisited(int,int);
};

#endif // MAZE_H
