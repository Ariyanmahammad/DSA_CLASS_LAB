#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} node;

// Define the list structure
typedef struct list {
    node* head;
    node* tail;
} list;

// Function to create a new node
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the list
void initList(list* l) {
    l->head = NULL;
    l->tail = NULL;
}

// Function to push a value to the front of the list
void pushFront(list* l, int val) {
    node* newNode = createNode(val);
    if (l->head == NULL) {
        l->head = l->tail = newNode;
    } else {
        newNode->next = l->head;
        l->head = newNode;
    }
}

// Function to push a value to the back of the list
void pushBack(list* l, int val) {
    node* newNode = createNode(val);
    if (l->head == NULL) {
        l->head = l->tail = newNode;
    } else {
        l->tail->next = newNode;
        l->tail = newNode;
    }
}

// Function to print the list
void printList(list* l) {
    node* temp = l->head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    list ll;
    initList(&ll);
    pushFront(&ll, 3);
    pushFront(&ll, 2);
    pushFront(&ll, 1);
    pushBack(&ll, 4);
    pushBack(&ll, 5);

    printList(&ll);

    return 0;
}
