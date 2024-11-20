#include <stdio.h>
#include <stdlib.h>

#define SIZE 100  // Maximum size of the queue

typedef struct Queue {
    int items[SIZE];
    int front;
    int rear;
} Queue;

void enqueue(Queue* q, int item);
int dequeue(Queue* q);
void display(Queue* q);

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;

    int ch, item;
    while (1) {
        printf("Enter your choice\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data to be inserted: \n");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2:
                item = dequeue(&q);
                if (item != -1)
                    printf("Dequeued item: %d\n", item);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

void enqueue(Queue* q, int item) {
    if (q->rear == SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) // If queue is empty
        q->front = 0;
    q->rear++;
    q->items[q->rear] = item;
    printf("Inserted %d\n", item);
}

int dequeue(Queue* q) {
    int item;
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) { // Queue becomes empty after dequeuing
        q->front = q->rear = -1;
    }
    return item;
}

void display(Queue* q) {
    if (q->rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: \n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}
