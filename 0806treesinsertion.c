#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* create(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = create(data);
        return root;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }


    return root;
}


void inorder(Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, file);
    fprintf(file, "%d\n ", root->data);
    inorder(root->right, file);
}

void preorder(Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }

    fprintf(file, "%d\n ", root->data);
    preorder(root->left, file);
    preorder(root->right, file);
}


void postorder(Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }

    postorder(root->left, file);
    postorder(root->right, file);
    fprintf(file, "%d\n ", root->data);
}


void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    int n, i, data;
    time_t t;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    FILE* inputfp = fopen("input.txt", "w");
     srand((unsigned) time(&t));


    for (i = 0; i < n; i++) {
        data = rand() % 100;
        printf("%d\n",data);
        fprintf(inputfp,"%d\n",data);
        root = insert(root, data);
    }
    fclose(inputfp);

    FILE* inorderfp = fopen("inorder.txt", "w");
    if (inorderfp == NULL) {
        printf("Error opening inorder.txt file.\n");
        return 1;
    }

    FILE* preorderfp = fopen("preorder.txt", "w");
    if (preorderfp == NULL) {
        printf("Error opening preorder.txt file.\n");
        fclose(inorderfp);
        return 1;
    }

    FILE* postorderfp = fopen("postorder.txt", "w");
    if (postorderfp == NULL) {
        printf("Error opening postorder.txt file.\n");
        fclose(inorderfp);
        fclose(preorderfp);
        return 1;
    }


    inorder(root, inorderfp);
    preorder(root, preorderfp);
    postorder(root,postorderfp);
}
