#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct Queue {
    node* front;
    node* rear;
} Queue;

void enqueue(Queue*, int);
int dequeue(Queue*);
void display(Queue*);

int main() {
    int ch, item;
    Queue q;
    q.front = q.rear = NULL;

    while (1) {
        printf("Enter your choice\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2:
                item = dequeue(&q);
                if (item != -1) {
                    printf("Dequeued item: %d\n", item);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

void enqueue(Queue* q, int item) {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;

    if (q->rear == NULL) {  // Empty queue
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", item);
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    node* temp = q->front;
    int item = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {  // If the queue becomes empty
        q->rear = NULL;
    }
    free(temp);
    return item;
}

void display(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    node* temp = q->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
