#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else {
        if (data < root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

// Function to count the number of levels in a binary tree
int countLevels(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = countLevels(root->left);
        int rightHeight = countLevels(root->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

// Function to count the number of nodes in each level of a binary tree
void countNodesInLevels(struct Node* root, int level, int* countArr) {
    if (root == NULL) {
        return;
    }

    countArr[level]++;

    countNodesInLevels(root->left, level + 1, countArr);
    countNodesInLevels(root->right, level + 1, countArr);
}

int main() {
    struct Node* root = NULL;
    int num, levels;

    // Read input numbers from a file
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    srand(time(0)); // Seed the random number generator

    // Insert numbers into the binary tree
    while (fscanf(file, "%d", &num) != EOF) {
        root = insertNode(root, num);
    }

    fclose(file);

    // Count the number of levels in the tree
    levels = countLevels(root);

    // Create an array to store the count of nodes in each level
    int* countArr = (int*)calloc(levels, sizeof(int));

    // Count the number of nodes in each level
    countNodesInLevels(root, 0, countArr);

    // Display the results
    printf("Number of levels in the tree: %d\n", levels);
    printf("Number of nodes in each level:\n");
    for (int i = 0; i < levels; i++) {
        printf("Level %d: %d nodes\n", i, countArr[i]);
    }

    // Free memory
    free(countArr);

    return 0;
}
