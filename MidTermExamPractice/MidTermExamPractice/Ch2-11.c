//
//  Ch2-11.c
//  MidTermExamPractice
//
//  Created by 현소류 on 2022/10/23.
//

#include <stdio.h>

void asterisk(int i) {
    if(i > 1) {
        asterisk(i / 2);
        asterisk(i / 2);
    }
    printf("* \n");
}

int main() {
    asterisk(5);
}
