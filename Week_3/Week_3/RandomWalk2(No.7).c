//
//  RandomWalk2(No.7).c
//  Week_3
//
//  Created by 현소류 on 2022/09/22.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 20
#define M 20

bool check_tile(const int tile[][M]);
void move_dir(int dir);
bool check_move(int tile[][M], int dir);
inline static void Move(int tile[][M]);
void print(const int tile[][M]);

int i = N / 2, j = M / 2;

int main(void) {
    int tile[N][M] = {
        0
    };

    int count = 0, direction;
    bool check = false, possible;
    double start, end;
    srand((unsigned)time(NULL));
    tile[i][j] = 1;

    start = (double)clock() / CLOCKS_PER_SEC;

    while (1) {
        direction = rand() % 8;
        possible = check_move(tile, direction);
        if (possible == true){
            move_dir(direction);
            Move(tile);
            count++;
            check = check_tile(tile);
            print(tile);
            printf("\n");
            if (check == true) {
                break;
            }
        }
    }
    
    end = (double)clock() / CLOCKS_PER_SEC;
    printf("Beatles Moves : %d\n", count);
    printf("Time : %fsecs\n", (end - start));
    return 0;
}

bool check_tile(const int tile[][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tile[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool check_move(int tile[][M], int dir) {
    if (j == 0) {
        if (dir == 5 || dir == 6 || dir == 7) {
            return false;
        }
    } else if (j == M - 1) {
        if (dir == 1 || dir == 2 || dir == 3) {
            return false;
        }
    }
    if (i == 0) {
        if (dir == 0 || dir == 1 || dir == 7) {
            return false;
        }
    } else if (i == N - 1) {
        if (dir == 3 || dir == 4 || dir == 5) {
            return false;
        }
    }
    return true;
}

void move_dir(int dir) {
    switch (dir) {
        case 0:
            i--;
            break;
        case 1:
            i--;
            j++;
            break;
        case 2:
            j++;
            break;
        case 3:
            i++;
            j++;
            break;
        case 4:
            i++;
            break;
        case 5:
            i++;
            j--;
            break;
        case 6:
            j--;
            break;
        case 7:
            i--;
            j--;
            break;
    }
}

inline static void Move(int tile[][M]) {
    tile[i][j] = 1;
}

void print(const int tile[][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ",tile[i][j]);
        }
        printf("\n");
    }
}
