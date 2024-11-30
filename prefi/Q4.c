#include <stdio.h>
#include <stdlib.h>

// Definition of the binary tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform the in-place flattening of the binary tree
void flattenTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // Flatten the left subtree
    if (root->left != NULL) {
        flattenTree(root->left);

        // Store the right subtree
        struct Node* tempRight = root->right;

        // Move the left subtree to the right
        root->right = root->left;
        root->left = NULL;

        // Find the last node of the new right subtree
        struct Node* current = root->right;
        while (current->right != NULL) {
            current = current->right;
        }

        // Connect the previously stored right subtree
        current->right = tempRight;
    }

    // Flatten the right subtree
    flattenTree(root->right);
}

// Function to print the flattened tree as a linked list
void printFlattenedTree(struct Node* root) {
    while (root != NULL) {
        printf("%d ", root->data);
        root = root->right;
    }
    printf("\n");
}

int main() {
    // Example binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->right = createNode(6);

    // Flatten the binary tree into a linked list
    flattenTree(root);

    // Print the flattened tree
    printf("Flattened tree in preorder as linked list:\n");
    printFlattenedTree(root);

    return 0;
}

