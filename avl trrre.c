#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node* insert(Node* node, int key, FILE* outputFile) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key, outputFile);
    else if (key > node->key)
        node->right = insert(node->right, key, outputFile);
    else
        return node;


    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    fprintf(outputFile, "Node %d inserted\n", key);
    printAVLTree(node, 0, outputFile);
    fprintf(outputFile, "\n\n\n");

    // Return the unchanged node pointer
    return node;
}

// Function to print the AVL tree in an in-order traversal
void printAVLTree(Node* node, int space, FILE* outputFile) {
    if (node == NULL)
        return;

    space += 10;

    printAVLTree(node->right, space, outputFile);

    fprintf(outputFile, "\n");
    for (int i = 10; i < space; i++)
        fprintf(outputFile, " ");
    fprintf(outputFile, "%d", node->key);

    if (node->left != NULL || node->right != NULL)
        fprintf(outputFile, "[]");

    fprintf(outputFile, "\n");

    printAVLTree(node->left, space, outputFile);
}

int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}
int main() {
    srand(time(NULL));

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to create the output file.\n");
        return 1;
    }

    Node* root = NULL;

    for (int i = 1; i <= 5; i++) {
        int key = getRandomNumber(1, 100);
        root = insert(root, key, outputFile);
    }

    fclose(outputFile);

    printf("AVL tree states have been written to 'output.txt'.\n");

    return 0;
}
