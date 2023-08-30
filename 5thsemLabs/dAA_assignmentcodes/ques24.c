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

// Function to print alternate nodes in the linked list using recursion
void printAlternateNodes(struct Node* node, int level) {
    if (node == NULL)
        return;

    if (level % 2 == 0) {
        printf("%d -> ", node->data);
    }

    printAlternateNodes(node->next, level + 1);
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the linked list
    insert(&head, 5);
    insert(&head, 8);
    insert(&head, 12);
    insert(&head, 17);
    insert(&head, 22);

    printf("Alternate nodes in the linked list: ");
    printAlternateNodes(head, 0);
    printf("NULL\n");

    return 0;
}
