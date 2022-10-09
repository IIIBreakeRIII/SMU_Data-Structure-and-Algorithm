//
//  LinkedListMax(No.2).c
//  Week6
//
//  Created by 현소류 on 2022/10/09.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char SugarContent[100];
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
        printf("%s, ", p -> data.name);
        printf("%s \n", p -> data.SugarContent);
    }
}

int main(void) {
    ListNode * head = NULL;
    element data;
    while (1) {
        printf("Enter Fruit Name(If You Want To End The Program, Enter End) : ");
        gets(data.name);
        gets(data.SugarContent);
        if(strcmp(data.name, "End") == 0) {
            break;
        }
        head = InsertFirst(head, data);
        PrintList(head);
        char max = 0;
        if(data.SugarContent >= max) {
            max = data.SugarContent;
            printf("Max Sugar Content : %d \n", max);
        }
    }
    return 0;
}
