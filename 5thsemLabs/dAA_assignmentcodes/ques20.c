#include <stdio.h>
#include <stdlib.h>

// Define the structure of a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to display the linked list using recursion
void display(struct Node* node) {
    if (node == NULL)
        return;

    printf("%d -> ", node->data); // Print the data of the current node
    display(node->next); // Recursively move to the next node
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the linked list
    insert(&head, 5);
    insert(&head, 8);
    insert(&head, 12);
    insert(&head, 17);

    printf("Linked list nodes: ");
    display(head);
    printf("NULL\n");

    return 0;
}
