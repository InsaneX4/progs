#include <stdio.h>
#include <stdlib.h>

void createnode();
void findcycle();

struct node 
{
    int data;
    struct node *next;
};

typedef struct node node ;
node *head = NULL;

void main(){
    int i,n;
    printf("Enter no. of nodes");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        createnode();
    }
    findcycle(head);



}
void findcycle(node *head){
    node *slow  = head; 
    node *fast  = head;

    while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            printf("cycle exist");
            exit(0);
        }
    }
    printf("There is no cycle exist");

}
void createnode(){
    node *temp;
    temp = (node *)malloc(sizeof(node));

    if(temp == NULL){ printf("Memory Full");
    exit(0);
    }
    printf("Enter the element");
    scanf("%d",&temp->data);
    temp->next = NULL;
    if(head == NULL){
    head = temp;
    }
    else{
        node *p = head;

        while(p->next != NULL){
            p=p->next;
        }
        p->next = head;
        p = NULL;
        temp = NULL;
    }

    }