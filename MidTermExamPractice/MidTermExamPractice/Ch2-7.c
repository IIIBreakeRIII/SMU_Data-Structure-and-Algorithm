//
//  Ch2-7.c
//  MidTermExamPractice
//
//  Created by 현소류 on 2022/10/23.
//

#include <stdio.h>

int sum(int n) {
    printf("%d\n", n);
    if(n < 1) {
        return 1;
    }
    else {
        return (n + sum(n - 1));
    }
}

int main() {
    printf("%d \n", sum(5));
}
