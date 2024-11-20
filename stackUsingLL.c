#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
    int data;
    struct stack *next;
} stack;


void push(stack **p, int item) {
    stack *newNode=(stack *)malloc(sizeof(stack));
    if (newNode == NULL) {
        printf("Stack overflow\n");
    } else {
        newNode->data = item;
        newNode->next = *p;
        *p = newNode;
    }
}


int pop(stack **p) {
    stack *temp; // Use only one variable
    int item;

    if (*p == NULL) { // Check if stack is empty
        printf("Stack underflow\n");
        return -1;
    } else {
        temp = *p;      // Assign the top of the stack to temp
        item = temp->data; // Get the data from the top element
        *p = temp->next;   // Move the top pointer to the next element
        free(temp);       // Free the old top element
        return item;      // Return the popped item
    }
}


void display(stack **p) {
    stack *temp;
    temp = *p;
    if (temp == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


int peek(stack **p) {
    if (*p == NULL) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return (*p)->data;
    }
}

int main() {
    stack *head = NULL;
    int choice, value;

    while(1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&head, value);
                break;
            case 2:
                value = pop(&head);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek(&head);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                display(&head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}
