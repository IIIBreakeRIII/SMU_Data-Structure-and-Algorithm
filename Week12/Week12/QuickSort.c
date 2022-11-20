//
//  QuickSorting.c
//  Week12
//
//  Created by 현소류 on 2022/11/21.
//

#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b) { int t; t = a; a = b; b = t; }

int n;

void PrintSit(int list[], int high, int low) {
    for(int i = 0; i < n; i++) {
        printf("%d \t", list[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++) {
        if(i == high) {
            printf("High \t");
        }
        else if(i == low) {
            printf("Low \t");
        }
        else {
            printf("\t");
        }
    }
    printf("\n");
}

int partition(int list[], int left, int right) {
    int pivot;
    int low, high;
    low = left;
    high = right + 1;
    pivot = list[left];
    do {
        do {
            low++;
        } while (low <= right && list[low] < pivot);
        do {
            high--;
        } while (high >= left && list[high] > pivot);
        if(low < high) {
            PrintSit(list, high, low);
        }
    }
}
