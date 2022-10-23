//
//  Ch2-15.c
//  MidTermExamPractice
//
//  Created by 현소류 on 2022/10/23.
//

#include <stdio.h>

int fib(int n) {

    printf("fib(%d) Is Called \n", n);
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    return (fib(n - 1) + fib(n - 2));
}

int main() {
    fib(6);
}
