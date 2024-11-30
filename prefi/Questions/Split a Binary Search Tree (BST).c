#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} *TreeNode;

// Function to create a new tree node
TreeNode create_node(int value) {
    TreeNode new_node = (TreeNode)malloc(sizeof(struct TreeNode));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to perform inorder traversal and print the values
void inorder_traversal(TreeNode root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->value);
    inorder_traversal(root->right);
}

// Function to split the BST into two trees based on value V
void split_bst(TreeNode root, int V, TreeNode* tree1, TreeNode* tree2) {
	if (root == NULL) {
        *tree1 = NULL;
        *tree2 = NULL;
        return;
    }

    if (root->value <= V) {
        *tree1 = root; 
        split_bst(root->right, V, &((*tree1)->right), tree2);
    } else {
        *tree2 = root;  
        split_bst(root->left, V, tree1, &((*tree2)->left));
    }
}

// Function to insert a new node into the BST
TreeNode insert(TreeNode root, int value) {
    if (root == NULL) {
        return create_node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

int main() {
    TreeNode root = NULL;

    // Insert nodes into the BST
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 25);

    int V;
    printf("Enter the value V: ");
    scanf("%d", &V);

    TreeNode tree1 = NULL, tree2 = NULL;

    // Split the BST into two trees based on V
    split_bst(root, V, &tree1, &tree2);

    // Print the inorder traversal of both resulting trees
    printf("Inorder traversal of Tree 1 (<= %d): ", V);
    inorder_traversal(tree1);
    printf("\n");

    printf("Inorder traversal of Tree 2 (> %d): ", V);
    inorder_traversal(tree2);
    printf("\n");

    return 0;
}
