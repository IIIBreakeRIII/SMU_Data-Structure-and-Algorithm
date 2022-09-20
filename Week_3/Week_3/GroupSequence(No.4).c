//
//  GroupSequence(No.4).c
//  Week_3
//
//  Created by 현소류 on 2022/09/20.
//

#include <stdio.h>

int groupSequence(int repeat) {
    if(repeat == 1) {
        return 1;
    }
    else {
        return repeat + groupSequence(repeat - 1);
    }
}

int main(void) {
    int repeat = 4;
    int i, sum = 0;
    
    for(i = 1; i <= repeat; i++) {
        sum = sum + groupSequence(i);
      }
    
    printf("Sum Of Group Sequence Of %d = %d\n", repeat, sum);
}
