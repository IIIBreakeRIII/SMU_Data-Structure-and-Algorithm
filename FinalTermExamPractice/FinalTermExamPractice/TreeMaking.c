//
//  TreeMaking.c
//  FinalTermExamPractice
//
//  Created by 현소류 on 2022/12/16.
//

#include <stdio.h>

TreeNode * DeleteNode(TreeNode * root, int key) {
    if(root == NULL) {
        return root;
    }
    if(key < root -> key) {
        root -> left = DeleteNode(root -> left, key);
    }
    else if(key > root -> key) {
        root -> right = DeleteNode(root -> right, key);
    }
    else {
        if(root -> left == NULL) {
            TreeNode * temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL) {
            TreeNode * temp = root -> left;
            free(root);
            return temp;
        }
        TreeNode * temp = MinValueNode(root -> right);
        root -> key = tem -> key;
        root -> right = DeleteNode(root -> right, temp -> key);
    }
    return root;
} TreeNode;
