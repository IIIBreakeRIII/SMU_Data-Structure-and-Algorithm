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
            SWAP(list[low], list[high]);
        }
    } while (low < high);
    
    SWAP(list[left], list[high]);
    return high;
}

void QuickSort(int list[], int left, int right) {
    if(left < right) {
        int q = partition(list, left, right);
        QuickSort(list, left, q - 1);
        QuickSort(list, q + 1, right);
    }
}

int main(void) {
    int * ar;
    printf("Amount of List : ");
    scanf("%d", &n);
    
    printf("Enter the Contents of List : ");
    ar = (int * )malloc(sizeof(int) * n);
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
 
    QuickSort(ar, 0, n - 1);
 
    free(ar);
    return 0;
    
}
