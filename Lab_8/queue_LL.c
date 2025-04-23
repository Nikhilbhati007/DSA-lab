#include <stdio.h>
struct node{
    int data;
    struct node *next;
    int front;
    int rear;
};
void enqueue(struct node **head, int value){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
        (*head)->front = 0;
        (*head)->rear = 0;
    }else{
        struct node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        (*head)->rear++;
    }
}
void dequeue(struct node **head){
    if(*head == NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
    if(*head != NULL){
        (*head)->front--;
    }
}
void printQueue(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void peek(struct node *head){
    if(head == NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("Front: %d\n", head->data);
}
int main(){
    struct node *head = NULL;
    enqueue(&head, 10);
    enqueue(&head, 20);
    enqueue(&head, 30);
    printQueue(head);
    peek(head);
    dequeue(&head);
    printQueue(head);
    
    return 0;
}