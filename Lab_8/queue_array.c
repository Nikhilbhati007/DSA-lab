#include <stdio.h>
int N;
int stack1[];
int rear= -1;
int front= -1;
void enqueue(int x){
    if(rear==N-1){
        printf("Queue is full\n");
    }
    else{
        if(front==-1){
            front=0;
        }
        rear++;
        stack1[rear]=x;
    }
}
void dequeue(){
    if(front==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("Dequeued element is %d\n",stack1[front]);
        front++;
        if(front>rear){
            front=rear=-1;
        }
    }
}
void display(){
    if(front==-1){
        printf("Queue is empty\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",stack1[i]);
        }
        printf("\n");
    }
}
// Compare this snippet from stack_02.c:
int main(){
    printf("Enter the value of N: ");
    scanf("%d",&N);
    int stack[N];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int x;
        printf("Enter the element: ");
        scanf("%d",&x);
        enqueue(x);
    }
    display();
    dequeue();
    display();

        
    return 0;
}