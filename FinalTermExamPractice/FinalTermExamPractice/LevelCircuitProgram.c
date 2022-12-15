//
//  LevelCircuitProgram.c
//  FinalTermExamPractice
//
//  Created by 현소류 on 2022/12/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode * left, * right;
} TreeNode;

#define MAX_QUEUE_SIZE 100

typedef TreeNode * element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// Error Func.

void error(char * message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// Init State Func.

void InitQueue(QueueType * q) {
    q -> front = q -> rear = 0;
}

int IsEmpty(QueueType * q) {
    return (q -> front == q -> rear);
}

// Full State Func.

int IsFull(QueueType * q) {
    return ((q -> rear + 1) % MAX_QUEUE_SIZE == q -> front);
}

// Insert Func.

void enqueue(QueueType * q, element item) {
    if(IsFull(q)) {
        error("큐가 포화상태임");
    }
    q -> rear = (q -> rear + 1) % MAX_QUEUE_SIZE;
    q -> data[q -> rear] = item;
}

// Delete Func.

element dequeue(QueueType * q) {
    if(IsEmpty(q)) {
        error("큐가 공배상태임");
    }
    q -> front = (q -> front + 1) % MAX_QUEUE_SIZE;
    return q -> data[q -> front];
}

void LevelOrder(TreeNode * ptr) {
    QueueType q;
    
    InitQueue(&q);
    
    if(ptr == NULL) {
        return;
    }
    enqueue(&q, ptr);
    while(!IsEmpty(&q)) {
        ptr = dequeue(&q);
        printf("[%d] ", ptr -> data);
        if(ptr -> left) {
            enqueue(&q, ptr -> left);
        }
        if(ptr -> right) {
            enqueue(&q, ptr -> right);
        }
    }
}

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode * root = &n6;

int main(void) {
    printf("레벨 순회 = ");
    LevelOrder(root);
    printf("\n");
    return 0;
}
