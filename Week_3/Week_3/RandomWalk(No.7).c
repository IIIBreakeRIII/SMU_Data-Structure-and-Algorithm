//
//  RandomWalk(No.7).c
//  Week_3
//
//  Created by 현소류 on 2022/09/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

int check(int a[][SIZE]);
int CantGo(int num);
void Move(int num);
int i, j, count;

int main(void) {
    int a[SIZE][SIZE] = {{0}, {0}};
    int x, y, num;
    srand((unsigned)time(NULL));
    i = 3; j = 3; count = 0;
    while(1) {
        a[i][j] = 1;
        x = check(a);
        if(count > 100000) {
            printf("Beatle Move Over Hundred Thousand Times.. Plz Make Him Rest.. \n");
            break;
        }
        if(x == 1) {
            printf("Beatle Moves : %dTimes\n", count);
            break;
        }
        num = rand() % 8;
        y = CantGo(num);
        if(y == 0) {
            continue;
        }
        Move(num);
    }
    return 0;
}

int check(int a[][SIZE]) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(a[i][j] == 0) {
                return 0;
            }
        }
        return 0;
    }
    return 1;
}

int CantGo(int num) {
    if(i == 0 && j == 0) {
        if(num == 1 || num == 0 || num == 7 || num == 6 || num == 5) {
            return 0;
        }
    }
    else if(i == 0 && j == 6) {
        if(num == 7 || num == 0 || num == 1 || num == 2 || num == 3) {
            return 0;
        }
    }
    else if(i == 6 && j == 0) {
        if(num == 7 || num == 6 || num == 5 || num == 4 || num == 3) {
            return 0;
        }
    }
    else if(i == 6 && j == 6) {
        if(num == 1 || num == 2 || num == 3 || num == 4 || num == 5) {
            return 0;
        }
    }
    else if(i == 0) {
        if(num == 7 || num == 0 || num == 1) {
            return 0;
        }
    }
    else if(i == 6) {
        if(num == 5 || num == 4 || num == 3) {
            return 0;
        }
    }
    else if(j == 0) {
        if(num == 7 || num == 6 || num == 5) {
            return 0;
        }
    }
    else if(j == 6) {
        if(num == 1 || num == 2 || num == 3) {
            return 0;
        }
    }
    else {
        return 1;
    }
    return 0;
}

void Move(int num) {
    if(num == 0) {
        i--;
        count++;
    }
    else if(num == 1) {
        i--;
        j++;
        count++;
    }
    else if(num == 2) {
        j++;
        count++;
    }
    else if(num == 3) {
        i++;
        j++;
        count++;
    }
    else if(num == 4) {
        i++;
        count++;
    }
    else if(num == 5) {
        i++;
        j--;
        count++;
    }
    else if(num == 6) {
        j--;
        count++;
    }
    else if(num == 7) {
        i--;
        j--;
        count++;
    }
}
