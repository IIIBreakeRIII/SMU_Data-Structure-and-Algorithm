//
//  GreatestCommonFactor(No.8).c
//  Week_3
//
//  Created by 현소류 on 2022/09/22.
//

#include <stdio.h>

//Euclidean Algorithm

int GCD(int x, int y) {
    if(y == 0) {
        return x;
    }
    else {
        return GCD(y, (x % y));
    }
}

int main(void) {
    printf("Greatest Common Factor is : %d\n", GCD(12, 18));
}
