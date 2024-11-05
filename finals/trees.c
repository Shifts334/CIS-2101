#include<stdlib.h>
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

// Function to find the minimum value node in a BST
BST findMin(BST root) {
    // Traverse to the leftmost node
    while(root->left != NULL) root = root->left;
    return root;
}

// Function to find the maximum value node in a BST
BST findMax(BST root) {
    // Traverse to the rightmost node
    while(root->right != NULL) root = root->right;
    return root;
}

// Function to delete a node from the BST
BST deleteNode(BST root, int data) {
    // Base case: if the tree is empty
    if(root == NULL) return root;

    // If the data to be deleted is smaller than the root's data,
    // then it lies in the left subtree
    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    // If the data to be deleted is greater than the root's data,
    // then it lies in the right subtree
    else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // If data is the same as root's data, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if(root->left == NULL) {
            BST temp = root->right;
            free(root); // Free the memory of the node
            return temp; // Return the non-null child or NULL
        } else if(root->right == NULL) {
            BST temp = root->left;
            free(root); // Free the memory of the node
            return temp; // Return the non-null child
        }

        // Node with two children: Choose either in-order successor or in-order predecessor
        if(rand() % 2) {
            // In-order successor: smallest node in the right subtree
            BST temp = findMin(root->right);
            root->data = temp->data; // Copy the in-order successor's data to this node
            root->right = deleteNode(root->right, temp->data); // Delete the in-order successor
        } else {
            // In-order predecessor: largest node in the left subtree
            BST temp = findMax(root->left);
            root->data = temp->data; // Copy the in-order predecessor's data to this node
            root->left = deleteNode(root->left, temp->data); // Delete the in-order predecessor
        }
    }
    return root; // Return the (possibly new) root
}

// Function for in-order traversal of the BST
void inorderTraversal(BST root) {
    if(root != NULL) {
        inorderTraversal(root->left); // Visit left subtree
        printf("%d ", root->data);    // Visit node
        inorderTraversal(root->right); // Visit right subtree
    }
}
