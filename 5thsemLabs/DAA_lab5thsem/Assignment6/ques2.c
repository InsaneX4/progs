#include <stdio.h>
#include <stdlib.h>
 
#define MAX_SIZE 50
 
struct SYMBOL {
    char alphabet;
    int frequency;
};
 
struct Node {
    struct SYMBOL symbol;
    struct Node *left;
    struct Node *right;
};
 
struct MinPriorityQueue {
    struct Node *heap[MAX_SIZE];
    int size;
};
 
void swap(struct Node **a, struct Node **b) {
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}
 
void minHeapify(struct MinPriorityQueue *queue, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
 
    if (left < queue->size && queue->heap[left]->symbol.frequency < queue->heap[smallest]->symbol.frequency)
        smallest = left;
 
    if (right < queue->size && queue->heap[right]->symbol.frequency < queue->heap[smallest]->symbol.frequency)
        smallest = right;
 
    if (smallest != index) {
        swap(&queue->heap[index], &queue->heap[smallest]);
        minHeapify(queue, smallest);
    }
}
 
struct MinPriorityQueue *createMinPriorityQueue() {
    struct MinPriorityQueue *queue = (struct MinPriorityQueue *)malloc(sizeof(struct MinPriorityQueue));
    queue->size = 0;
    return queue;
}
 
void insert(struct MinPriorityQueue *queue, struct Node *node) {
    if (queue->size == MAX_SIZE) {
        printf("Priority Queue is full. Cannot insert more symbols.\n");
        return;
    }
 
    int i = queue->size;
    queue->size++;
 
    while (i > 0 && node->symbol.frequency < queue->heap[(i - 1) / 2]->symbol.frequency) {
        queue->heap[i] = queue->heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
 
    queue->heap[i] = node;
}
 
struct Node *extractMin(struct MinPriorityQueue *queue) {
    if (queue->size == 0)
        return NULL;
 
    struct Node *minNode = queue->heap[0];
    queue->size--;
    queue->heap[0] = queue->heap[queue->size];
    minHeapify(queue, 0);
 
    return minNode;
}
 
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c ", root->symbol.alphabet);
        inorderTraversal(root->right);
    }
}
 
struct Node *constructHuffmanTree(struct SYMBOL symbols[], int n) {
    struct Node *left, *right, *top;
 
    struct MinPriorityQueue *queue = createMinPriorityQueue();
 
    for (int i = 0; i < n; i++) {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->symbol = symbols[i];
        node->left = NULL;
        node->right = NULL;
        insert(queue, node);
    }
 
    while (queue->size > 1) {
        left = extractMin(queue);
        right = extractMin(queue);
 
        top = (struct Node *)malloc(sizeof(struct Node));
        top->symbol.alphabet = '-';
        top->symbol.frequency = left->symbol.frequency + right->symbol.frequency;
        top->left = left;
        top->right = right;
 
        insert(queue, top);
    }
 
    struct Node *root = extractMin(queue);
    free(queue);
 
    return root;
}
 
int main() {
    int n;
    struct SYMBOL symbols[MAX_SIZE];
 
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);
 
    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++)
        scanf(" %c", &symbols[i].alphabet);
 
    printf("Enter their frequencies: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &symbols[i].frequency);
 
    struct Node *root = constructHuffmanTree(symbols, n);
 
    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);
    printf("\n");
 
    return 0;
}