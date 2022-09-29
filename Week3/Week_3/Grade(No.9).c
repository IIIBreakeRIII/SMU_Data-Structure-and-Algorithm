//
//  Grade(No.9).c
//  Week_3
//
//  Created by 현소류 on 2022/09/22.
//

#include <stdio.h>

int main() {
    double grade, convert;
    for(int i = 0; i <= 9; i++) {
        printf("Enter Your Grade : ");
        scanf("%lf", &grade);
        convert = 100 / 4.3 * grade;
        printf("The Converted Score is : %lf\n", convert);
    }
}
