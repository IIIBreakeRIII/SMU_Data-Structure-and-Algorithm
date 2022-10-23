//
//  Ch2-10.c
//  MidTermExamPractice
//
//  Created by 현소류 on 2022/10/23.
//

#include <stdio.h>

void recursive(int n) {
    if(n != 1) {
        recursive(n - 1);
    }
    printf("%d \n", n);
}

int main() {
    recursive(5);
}
