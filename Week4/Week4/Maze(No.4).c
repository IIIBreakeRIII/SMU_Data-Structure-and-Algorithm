//
//  Maze(No.4).c
//  Week4
//
//  Created by 현소류 on 2022/09/29.
//

#include <stdio.h>

const int N = 10;
const int PATHWAY_COLOR = 0;
const int WALL_COLOR = 1;
const int BLOCKED_COLOR = 3;
const int PATH_COLOR = 2;
int Maze[N][N] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 0, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 0, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 0, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

int FindExit(int x, int y) {
    if(x < 0 || y < 0 || x >= N || y >= N) {
        return 0;
    }
    else if(Maze[x][y] != PATHWAY_COLOR) {
        return 0;
    }
    else if(x == N - 1 && y == N - 1) {
        Maze[x][y] = PATH_COLOR;
        return 1;
    }
    else {
        Maze[x][y] = PATH_COLOR;
        if(FindExit(x - 1, y) || FindExit(x, y + 1) || FindExit(x + 1, y) || FindExit(x, y - 1)) {
            return 1;
        } else if(FindExit(x - 1, y) == 1 || FindExit(x, y + 1) == 1 || FindExit(x + 1, y) == 1 || FindExit(x, y - 1) == 1) {
            return 1;
        } else {
            Maze[x][y] = BLOCKED_COLOR;
            return 1;
        }
    }
}

int main() {
    int i, j;
    printf("Find Exit : %d\n", FindExit(1, 0));
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ", Maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}
