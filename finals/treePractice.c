#include<stdio.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}*Node;

// operations

Node createNode(int data);
Node insertNode(int data, Node root); 