//
//  CircuitProgram.c
//  FinalTermExamPractice
//
//  Created by 현소류 on 2022/12/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode * left, * right;
} TreeNode;

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode * root = &n6;

// 중위 순회

inorder(TreeNode * root) {
    if(root) {
        inorder(root -> left);
        printf("[%d] ", root -> data);
        inorder(root -> right);
    }
    return 0;
}

// 전위 순회

prorder(TreeNode * root) {
    if(root) {
        printf("[%d] ", root -> data);
        prorder(root -> left);
        prorder(root -> right);
    }
    return 0;
}

// 후위 순회

posorder(TreeNode * root) {
    if(root) {
        posorder(root -> left);
        posorder(root -> right);
        printf("[%d] ", root -> data);
    }
    return 0;
}

int main(void) {
    printf("중위 순회 = ");
    inorder(root);
    printf("\n");
    
    printf("전위 순회 = ");
    prorder(root);
    printf("\n");
    
    printf("후위 순회 = ");
    posorder(root);
    printf("\n");
    
    return 0;
}
