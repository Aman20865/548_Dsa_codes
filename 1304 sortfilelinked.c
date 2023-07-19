#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;

    struct node* current = *head_ref;
    struct node* prev = NULL;

    while (current != NULL && current->data < new_data) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        new_node->next = current;
        prev->next = new_node;
    }
}

void display(struct node* head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void write_to_file(FILE* fp, struct node* head)
{
    while (head != NULL) {
        fprintf(fp, "%d ", head->data);
        head = head->next;
    }
}

int main()
{
    struct node* head = NULL;
    FILE* fp_in = fopen("input.txt", "r");
    FILE* fp_out = fopen("output.txt", "w");

    if (fp_in == NULL || fp_out == NULL) {
        printf("Error: Failed to open file\n");
        return 1;
    }

    int num;
    while (fscanf(fp_in, "%d", &num) != EOF) {
        insert(&head, num);
    }

    printf("Sorted List: ");
    display(head);

    write_to_file(fp_out, head);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
