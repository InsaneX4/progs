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

// Function to count occurrences of an element in the linked list using recursion
int countOccurrences(struct Node* node, int target) {
    if (node == NULL)
        return 0;

    if (node->data == target)
        return 1 + countOccurrences(node->next, target);
    else
        return countOccurrences(node->next, target);
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the linked list
    insert(&head, 5);
    insert(&head, 8);
    insert(&head, 12);
    insert(&head, 17);
    insert(&head, 8); // Adding an extra occurrence of 8

    int targetElement = 8;
    int occurrences = countOccurrences(head, targetElement);

    printf("Number of occurrences of %d: %d\n", targetElement, occurrences);

    return 0;
}
