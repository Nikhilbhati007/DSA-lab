#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    char* value;
    struct Node* next;
};


struct Queue {
    struct Node *front, *rear;
};


struct Node* newNode(char* value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->value = strdup(value);
    temp->next = NULL;
    return temp;
}


struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}


void enqueue(struct Queue* q, char* value) {
    struct Node* temp = newNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}


char* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;

    struct Node* temp = q->front;
    char* result = strdup(temp->value);
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp->value);
    free(temp);

    return result;
}


void generateBinaryNumbers(int n) {
    struct Queue* q = createQueue();
    enqueue(q, "1");

    for (int i = 0; i < n; i++) {
        char* current = dequeue(q);
        printf("%s\n", current);

        
        char* current0 = (char*)malloc(strlen(current) + 2);
        char* current1 = (char*)malloc(strlen(current) + 2);

        sprintf(current0, "%s0", current);
        sprintf(current1, "%s1", current);

        enqueue(q, current0);
        enqueue(q, current1);

        free(current0);
        free(current1);
        free(current);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    generateBinaryNumbers(n);
    return 0;
}
