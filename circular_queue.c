// Circular Queue Implementation in C
#include <stdio.h>
int N;
int arr[N];
int front = -1;
int rear = -1;
void Enqueue(int x){
    if((front == 0 && rear == N-1)){
        printf("Queue is full\n");
    }else{
        if (front == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear + 1) % N;
        } 
        arr[rear] = x;
    }
void Dequeue(){
    if (front == -1){
        printf("Queue is empty\n");
    }else{
        printf("Dequeued element: %d\n", arr[front]);
        if (front == rear){
            front = -1;
            rear = -1;
        }else{
            front = (front + 1) % N;
        }
    }
}
void display(){
    if (front == -1){
        printf("Queue is empty\n");
    }else{
        printf("Queue elements: ");
        for (int i = front; i != rear; i = (i + 1) % N){
            printf("%d ", arr[i]);
        }
        printf("%d\n", arr[rear]);
    }
}

       

int main(){
    printf("Enter the size of the queue: ");
    scanf("%d", &N);
    int arr[N];
    int front = -1;
    int rear = -1;
    int choice, value;
    scanf("%d", &choice);
    while (choice != 0){
        switch (choice){
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                Enqueue(value);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
                break;
            }
        printf("Enter your choice-: Enqueue, 2: Dequeue, 3: Display, 0: Exit: ");
        scanf("%d", &choice);
    }
    return 0;
}
