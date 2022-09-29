//
//  MaxNum(No.2).c
//  Week_3
//
//  Created by 현소류 on 2022/09/20.
//

#include <stdio.h>

int main() {
    int num1, num2, num3;
    int max = 0;
    int count = 0;

    printf("Enter Number : ");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    if(num1 == num2) {
        count += 1;
        if(num2 == num3) {
            count += 1;
            printf("All Same Number, Count = %d\n", count);
        }
        else if(num2 > num3) {
            max = num2;
            count += 1;
            printf("Max Number Is %d, Count = %d\n", max, count);
        }
        else {
            max = num3;
            count += 1;
            printf("Max Number Is %d, Count = %d\n", max, count);
        }
    }
    else if(num2 == num3) {
        count += 1;
        if(num1 == num2) {
            count += 1;
            printf("All Same Number, Count = %d\n", count);
        }
        else if(num1 > num2) {
            count += 1;
            max = num1;
            printf("Max Number Is %d, Count = %d\n", max, count);
        }
        else {
            count += 1;
            max = num2;
            printf("Max Number Is %d, Count = %d\n", max, count);
        }
    }
    else if(num1 == num3) {
        count += 1;
        if(num2 == num1) {
            count += 1;
            printf("All Same Number, Count = %d\n", count);
        }
        else if(num2 > num1) {
            count += 1;
            max = num2;
            printf("Max Number Is %d, Count = %d\n", max, count);
        }
        else {
            count += 1;
            max = num1;
            printf("Max Number Is %d, Count = %d\n", max, count);
        }
    }
    else if(num1 > num2) {
        count += 1;
        max = num1;
        if(max > num3) {
            count += 1;
            printf("Max Number Is %d, Count = %d\n", max, count);
        }
        else {
            count += 1;
            max = num3;
            printf("Max Number Is %d, Count = %d\n", max, count);
        }
    }
    else if(num2 > num1) {
        count += 1;
        max = num2;
        if(max > num3) {
            count += 1;
            printf("Max Number Is %d, Count = %d\n", max, count);
        }
        else {
            count += 1;
            max = num3;
            printf("Max Number Is %d, Count = %d\n", max, count);
        }
    }
}
