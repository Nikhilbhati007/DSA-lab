#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
void push(struct node **top,int data){
    struct node *nnode,*temp;
    temp=*top;
    nnode=(struct node *)malloc(sizeof(struct node));
    nnode->data=data;
    if(*top==NULL){
        *top=nnode;
        nnode->next=NULL;
        nnode->prev=NULL;
    }
    else{
        (*top)->prev=nnode;
        nnode->next=*top;
        nnode->prev=NULL;
        *top=nnode;
}
}
void pop(struct node **top){
    struct node *temp;
    temp=*top;
    if(*top==NULL){
        printf("Underflow");
    }
    else{
        temp=*top;
        printf("Pop out element:%d",(*top)->data);
        *top=(*top)->next;
        (temp->next)->prev=NULL;
        free(temp);

    }
    printf("\n");
}
void display(struct node *top){
    struct node *temp;
    temp=top;
    if(top==NULL){
        printf("Underflow");
    }else{
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(){
    struct node *top=NULL;
    int n,x;
    printf("Enter number of pop operation you want:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Enter data:");
        scanf("%d",&x);
        push(&top,x);
    }
    display(top);
    pop(&top);
    display(top);
    return 0;
}