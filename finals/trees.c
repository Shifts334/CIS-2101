#include<stdio.h>
#include<stdlib.h>

//basic structure for a node in a tree
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}nodePtr;


