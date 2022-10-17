//
//  LinkedListReverseSort(No.2).c
//  Week7
//
//  Created by 현소류 on 2022/10/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode * link;
} ListNode;

void error(char * message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode * InsertFirst(ListNode * head, element value)
{
    ListNode * p = (ListNode *)malloc(sizeof(ListNode));
    p -> data = value;
    p -> link = head;
    head = p;
    return head;
}

void PrintList(ListNode * head)
{
    for (ListNode * p = head; p != NULL; p = p -> link)
        printf("%d -> ", p -> data);
    printf("NULL \n");
}

ListNode * reverse(ListNode * head)
{
    ListNode * p, * q, * r;

    p = head;
    q = NULL;
    while (p != NULL) {
        r = q;

        q = p;
        p = p -> link;
        q -> link = r;
    }
    return q;
}

int main(void)
{
    ListNode * head = NULL;

    printf("<-- Head List -->\n");
    
    head = InsertFirst(head, 10);
    PrintList(head);
    
    head = InsertFirst(head, 20);
    PrintList(head);
    
    head = InsertFirst(head, 30);
    PrintList(head);

    printf("\n");
    printf("<-- After Reverse -->\n");
    head = reverse(head);
    PrintList(head);

    return 0;
}
