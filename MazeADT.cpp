#include "Maze.h"

Maze::Maze(int mazeData[][6]) : MAZE_ROW(6), MAZE_COLUMN(6){
        for(int i = 0; i < MAZE_ROW; ++i){
            for(int j = 0; j < MAZE_COLUMN; ++j){
                maze[i][j] = mazeData[i][j];
                mark[i][j] = 0;
            }
        }
}

void Maze::MazeSolve(){
    typedef struct{int vert; int horiz;}offsets;
    const offsets move[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1},//n ne e se 
                          {1, 0}, {1, -1}, {0, -1}, {-1, -1}}; //s sw w nw
       
    Position curPos = {1, 1, 2}; // 입구좌표(1, 1) 처음방향E     
    mark[1][1] = 1;
    maze[1][1] = 1; // 시작위치표시 
    bool forwarded;

    while(1){
        if(curPos.g == MAZE_ROW - 2 && curPos.h == MAZE_COLUMN - 2){
            stack.push(curPos);
            std::cout << "FoundPath!" << std::endl << std::endl;
            std::cout << "Path is: " << std::endl;
            stack.displayStack();
            std::cout << std::endl;
            std::cout << "Mark is: " << std::endl;
            DisplayMark();
            break;
        }else{
            forwarded = false;
            while(curPos.dir < 8){
                int i = curPos.g + move[curPos.dir].vert;
                int j = curPos.h + move[curPos.dir].horiz;
                if(!maze[i][j] && !mark[i][j]){
                    stack.push(curPos);
                    Move(curPos, move[curPos.dir].vert, move[curPos.dir].horiz);
                    forwarded = true;
                    break;
                }
                ++curPos.dir;
            }
            if(!forwarded){
                if(stack.isEmpty()){
                    std::cout << "No path exists!" << std::endl;
                    DisplayMark();
                    break;
                }
                curPos = stack.pop();
            }
        }
    }
}

void Maze::Move(Position & curPos, int i, int j){
    curPos.g += i;
    curPos.h += j;
    curPos.dir = 0;
    mark[curPos.g][curPos.h] = 1;
}

void Maze::DisplayMark(){
    for(int i = 0; i < MAZE_ROW; i++){
        for(int j = 0; j < MAZE_COLUMN; j++){
            std::cout << mark[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}