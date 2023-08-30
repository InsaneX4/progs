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

// Function to reverse the linked list using recursion
struct Node* reverse(struct Node* node) {
    if (node == NULL || node->next == NULL)
        return node;

    struct Node* restReversed = reverse(node->next); // Recursively reverse the rest of the list
    node->next->next = node;
    node->next = NULL;

    return restReversed;
}

// Function to display the linked list
void display(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the linked list
    insert(&head, 5);
    insert(&head, 8);
    insert(&head, 12);
    insert(&head, 17);

    printf("Original linked list: ");
    display(head);

    head = reverse(head);

    printf("Reversed linked list: ");
    display(head);

    return 0;
}
