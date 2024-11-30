#include <stdio.h>
#include <stdlib.h>

// Define the AVLNode structure using typedef
typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} *AVLNode;

// Helper function to create a new AVL node
AVLNode create_node(int data) {
    AVLNode new_node = (AVLNode)malloc(sizeof(struct AVLNode)); // Allocate memory for the new node
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    new_node->height = 1; // Height of a newly created node is 1
    return new_node;
}





// Insert a node and balance the tree
AVLNode insert(AVLNode node, int data) {
    if (node == NULL) {
        return create_node(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    int balance = balance_factor(node);


    if (balance > 1 && data < node->left->data) {
        return right_rotate(node);
    }

    if (balance < -1 && data > node->right->data) {
        return left_rotate(node);
    }

    if (balance > 1 && data > node->left->data) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node; 
}
// Get the height of a node
int height(AVLNode node) {
    return node ? node->height : 0;
}

// Get the balance factor of a node
int balance_factor(AVLNode node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Find the node with the minimum value (used in deletion)
AVLNode min_value_node(AVLNode node) {
    AVLNode current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}



// In-order traversal to print the tree
void inorder_traversal(AVLNode root) {
    if (root == NULL) return;
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

// Print the height of the tree
void print_height(AVLNode root) {
    printf("Height of the tree: %d\n", height(root));
}
// Right rotation
AVLNode right_rotate(AVLNode y) {
	AVLNode x = y->left;
    AVLNode T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x; 
    return x; 
}

// Left rotation
AVLNode left_rotate(AVLNode x) {
    AVLNode left_rotate(AVLNode x) {
    AVLNode y = x->right;
    AVLNode T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y; 
    return y; 
}
// Delete a node and balance the tree
AVLNode delete(AVLNode root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if ((root->left == NULL) || (root->right == NULL)) {
            AVLNode temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp; 
            }
            free(temp);
        } else {
            AVLNode temp = min_value_node(root->right);

            root->data = temp->data;

            root->right = delete(root->right, temp->data);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balance = balance_factor(root);


    if (balance > 1 && balance_factor(root->left) >= 0) {
        return right_rotate(root);
    }

    if (balance > 1 && balance_factor(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    if (balance < -1 && balance_factor(root->right) <= 0) {
        return left_rotate(root);
    }

    if (balance < -1 && balance_factor(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

// Function to perform the required AVL tree operations

void avl_tree_operations() {
    AVLNode root = NULL;

    // Insert integers from 1 to 5
    for (int i = 1; i <= 5; i++) {
        root = insert(root, i);
    }

    // Delete even numbers (2 and 4)
    root = delete(root, 2);
    print_height(root);
    printf("In-order traversal after deleting 2: ");
    inorder_traversal(root);
    printf("\n");

    root = delete(root, 4);
    print_height(root);
    printf("In-order traversal after deleting 4: ");
    inorder_traversal(root);
    printf("\n");
}

int main() {
    avl_tree_operations();
    return 0;
}
