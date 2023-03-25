#include <stdio.h>
#include <stdlib.h>

void createnode();
int listLength();
void findcycle();
int deleteAtBegin();
int deleteAtEnd();

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
    printf("Size: %d\n",listLength(head));

    printf("New Size %d\n",deleteAtBegin(head));
    printf("New Size %d\n",deleteAtEnd(head));

}

int listLength(node *head){
    int count = 0;
    
    if(head == NULL){
        return count;
    } else{
        node *p = head;
        count = 1;
        while(p->next != NULL){
            p = p->next;
            count++;
        }

        
    }
    return count;
    
}
int deleteAtBegin(node *head){
    if(head == NULL){
        printf("List is Empty");
        exit(0);
    }
    if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        node *p = head;
        head = head->next;
        free(p);
        p=NULL;
    }
    return listLength(head);
}

int deleteAtEnd(node *head){
    
    if(head==NULL){
        printf("List is Empty");
        exit(0);
    }
    else if(head->next == NULL){
        free(head);
        head= NULL;
    } else{
    node *q = head;
    node *p = head; 
    while(q->next != NULL){
        p = q;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    q=NULL;
    p=NULL;
    }
    return listLength(head);
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
    exit(1);
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
        p->next = temp;
        p = NULL;
        temp = NULL;
    }

    }


