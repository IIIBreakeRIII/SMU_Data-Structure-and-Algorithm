//
//  CircularQueue2(No.7).c
//  Week5
//
//  Created by 현소류 on 2022/10/06.
//

#include <stdio.h>

#define MAX_QUEUE_SIZE 100
#define Element int

Element data[MAX_QUEUE_SIZE];
int front;
int rear;

void InitQueue(void) {
    front = rear = 0;
}

int IsEmpty(void) {
    return front == rear;
}

int IsFull(void) {
    return (rear + 1) % MAX_QUEUE_SIZE == front;
}

int Size(void) {
    return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void AddRear(Element val) {
    if(IsFull()) {
        printf("Queue Is Full");
    }
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    data[rear] = val;
}

Element DeleteFront(void) {
    if(IsEmpty()) {
        printf("Queue Error");
    }
    front = (front + 1) % MAX_QUEUE_SIZE;
    return data[front];
}

Element GetFront(void) {
    if(IsEmpty()) {
        printf("Queue Error");
    }
    return data[(front + 1) % MAX_QUEUE_SIZE];
}

void PrintQueue(char msg[]) {
    if(IsEmpty()) {
        printf("Empty Queue. \n");
    }
    else {
        printf("Queue : ");
        if(!IsEmpty()) {
            printf("%d | ", data[front]);
        }
        else {
            printf("%d | ", data[rear]);
        }
        printf("\n");
    }
}

void AddFront(Element val) {
    if(IsFull()) {
        printf("Queue Is Full");
    }
    data[front] = val;
    front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

Element DeleteRear(void) {
    Element ret;
    if(IsEmpty()) {
        printf("Queue Error");
    }
    ret = data[rear];
    rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return ret;
}

Element GetRear(void) {
    if(IsEmpty()) {
        printf("Queue Error");
    }
    return data[rear];
}

int main(void) {
    int i;
    
    InitQueue();
    
    for(i = 1; i < 10; i++) {
        if(i % 2) {
            AddFront(i);
        }
        else AddRear(i);
    }
    
    PrintQueue("Dequeue : ");
    printf("\tDelete Front() > %d\n", DeleteFront());
    printf("\tDelete Rear() > %d\n", DeleteRear());
    printf("\tDelete Front() > %d\n", DeleteFront());
    PrintQueue("Delete Dequeue : ");
}
