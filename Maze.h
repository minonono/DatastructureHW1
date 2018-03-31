#ifndef __MAZE_H__
#define __MAZE_H__
#include "Stack.h"
#include "Position.h"
#include <iostream>

class Maze{
private:
    const int MAZE_ROW;
    const int MAZE_COLUMN;
    int maze[6][6];
    int mark[6][6];
    Position curPos;
    Stack stack;
public:
    Maze(int mazeData[][6]);
    void MazeSolve();
    void Move(Position & curPos, int i, int j);
    void DisplayMark();
};

#endif