#include "Maze.h"

int main(void){
    int mazeData[6][6]= {1,1,1,1,1,1, 1,0,1,1,1,1, 1,0,0,0,0,1, 1,1,0,1,1,1, 1,0,1,0,0,1, 1,1,1,1,1,1};
    Maze maze(mazeData);
    maze.MazeSolve();
    return 0;
}


 