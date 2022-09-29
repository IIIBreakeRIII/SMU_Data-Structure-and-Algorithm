//
//  RecursiveFunction(No.3).c
//  Week_3
//
//  Created by 현소류 on 2022/09/20.
//

#include <stdio.h>

void recursive(int repeat) {
    if(repeat == 101) {
        printf("\n");
        return;
    }
    if(repeat % 10 == 1){
        printf("\n");
    }
    printf("%d ", repeat);
    recursive(repeat + 1);
}

int main(void) {
    recursive(1);
}
