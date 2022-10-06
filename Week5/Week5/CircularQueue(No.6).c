//
//  CircularQueue(No.6)c
//  Week5
//
//  Created by 현소류 on 2022/10/06.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef int element;

typedef struct QueueType {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// Init Queue
void InitQueue(QueueType *q) {
    q -> front = q -> rear = 0;
}

// Check Queue Is Empty
int IsEmpty(QueueType *q) {
    return (q -> front == q -> rear);
}

// Check Queuee Is Full
int IsFull(QueueType *q) {
    return (q -> front == ((q -> rear + 1) % MAX_QUEUE_SIZE));
}

// Check Queue Is Full And Append Func.
void Enqueue(QueueType *q, int data) {
    if(IsFull(q)) {
        printf("Queue Is Full. \n");
    }
    else {
        q -> rear = (q -> rear + 1) % MAX_QUEUE_SIZE;
        q -> data[q -> rear] = data;
    }
}

// Check Queue Is Empty And Delete Func.
element Dequeue(QueueType *q) {
    if(IsEmpty(q)) {
        printf("Queue Is Empty. \n");
        exit(1);                                       // Have to use stdlib.h library
    }
    else {
        q -> front = (q -> front + 1) % MAX_QUEUE_SIZE;
        int data = q -> data[q -> front];
        return data;
    }
}

// Print All Element In Queue
void PrintQueue(QueueType *q) {
    if(IsEmpty(q)) {
        printf("Empty Queue. \n");
    }
    else {
        printf("Queue : ");
        if(!IsEmpty(q)) {
            int i = q -> front;
            do {
                i = (i + 1) % MAX_QUEUE_SIZE;
                printf("%d | ", q -> data[i]);
                if(i == q -> rear) {
                    break;
                }
            }
            while(i != q -> front);
            printf("\n");
        }
    }
}

int main() {
    
    QueueType queue;
    
    int item = 0;
    
    // Init Queue
    InitQueue(&queue);
    
    // Append Queue 1, 2, 3, 4, 5, 6, 7, 8, 9
    Enqueue(&queue, 1);
    Enqueue(&queue, 2);
    Enqueue(&queue, 3);
    Enqueue(&queue, 4);
    Enqueue(&queue, 5);
    Enqueue(&queue, 6);
    Enqueue(&queue, 7);
    Enqueue(&queue, 8);
    Enqueue(&queue, 9);
    
    // Print Queue
    PrintQueue(&queue);
    
    // Dequeue Queue 3 Times
    item = Dequeue(&queue);
    item = Dequeue(&queue);
    item = Dequeue(&queue);
    
    // Print Queue
    // Check The Queue 1, 2, 3 Are Deleted
    PrintQueue(&queue);
    
    return 0;
    
}
