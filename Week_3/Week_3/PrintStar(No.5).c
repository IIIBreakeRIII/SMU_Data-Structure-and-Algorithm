//
//  PrintStar(No.5).c
//  Week_3
//
//  Created by 현소류 on 2022/09/20.
//

#include <stdio.h>

void star(int repeat) {
    if(repeat <= 0) {
        return;
    }
    printf("*");
    star(repeat - 1);
}

void line(int repeat, int n) {
    if(n > repeat) {
        return;
    }
    star(n);
    printf("\n");
    line(n + 1, repeat);
}

int main(){
    int repeat = 5;
    line(1, repeat);
    return 0;
}
