#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void push(struct node **top,int data){
    struct node *nnode,*temp;
    nnode=(struct node *)malloc(sizeof(struct node));
    nnode->data=data;
    if (*top==NULL){
        *top=nnode;
        nnode->next=NULL;
    }
    else{
        nnode->next=*top;
        *top=nnode;
    }
}
void Peek(struct node *top){
    if(top==NULL){
        printf("Under flow");
    }else{
        printf("The Peek element is:%d",top->data);
    }
}
void pop(struct node **top){
    struct node *temp;
    temp=*top;
    if(*top==NULL){
        printf("Underflow");
    }else{
        printf("The pop out element of stack:%d\n",(*top)->data);
        *top=(*top)->next;
        free(temp);
    }
}
void display(struct node *top){
    struct node *temp;
    temp=top;
    if(top==NULL){
        printf("Underflow");
    }else{
        while(temp!=NULL){
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