//
//  PrintStar(No.5).c
//  Week_3
//
//  Created by 현소류 on 2022/09/20.
//

#include <stdio.h>

void star(int max) {
    if(max <= 0) {
        return;
    }
    printf("*");
    star(max - 1);
}

void line(int current, int max) {
    if(current > max) {
        return;
    }
    
    star(current);
    printf("\n");
    line(current + 1, max);
}

int main() {
    int repeat = 5;
    line(1, repeat);
}
