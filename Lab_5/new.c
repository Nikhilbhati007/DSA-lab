#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
int main(){
    struct node* head,*temp;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;
    if (head == NULL){
        printf("Memory not allocated\n");
    }
    temp=head;
    for (int i = 2; i <= 5; i++){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = i;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
    return 0;
}