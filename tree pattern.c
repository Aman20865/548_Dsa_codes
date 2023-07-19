#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to display the tree using tree patterns and arrow marks
void displayTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    displayTree(root->right, level + 1);

    for (int i = 0; i < level; i++) {
        printf("   ");
    }

    if (level > 0) {
        printf(" --> ");
    }

    printf("%d\n", root->data);

    displayTree(root->left, level + 1);
}

// Function to store the tree data in a file
void storeTreeToFile(Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }

    storeTreeToFile(root->right, file);

    fprintf(file, "%d\n", root->data);

    storeTreeToFile(root->left, file);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an empty tree
    Node* root = NULL;

    // Generate and insert random numbers into the tree
    for (int i = 0; i < 10; i++) {
        int num = rand() % 100;
        root = insertNode(root, num);
    }

    // Display the tree
    printf("Tree Pattern:\n");
    displayTree(root, 0);

    // Store the tree data in a file
    FILE* file = fopen("tree_data.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    storeTreeToFile(root, file);
    fclose(file);

    printf("Tree data has been stored in the file 'tree_data.txt'.\n");

    return 0;
}

