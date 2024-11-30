#include <stdio.h>
#include <stdlib.h>

// Updated definition of the BST node structure using typedef
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}*nodePtr;

// Helper function to create a new node
nodePtr createNode(int data) {
    nodePtr newNode = (nodePtr)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
nodePtr insert(nodePtr root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform an inorder traversal and print nodes
void inorderTraversal(nodePtr root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to split the BST into two trees based on value V
nodePtr splitBST(nodePtr root, int V, nodePtr* lessEqual, nodePtr* greater) {
    if (root == NULL) {
        *lessEqual = NULL;
        *greater = NULL;
        return NULL;
    }
    if (root->data <= V) {
        *lessEqual = root;
        nodePtr temp = splitBST(root->right, V, &((*lessEqual)->right), greater);
        return temp;
    } else {
        *greater = root;
        nodePtr temp = splitBST(root->left, V, lessEqual, &((*greater)->left));
        return temp;
    }
}

int main() {
    // Example usage:
    nodePtr root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 10);

    nodePtr lessEqual = NULL;
    nodePtr greater = NULL;

    int V = 5; // Split value
    splitBST(root, V, &lessEqual, &greater);

    // Printing the inorder traversal of both trees
    printf("Inorder traversal of Tree 1 (<= %d): ", V);
    inorderTraversal(lessEqual);
    printf("\n");

    printf("Inorder traversal of Tree 2 (> %d): ", V);
    inorderTraversal(greater);
    printf("\n");

    return 0;
}

