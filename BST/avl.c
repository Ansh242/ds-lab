#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Get height of the node
int height(struct Node *n) {
    return (n == NULL) ? 0 : n->height;
}

// Get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1; // New node is initially added at leaf
    return node;
}

// Right Rotate
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left Rotate
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get Balance Factor
int getBalance(struct Node *n) {
    return (n == NULL) ? 0 : height(n->left) - height(n->right);
}

// Recursive function to insert a key
struct Node* insert(struct Node* node, int key) {
    // 1. Standard BST insertion
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys not allowed
        return node;

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get balance factor to check if it became unbalanced
    int balance = getBalance(node);

    // Case 1: Left Left (LL)
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Case 2: Right Right (RR)
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Case 3: Left Right (LR)
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right Left (RL)
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(struct Node *root) {
    if(root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30); // Triggers RR rotation
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25); // Triggers LR/RL rotations

    printf("Preorder traversal of the balanced AVL tree: \n");
    preOrder(root);

    return 0;
}