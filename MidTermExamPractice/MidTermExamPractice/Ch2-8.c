//
//  Ch2-8.c
//  MidTermExamPractice
//
//  Created by 현소류 on 2022/10/23.
//

#include <stdio.h>

int recursive(int n) {
    printf("%d \n", n);
    if(n < 1) {
        return 2;
    }
    else {
        return(2 * recursive(n - 1) + 1);
    }
}

int main() {
    printf("%d \n", recursive(5));
}
