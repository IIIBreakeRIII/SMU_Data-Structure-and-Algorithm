//
//  FindMusic.c
//  Week9
//
//  Created by 현소류 on 2022/11/01.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

typedef struct {
    char word[MAX_WORD_SIZE];
    char meaning[MAX_MEANING_SIZE];
} element;

typedef struct TreeNode {
    element key;
    struct TreeNode * left, * right;
} TreeNode;

int Compare(element e1, element e2) {
    return strcmp(e1.word, e2.word);
}

void Display(TreeNode * p) {
    if(p != NULL) {
        printf("(");
        Display(p -> left);
        printf("%s:%s", p -> key.word, p -> key.meaning);
        Display(p -> right);
        printf(")");
    }
}

TreeNode * Search(TreeNode * root, element key) {
    TreeNode * p = root;
    while(p != NULL) {
        if(Compare(key, p -> key) == 0) {
            return p;
        }
        else if(Compare(key, p -> key) < 0) {
            p = p -> left;
        }
        else if(Compare(key, p -> key) > 0) {
            p = p -> right;
        }
    }
    return p;
}

TreeNode * NewNode(element item) {
    TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp -> key = item;
    temp -> left = temp -> right = NULL;
    return temp;
}

TreeNode * InsertNode(TreeNode * node, element key) {
    if(node == NULL) {
        return NewNode(key);
    }
    if(Compare(key, node -> key) < 0) {
        node -> left = InsertNode(node -> left, key);
    }
    else if(Compare(key, node -> key) > 0) {
        node -> right = InsertNode(node -> right, key);
    }
    return node;
}

TreeNode * MinValueNode(TreeNode * node) {
    TreeNode * current = node;
    while(current -> left != NULL) {
        current = current -> left;
    }
    return current;
}

TreeNode * DeleteNode(TreeNode * root, element key) {
    if(root == NULL) {
        return root;
    }
    if(Compare(key, root -> key) < 0) {
        root -> left = DeleteNode(root -> left, key);
    }
    if(Compare(key, root -> key) > 0) {
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
        root -> key = temp -> key;
        root -> right = DeleteNode(root -> right, temp -> key);
    }
    return root;
}

void Help() {
    printf("-- Music Data Managing Program -- \n\n");
    printf("1. Add Music \n");
    printf("2. Search Music \n");
    printf("0. Exit \n\n");
    printf("Enter Menu Command Num : ");
}

void Help2() {
    printf("-- Search Music -- \n\n");
    printf("1. Search By Title \n");
    printf("2. Search By Artist \n");
    printf("0. Move To Before Menu \n\n");
    printf("Enter Menu Command Num : ");
}

void Help3() {
    printf("-- Search By Title -- \n\n");
    printf("1. Korean \n");
    printf("2. English \n");
    printf("0. Move To Before Menu \n\n");
    printf("Enter Menu Command Num : ");
}

int main(void) {
   char command, command2, command3;
    
   element e;
   TreeNode * root = NULL;
   TreeNode * tmp;

   do {
      Help();
       
      command = getchar();
      getchar();
       
      switch (command) {
          case '1':
             printf("Title : ");
             gets(e.word);
              
             printf("Artist : ");
             gets(e.meaning);
              
             root = InsertNode(root, e);
              
             break;
              
          case '2':
             do {
                Help2();
                 
                command2 = getchar();
                getchar();
                 
                switch (command2) {
                   case '1':
                      do {
                         Help3();
                          
                         command3 = getchar();
                         getchar();
                          
                         switch (command3) {
                            case '1':
                               printf("Enter Title Of Music(Korean) : ");
                               gets(e.word);
                                 
                               tmp = Search(root, e);
                                 if(tmp != NULL) {
                                     printf("Artist : %s\n", e.meaning);
                                 }
                               break;
                            case '2':
                               printf("Enter Title Of Music(English) : ");
                               gets(e.word);
                                 
                               tmp = Search(root,e);
                                 if(tmp != NULL) {
                                     printf("Artist : %s\n", e.meaning);
                                 }
                               break;
                         }
                      } while (command3 != '0');
                      break;
                   case '2':
                      printf("Search By Artist \n Enter Artist : ");
                      gets(e.meaning);
                        
                      tmp = Search(root,e);
                        if(tmp != NULL) {
                            printf("Title : %s\n",e.word);
                        }
                      break;
                      
                }
             } while (command2 != '0');
             break;
          }
   } while (command != '0');
   return 0;
}
