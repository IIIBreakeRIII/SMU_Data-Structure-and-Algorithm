//
//  Ch2-9.c
//  MidTermExamPractice
//
//  Created by 현소류 on 2022/10/23.
//

#include <stdio.h>

int recursive(int n) {
    printf("%d \n", n);
    if(n < 1) {
        return -1;
    }
    else {
        return (recursive(n - 3) + 1);
    }
}

int main() {
    printf("%d\n", recursive(10));
}
