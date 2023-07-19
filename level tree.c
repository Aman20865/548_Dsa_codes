#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
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

// Function to insert a node in the binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to find the number of levels in a binary tree
int findLevels(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftDepth = findLevels(root->left);
        int rightDepth = findLevels(root->right);

        if (leftDepth > rightDepth) {
            return (leftDepth + 1);
        } else {
            return (rightDepth + 1);
        }
    }
}

// Function to count the nodes in each level of a binary tree
void countNodesPerLevel(Node* root, int level, int* count, FILE* outputFile) {
    if (root == NULL) {
        return;
    }

    if (level == 1) {
        (*count)++;
    } else if (level > 1) {
        countNodesPerLevel(root->left, level - 1, count, outputFile);
        countNodesPerLevel(root->right, level - 1, count, outputFile);
    }
}

// Function to generate random numbers and build the binary tree
Node* generateRandomTree(int n) {
    Node* root = NULL;
    int i, num;
    FILE* inputFile = fopen("input.txt", "w");
    srand(time(NULL));

    for (i = 0; i < 5; i++) {
        num = rand() % 100;  // Generate a random number between 0 and 99
        fprintf(inputFile, "%d ", num);
        root = insertNode(root, num);
    }

    fclose(inputFile);
    return root;
}

int main() {
    int n, i;
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL) {
        printf("Unable to open the input file.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &n);
    Node* root = generateRandomTree(n);
    fclose(inputFile);

    // Find the number of levels in the tree
    int levels = findLevels(root);
    fprintf(outputFile, "Number of levels in the tree: %d\n", levels);

    // Count the nodes present in each level
    for (i = 1; i <= levels; i++) {
        int count = 0;
        countNodesPerLevel(root, i, &count, outputFile);
        fprintf(outputFile, "Nodes in level %d: %d\n", i, count);
    }

    fclose(outputFile);
    printf("Output has been written to the output.txt file.\n");

    return 0;
}

