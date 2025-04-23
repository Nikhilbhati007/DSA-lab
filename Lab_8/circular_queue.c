#include <stdio.h>
#include <stdlib.h>

int *arr;
int N;
int front = -1;
int rear = -1;

void Enqueue(int x) {
    if ((front == 0 && rear == N - 1) || (rear + 1) % N == front) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % N;
    }
    arr[rear] = x;
}

void Dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued element: %d\n", arr[front]);
    if (front == rear) {
        front = rear = -1; // Reset queue
    } else {
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", arr[i]);
        if (i == rear)
            break;
        i = (i + 1) % N;
    }
    printf("\n");
}

int main() {
    printf("Enter the size of the queue: ");
    scanf("%d", &N);

    arr = (int *)malloc(N * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice, value;
    printf("Enter your choice- 1: Enqueue, 2: Dequeue, 3: Display, 0: Exit: ");
    scanf("%d", &choice);

    while (choice != 0) {
        switch (choice) {
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
        }
        printf("Enter your choice- 1: Enqueue, 2: Dequeue, 3: Display, 0: Exit: ");
        scanf("%d", &choice);
    }

    free(arr);
    return 0;
}
