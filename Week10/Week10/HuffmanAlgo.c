//
//  HuffmanAlgo.c
//  Week10
//
//  Created by 현소류 on 2022/11/07.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 99999

typedef struct TreeNode {
    char ch;
    int weight;
    struct TreeNode * left;
    struct TreeNode * right;
} TreeNode;

typedef TreeNode * TreeNodePTR;

typedef struct {
    TreeNodePTR HiddenTree;
    char ch;
    int key;
} element;

typedef struct {
    element heap[MAX];
    int HeapSize;
} HeapType;

typedef HeapType * HeapTypePTR;

HeapTypePTR HeapInit() {
    HeapTypePTR h = (HeapTypePTR)malloc(sizeof(HeapType));
    h -> HeapSize = 0;
    return h;
}

void InsertMinHeap(HeapTypePTR h, element item) {
    int i;
    i = ++(h -> HeapSize);
    while((i != 1) && (item.key < h -> heap[i / 2].key)) {
        h -> heap[i] = h -> heap[i / 2];
        i /= 2;
    }
    h -> heap[i] = item;
}

element DeleteMinHeap(HeapTypePTR h) {
    int parent, child;
    element item, temp;
    temp = h -> heap[1];
    temp = h -> heap[(h -> HeapSize)--];
    parent = 1;
    child = 2;
    
    while (child <= h -> HeapSize) {
        if((h -> heap[parent * 2].key >= 0) && (h -> heap[(parent * 2) + 1].key >= 0)) {
            if ((h -> heap[parent * 2].key) < (h -> heap[(parent * 2) + 1].key)) {
                child = parent * 2;
            }
            else {
                child = (parent * 2) + 1;
            }
        }
        if (temp.key <= h -> heap[child].key) {
            break;
        }
        h -> heap[parent] = h -> heap[child];
        parent = child;
        child *= 2;
    }
    h -> heap[parent] = temp;
    return item;
}

