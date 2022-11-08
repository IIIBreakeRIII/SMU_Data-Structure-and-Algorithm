//
//  HuffmanAlgo.c
//  Week10
//
//  Created by 현소류 on 2022/11/07.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 99999

typedef struct TreeNode {
    char ch;
    int weight;
    struct TreeNode * left;
    struct TreeNode * right;
} TreeNode;

typedef TreeNode * TreeNodePTR;

typedef struct {
    TreeNodePTR HiddenTree;
    char ch;
    int key;
} element;

typedef struct {
    element heap[MAX];
    int HeapSize;
} HeapType;

typedef HeapType * HeapTypePTR;

HeapTypePTR HeapInit() {
    HeapTypePTR h = (HeapTypePTR)malloc(sizeof(HeapType));
    h -> HeapSize = 0;
    return h;
}

void InsertMinHeap(HeapTypePTR h, element item) {
    int i;
    i = ++(h -> HeapSize);
    while((i != 1) && (item.key < h -> heap[i / 2].key)) {
        h -> heap[i] = h -> heap[i / 2];
        i /= 2;
    }
    h -> heap[i] = item;
}

element DeleteMinHeap(HeapTypePTR h) {
    int parent, child;
    element item, temp;
    temp = h -> heap[1];
    temp = h -> heap[(h -> HeapSize)--];
    parent = 1;
    child = 2;
    
    while (child <= h -> HeapSize) {
        if((h -> heap[parent * 2].key >= 0) && (h -> heap[(parent * 2) + 1].key >= 0)) {
            if ((h -> heap[parent * 2].key) < (h -> heap[(parent * 2) + 1].key)) {
                child = parent * 2;
            }
            else {
                child = (parent * 2) + 1;
            }
        }
        if (temp.key <= h -> heap[child].key) {
            break;
        }
        h -> heap[parent] = h -> heap[child];
        parent = child;
        child *= 2;
    }
    h -> heap[parent] = temp;
    return item;
}

TreeNodePTR MakeHTree(TreeNodePTR left, TreeNodePTR right) {
    TreeNodePTR node = (TreeNodePTR)malloc(sizeof(TreeNode));
    node -> left = left;
    node -> right = right;
    return node;
}

int IsLeaf(TreeNodePTR T) {
    return !(T -> left) && !(T -> right);
}

typedef struct {
    char ch;
    int freq;
    int * codes;
    int CodesStop;
} PrintArray;
PrintArray * PArray;

void PrintCodesArray(int codes[], int stop, int freq, char ch) {
    static int i = 0;
    printf("[%d] %c(Frequency : %d, Stop : %d) : ", i, ch, freq, stop);
    for(int j = 0; j < stop; j++) {
        printf("%d", codes[j]);
    }
    printf("\n");
    
    PArray[i].ch = ch;
    PArray[i].freq = freq;
    PArray[i].CodesStop = stop;
    
    for(int k = 0; k < PArray[i].CodesStop; k++) {
        (PArray[i].codes)[k] = codes[k];
    }
    i++;
}

void MakeCodesArray(TreeNodePTR T, int codes[], int idx) {
    if (T -> left) {
        codes[idx] = 1;
        MakeCodesArray(T -> left, codes, idx + 1);
    }
    if(T -> right) {
        codes[idx] = 0;
        MakeCodesArray(T -> right, codes, idx + 1);
    }
    if(IsLeaf(T)) {
        PrintCodesArray(codes, idx, T -> weight, T -> ch);
    }
}

TreeNodePTR HuffmanTree;
void MakeHuffmanHeap(int freq[], char CHList[], int n) {
    int i;
    TreeNodePTR HNode;
    HeapTypePTR h;
    element e, e1, e2;
    int codes[100];
    
    h = HeapInit();
    
    for(i = 0; i < n; i++) {
        HNode = MakeHTree(NULL, NULL);
        
        e.ch = HNode -> ch = CHList[i];
        e.key = HNode -> weight = freq[i];
        e.HiddenTree = HNode;
        
        InsertMinHeap(h, e);
    }
    
    for(i = 1; i < n; i++) {
        e1 = DeleteMinHeap(h);
        e2 = DeleteMinHeap(h);
        
        HNode = MakeHTree(e1.HiddenTree, e2.HiddenTree);
        
        e.key = HNode -> weight = e1.key + e2.key;
        e.HiddenTree = HNode;
        
        InsertMinHeap(h, e);
    }
    e = DeleteMinHeap(h);
    HuffmanTree = e.HiddenTree;
    
    MakeCodesArray(HuffmanTree, codes, 0);
}

int GetI;
char GetSymbol(char string[]) {
    return string[GetI++];
}

char * string = NULL;
int InputProcessing(char * CHList, int * freq) {
    int alphabet = 26;
    char * AlphabetList = (char *)malloc(sizeof(char) * alphabet);
    int * AlphabetFreq = (int *)calloc(alphabet, sizeof(int));
    for(int i = 0; i < alphabet; i++) {
        AlphabetList[i] = 'a' + i;
    }
    
    string = (char *)malloc(sizeof(char) * MAX);
    gets(string);
    
    char tmp = 0;
    int idx = 0;
    GetI = 0;
    while((tmp = GetSymbol(string)) != 0) {
        if('a' <= tmp && tmp <= 'z') {
            idx = tmp - 'a';
            AlphabetFreq[idx]++;
        }
    }
    
    int num = 0;
    for(int i = 0; i < alphabet; i++) {
        if(AlphabetFreq[i] > 0) {
            CHList[num] = AlphabetList[i];
            freq[num++] = AlphabetFreq[i];
        }
    }
    for(int i = 0; i < num; i++) {
        printf("%c:%d\n", CHList[i], freq[i]);
    }
    
    return num;
}

int main(void) {
    char * CHList = (char *)malloc(sizeof(char) * MAX);
    int * freq = (int *)malloc(sizeof(int) * MAX);
    int num = InputProcessing(CHList, freq);
    PArray = (PrintArray * )malloc(sizeof(PrintArray) * MAX);
    
    for (int i = 0; i < num; i++) {
        PArray[i].codes = (int *)malloc(sizeof(PrintArray) * MAX);
    }
    
    MakeHuffmanHeap(freq, CHList, num);
    
    int tmp;
    GetI = 0;
    char * HuffmanEncode = (char *)malloc(sizeof(char));
    int HuffmanEncodeSize = 0;
    while ((tmp = GetSymbol(string)) != 0) {
        for (int i = 0; i < num; i++) {
            if (PArray[i].ch == tmp) {
                for (int k = 0; k < PArray[i].CodesStop; k++) {
                    HuffmanEncode[HuffmanEncodeSize++] = (PArray[i].codes)[k];
                    realloc(HuffmanEncode, sizeof(char) + HuffmanEncodeSize);
                }
                break;
            }
        }
    }

    printf("\n");
    for (int i = 0; i < HuffmanEncodeSize; i++)
        printf("%d", HuffmanEncode[i]);
    printf("\n");

    TreeNode * temp = HuffmanTree;
    for (int i = 0; i < HuffmanEncodeSize; i++) {
        if (HuffmanEncode[i] == 1) {
            temp = temp -> left;
            if ((temp -> left == NULL) && (temp -> right == NULL)) {
                printf("%c",temp -> ch);
                temp = HuffmanTree;
            }
        }
        else {
            temp = temp -> right;
            if ((temp -> left == NULL) && (temp -> right == NULL)) {
                printf("%c", temp -> ch);
                temp = HuffmanTree;
            }
        }
    }
    printf("\n");
    
    return 0;
}
