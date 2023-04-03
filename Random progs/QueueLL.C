#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;
node *front = NULL;
node *Rear = NULL;
void enqueue(int value){
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    ptr->next = NULL;

    if((front == NULL) && (Rear == NULL)){
        front = Rear = ptr;
    } else {
        Rear->next  = ptr;
    }
    printf("Node is Inserted\n\n");
}

int dequeue(){
    if(front == NULL){
        printf("\nUnderflow\n");
        return -1;
    }
    else {
        node *temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        return temp_data;
    }
}

void Display(){
    node *temp;
    if((front == NULL) && (Rear == NULL)){
        printf("\nQueue is Empty");
    } else {
        printf("The Queue is \n");
        temp = front;
        while(temp){
            printf("%d--->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n\n");
    }
}

int main() {
    int choice, value;
    printf("\nImplementation of Queue using Linked List\n");
    while (choice != 4) {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", & choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", & value);
                enqueue(value);
                break;
            case 2:
                printf("Popped element is :%d\n", dequeue());
                break;
            case 3:
                Display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nWrong Choice\n");
        }
    }
    return 0;
}