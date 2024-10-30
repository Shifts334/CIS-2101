#include<stdio.h>


typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}*BST;

BST createNode(int data){
    BST newNode = (BST)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Memory allocation failed\n");
        return NULL;
    }
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
}

