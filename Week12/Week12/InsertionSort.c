//
//  InsertionSort.c
//  Week12
//
//  Created by 현소류 on 2022/11/21.
//

#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int arr[], int n) {
    int key;
    int i = 0, j;
    
    for(i = 0; i < n; i++) {
        printf("(");
        for(j = 0; j < i; j++) {
            if(j == i - 1) {
                printf("%d", arr[j]);
            }
            else {
                printf("%d, ", arr[j]);
            }
        }
        printf(")   ");
        if(i != 0) {
            printf("  ");
        }
        printf("(");
        for(j = i; j < n; j++) {
            if(j == n - 1) {
                printf("%d", arr[j]);
            }
            else {
                printf("%d, ", arr[j]);
            }
        }
        printf(")");
        if(i != 0) {
            printf("%10d Add", key);
        }
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
 
        printf("\n");
    }
    printf("(");
    for (j = 0; j < i; j++) {
        if (j == i - 1)
            printf("%d", arr[j]);
        else
            printf("%d, ", arr[j]);
    }
    printf(")   ");
    printf("(");
    for (j = i; j < n; j++) {
        if (j == n - 1) {
            printf("%d", arr[j]);
        }
        else {
            printf("%d, ", arr[j]);
        }
    }
    printf(")");
    printf("%10d Add\n", key);
}

int main(void)
{
    int n;
    int *ar;
 
    printf("Amount of List : ");
    scanf("%d", &n);
 
    printf("Enter the Contents of List : ");
    ar = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
 
    InsertionSort(ar, n);
 
    free(ar);
    
    return 0;
}
