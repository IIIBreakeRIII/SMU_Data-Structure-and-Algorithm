//
//  HuffmanCode.c
//  FinalTermExamPractice
//
//  Created by 현소류 on 2022/12/17.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode {
    int weight;
    char ch;
    struct TreeNode * left;
    struct TreeNode * right;
} TreeNode;

typedef struct {
    TreeNode * ptree;
    char ch;
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int HeapSize;
} HeapType;

// 생성 함수

HeapType * create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수

void init(HeapType * h) {
    h -> HeapSize = 0;
}

// 삽입 함수

void InsertMinHeap(HeapType * h, element item) {
    int i;
    i = ++(h -> HeapSize);
    
    while((i != 1) && (item.key < h -> heap[i / 2].key)) {
        h -> heap[i] = h -> heap[i / 2];
        i /= 2;
    }
    h -> heap[i] = item;
}

element DeleteMinHeap(HeapType * h) {
    int parent, child;
    element item, temp;
    
    item = h -> heap[1];
    temp = h -> heap[(h -> HeapSize)--];
    parent = 1;
    child = 2;
    while(child <= h -> HeapSize) {
        if((child < h -> HeapSize) && (h -> heap[child].key) > h -> heap[child + 1].key) {
            child++;
        }
        if(temp.key < h -> heap[child].key) {
            break;
        }
        h -> heap[parent] = h -> heap[child];
        parent = child;
        child *= 2;
    }
    h -> heap[parent] = temp;
    return item;
}

// 이진 트리 생성 함수

TreeNode * MakeTree(TreeNode * left, TreeNode * right) {
    TreeNode * node = (TreeNode *) malloc(sizeof(TreeNode));
    node -> left = left;
    node -> right = right;
    return node;
}

// 이진 트리 제거 함수

void DestroyTree(TreeNode * root) {
    if(root == NULL) {
        return;
    }
    DestroyTree(root -> left);
    DestroyTree(root -> right);
    free(root);
}

int IsLeaf(TreeNode * root) {
    return !(root -> left) && !(root -> right);
}

void PrintArray(int codes[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d", codes[i]);
    }
    printf("\n");
}

void PrintCodes(TreeNode * root, int codes[], int top) {
    if(root -> left) {
        codes[top] = 1;
        PrintCodes(root -> left, codes, top + 1);
    }
    
    if(root -> right) {
        codes[top] = 0;
        PrintCodes(root -> right, codes, top + 1);
    }
    
    if(IsLeaf(root)) {
        printf("%c : ", root -> ch);
        PrintArray(codes, top);
    }
}

void HuffmanTree(int freq[], char ch_list[], int n) {
    int i;
    TreeNode * node, * x;
    HeapType * heap;
    element e, e1, e2;
    int codes[100];
    int top = 0;
    
    heap = create();
    init(heap);
    for(i = 0; i < n; i++) {
        node = MakeTree(NULL, NULL);
        e.ch = node -> ch = ch_list[i];
        e.key = node -> weight = freq[i];
        e.ptree = node;
        InsertMinHeap(heap, e);
    }
    for(i = 1; i < n; i++) {
        e1 = DeleteMinHeap(heap);
        e2 = DeleteMinHeap(heap);
        x = MakeTree(e1.ptree, e2.ptree);
        e.key = x -> weight = e1.key + e2.key;
        e.ptree = x;
        printf("%d + %d -> %d \n", e1.key, e2.key, e.key);
        InsertMinHeap(heap, e);
    }
    e = DeleteMinHeap(heap);
    PrintCodes(e.ptree, codes, top);
    DestroyTree(e.ptree);
    free(heap);
}

int main(void) {
    char ch_list = {'s', 'i', 'n', 't', 'e'};
    int freq[] = {4, 6, 8, 12, 15};
    HuffmanTree(freq, ch_list, 5);
    return 0;
}
