#include <stdio.h>
struct node{
    int data;
    struct node *next;
        
};

int wait = 0;
void enqueue(struct node **head,int x,struct node *front, struct node *rear){
    struct node *n_node,*temp;
    temp = *head;

    wait++;
    n_node = (struct node*)malloc(sizeof(struct node));
    n_node->data = x;
    if (*head == NULL){
        *head = n_node;
        (*head)->next = NULL;
        front = n_node;
        rear = n_node;
        temp = *head;
    }
    else{
        temp->next = n_node;
        n_node->next = NULL;
        rear = n_node;
    }
    printf("enqueue %d\n", x);
}
void dequeue(struct node **head){}
   
int main(){
    return 0;
}