#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
}*top = NULL;


void push(int x){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));

    if(t==NULL){
        printf("stack is full\n");
    }else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop(){
    int x = -1;
    struct node *t;
    if(top == NULL) {
        printf("stack is Empty\n");
    }else{
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display(){
    struct node *t;
    t = top;
    while(t != NULL) {
        printf("%d\n", t->data);
        t = t->next;
    }
    free(t);
}

int main(){
    push(10);
    push(20);
    push(30);
    Display();
    pop();
    Display();

}