//
//  LinkedListDelete(No.4).c
//  Week6
//
//  Created by 현소류 on 2022/10/10.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListType{
    int size;
    struct ListNode * head;
    struct ListNode * tail;
} ListType;

typedef struct ListNode {
    element data;
    struct ListNode * link;
} ListNode;

ListType * create() {
    ListType * list = (ListType *)malloc(sizeof(ListType));
    list -> size = 0;
    list -> head = list -> tail = NULL;
    return list;
}

void Error(char * message) {
    fprintf(stderr, "%s \n", message);
    exit(1);
}

void InsertList(ListType * list, element item) {
    ListNode * new = malloc(sizeof(ListNode));
    if(new == NULL) {
        Error("Fail To Assign Memory \n");
    }
    new -> data = item;
    new -> link = NULL;
    
    if(list -> tail == NULL) {
        list -> head = list -> tail = new;
    }
    else {
        list -> tail -> link = new;
        list -> tail = new;
    }
    list -> size++;
}

void PrintList(ListType * list) {
    ListNode * p = list -> head;
    for(int i = 0; i < list -> size - 1; i++) {
        printf("%d -> ", p -> data);
        p = p -> link;
    }
    printf("%d\n", p -> data);
}

int GetLength(ListType * list) {
    return list -> size;
}

element Sum(ListType * list) {
    ListNode * p = list -> head;
    element sum = 0;
    for(;p;p = p -> link) {
        sum += p -> data;
    }
    return sum;
}

void Delete(ListType * list, element key) {
    ListNode * p, * next;
    
    p = list -> head;
    
    while(p != NULL) {
        next = p -> link;
        if(p -> data == key) {
            free(p);
        }
        p = next;
    }
    printf("Success To Delete Data %d In Linked List. \n", key);
}

int main() {
    ListType * list;
    int n, data, key;
    
    list = create();
    
    printf("Enter The Number Of Node : ");
    scanf("%d", &n);
    printf("\n");
    
    for(int i = 0; i < n; i++) {
        printf("Node #%d Data : ", i + 1);
        scanf("%d", &data);
        element item = data;
        InsertList(list, item);
    }
    
    printf("\n");
    PrintList(list);
    
    printf("\nSum Of Data In Each Node : %d \n\n", Sum(list));
    
    printf("Enter The Data Which You Want To Delete : ");
    scanf("%d", &key);
    printf("\n");
    
    Delete(list, key);
    printf("\n");
    
    free(list);
}

