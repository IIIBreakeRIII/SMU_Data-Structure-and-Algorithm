//
//  LinkedList(No.1).c
//  Week6
//
//  Created by 현소류 on 2022/10/08.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
} element;

typedef struct {
    element data;
    struct ListNode* link;
} ListNode;

ListNode * InsertFirst(ListNode * head, element value) {
    ListNode * NewNode = (ListNode *)malloc(sizeof(ListNode));
    
    NewNode -> data = value;
    NewNode -> link = head;
    head = NewNode;
    
    return head;
}

void PrintList(ListNode * head) {
    for(ListNode * p = head; p != NULL; p = p -> link) {
        printf("%s \n", p -> data.name);
    }
}

int main(void) {
    ListNode * head = NULL;
    element data;
    while (1) {
        printf("Enter Fruit Name(If You Want To End The Program, Enter End) : ");
        gets(data.name);
        if(strcmp(data.name, "End") == 0) {
            break;
        }
        head = InsertFirst(head, data);
        PrintList(head);
        printf("\n");
    }
    return 0;
}
