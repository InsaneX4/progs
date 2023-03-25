#include <stdio.h>
#include <stdlib.h>
struct stack{
    char name;
    int size;
    int top;
    int *s;
};
typedef struct stack stack;
void createstack(stack *st, int s, char c){
    st->name =  c;
    st->size = s;
    st->top = -1;
    st->s = (int *)malloc(st->size*sizeof(int));
}
void Push(stack *st, int data){
    if(st->top == st->size-1){
        printf("Stack Overflow");

    }
    else{
        st->top ++;
        st->s[st->top] = data;
    }
}
int pop(stack *st){
    if(st->top == -1){
        printf("Stack underflow");
       
    } else{
        int y;
        y = st->s[st->top];
        st->top --;
        return y ;
    }
}
void TOH(stack *L, stack *M, stack *R, int n){
    if(n==0){
        return;
    } else{
        TOH(L,R,M,n-1);
        printf ("\n%c -> %c", L->name, R->name);
        int x = pop(L);
        Push(R,x);
        TOH(M,L,R,n-1);
    }
}
void Display(stack *st){
    printf("\n%c - ", st->name);
    if (st->top == -1){
        printf("[EMPTY]");
        return;
    }
    for (int i=st->top; i>=0; i--){
        printf("%d ",st->s[i]);
    }
}
int disks = 3;
stack L, M, R;
int main()
{
    createstack(&L, disks, 'L');
    for(int i = 1;i<=disks;i++){
        Push(&L, i);
    }
    createstack(&M, disks, 'M');
    createstack(&R, disks, 'R');
    printf("\n--- Printing Stack ---");
    Display(&L);
    Display(&M);
    Display(&R);
    printf("\n\n--- Tower of Hanoi Steps ---");
    TOH (&L, &M, &R, disks);

    printf("\n\n--- Printing Stack ---");
    Display(&L);
    Display(&M);
    Display(&R);

    return 0;
}
