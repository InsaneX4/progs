// HUFFMANCODING


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100
#define MAX_TREE_HT 100
struct node
{
    char data;
    int freq;
    struct node *left,*right;
};
struct node *heap[MAX];
int heapsize=-1;
void insert(struct node *element)
{
    heapsize++;
    int now=heapsize;
    while(heap[(now-1)/2]->freq>element->freq)
    {
        heap[now]=heap[(now-1)/2];
        now=(now-1)/2;
    }
    heap[now]=element;
}
struct node *delete()
{
    struct node *minElement,*lastElement;
    int child,now;
    minElement=heap[0];
    lastElement=heap[heapsize--];
    for(now=0;now*2<heapsize;now=child)
    {
        child=now*2+1;
        if(child!=heapsize&&heap[child+1]->freq<heap[child]->freq)
            child++;
        if(lastElement->freq>heap[child]->freq)
            heap[now]=heap[child];
        else
            break;
    }
    heap[now]=lastElement;
    return minElement;
}  
void print(struct node *temp,char *code)
{
    if(temp->left==NULL&&temp->right==NULL)
    {
        printf("%c: %s\n",temp->data,code);
        return;
    }
    int length=strlen(code);
    char leftcode[MAX],rightcode[MAX];
    strcpy(leftcode,code);
    strcpy(rightcode,code);
    leftcode[length]='0';
    leftcode[length+1]='\0';
    rightcode[length]='1';
    rightcode[length+1]='\0';
    print(temp->left,leftcode);
    print(temp->right,rightcode);
}
create_huffman( int a[] , int n){
    min_build_heap(a,n);
    while(n > 1){
        int x = extract_min(a,n);
        int y = extract_min(a,n);
        temp = creat_node();
        temp->left = NULL;
        temp->right = NULL;
        temp->data = '*';
        temp->freq = x+y;
        temp->left = x;
        temp->right = 1;
        insert(a,n,temp);
    }
}

gen_code(str code , node ){

}