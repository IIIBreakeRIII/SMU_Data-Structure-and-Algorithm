//
//  FoodCalorie(No.10).c
//  Week_3
//
//  Created by 현소류 on 2022/09/22.
//

#include <stdio.h>
#include <math.h>

struct food {
    char name[100];
    int calorie;
};

int CalcTotalCalorie(struct food array[], int size);

int main(void) {
    struct food FoodArray[3] = {
        { "hamburger", 900 },
        { "bulgogi", 500 },
        { "sushi", 700 }
    };
    int total = CalcTotalCalorie(FoodArray, 3);
    
    printf("Total Calorie That I Eat : %dcalorie\n", total);
    
    return 0;
}

int CalcTotalCalorie(struct food array[], int size) {
    int i, total = 0;
    
    for(i = 0; i < size; i++) {
        total += array[i].calorie;
    }
    return total;
}
