//
//  MP3Player(No.1).c
//  Week7
//
//  Created by 현소류 on 2022/10/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * element;

typedef struct DListNode {
    struct DListNode * lLink;
    struct DListNode * rLink;
    element data;
} DListNode;

DListNode * current;

void init(DListNode * head) {
    head -> lLink = head;
    head -> rLink = head;
}

void dInsert(DListNode * prev, element data) {
    DListNode * new_node = (DListNode *)malloc(sizeof(DListNode));
    new_node -> data = (char *)malloc(sizeof(char) * (strlen(data) + 1));
    strcpy(new_node -> data, data);
    printf("Length Of Data [%s] Is : %d\n", new_node -> data, strlen(new_node -> data));
    
    new_node -> rLink = prev -> rLink;
    new_node -> lLink = prev;
    
    prev -> rLink -> lLink = new_node;
    prev -> rLink = new_node;
}

void dDelete(DListNode * head, DListNode * removed) {
    if(removed == head) {
        return;
    }
    else {
        removed -> lLink -> rLink = removed -> rLink;
        removed -> rLink -> lLink = removed -> lLink;
        if(removed == current) {
            current = current -> rLink;
        }
        free(removed);
    }
}

void FreeNode(DListNode * head) {
    DListNode * p = head -> rLink, * next;
    while (p != head) {
        next = p -> rLink;
        free(p);
        p = next;
    }
}

void PrintDList(DListNode * head) {
    DListNode * p = head -> rLink;
    for(;p != head; p = p -> rLink) {
        if(p == current) {
            printf("|| <-|  ## %s ##  |-> ||", p -> data);
        }
        else {
            printf("|| <-|  %s  |-> ||", p -> data);
        }
    }
    printf("\n\n");
}

int main(void) {
    char ch;
    char title[100];
    
    char songA[] = "Mammamia";
    char songB[] = "Dancing Queen";
    char songC[] = "Fernando";
    
    DListNode * head = (DListNode * )malloc(sizeof(DListNode));
    init(head);
    
    dInsert(head, songA);
    dInsert(head, songB);
    dInsert(head, songC);
    
    current = head -> rLink;
    PrintDList(head);
    
    do {
        printf("\n Enter Command Line By (< | > | q) : ");
        ch = getchar();
        
        switch(ch) {
            case '<':
                current = current -> lLink;
                if(current == head) {
                    current = head -> lLink;
                }
                getchar();
                break;
                
            case '>':
                current = current -> rLink;
                if(current == head) {
                    current = head -> rLink;
                }
                getchar();
                break;
        }
        printf("\n---- %s ---- playing\n", current->data);
        
        PrintDList(head);
    } while (ch != 'q');
    
    printf("\n\n Delete \n");
    for(int i = 0; i < 5; i++) {
        PrintDList(head);
        dDelete(head, head -> rLink);
    }
    
    free(head);
    return 0;
}
