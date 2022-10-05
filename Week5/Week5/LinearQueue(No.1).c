//
//  LinearQueue(No.1).c
//  Week5
//
//  Created by 현소류 on 2022/10/05.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} Queue;

void Error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void InitQueue(Queue *q) {
    q -> rear = -1;
    q -> front = -1;
}

void QueuePrint(Queue *q) {
    int i;
    for(i = 0; i < MAX_QUEUE_SIZE; i++) {
        if(i <= q -> front || i > q -> rear) {
            printf("   | ");
        }
        else {
            printf("%d | ", q -> data[i]);
        }
    }
    printf("\n");
}

int IsFull(Queue *q) {
    if(q -> rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int IsEmpty(Queue *q) {
    if(q -> front == q -> rear) {
        return 1;
    }
    else {
        return 0;
    }
}

void EnQueue(Queue *q, int item) {
    if(IsFull(q)) {
        fprintf(stderr, "\nQueue Is Full\n\n");
        exit(1);
    }
    q -> data[++(q -> rear)] = item;
}

int DeQueue(Queue *q) {
    if(IsEmpty(q)) {
        fprintf(stderr, "\nQueue Is Empty\n\n");
        return -1;
    }
    int item = q -> data[++(q -> front)];
    return item;
}

int main(void) {
    int item = 0;
    Queue q;
    
    InitQueue(&q);
    
    EnQueue(&q, 10); QueuePrint(&q);
    EnQueue(&q, 20); QueuePrint(&q);
    EnQueue(&q, 30); QueuePrint(&q);
    EnQueue(&q, 40); QueuePrint(&q);
    EnQueue(&q, 50); QueuePrint(&q);
    
    item = DeQueue(&q); QueuePrint(&q);
    item = DeQueue(&q); QueuePrint(&q);
    
    return 0;
}
