#include<stdio.h>

#define SIZE 10

typedef struct stack {
    int top;
    int item[SIZE];
} stack;

void push(stack *s, int elem) {
    if (s->top == SIZE - 1) {
        printf("Stack overflowed\n");
    } else {
        s->top++;
        s->item[s->top] = elem;
    }
}

int pop(stack *s) {
    int element;
    if (s->top == -1) {
        printf("Stack underflowed\n");
        return -1;
    } else {
        element = s->item[s->top];
        s->top--;
        return element;
    }
}

void display(stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->item[i]);
        }
        printf("\n");
    }
}

int peep(stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->item[s->top];
    }
}

int main() {
    stack s;
    s.top = -1;
    int choice, elem;

    while (1) {
        printf("Enter your choice:\n1. Push\n2. Pop\n3. Display\n4. Peep\n5. Exit\n");
        printf("your choice is : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &elem);
                push(&s, elem);
                break;

            case 2:
                 if(pop(&s)!=-1){
                   printf("Popped element: %d\n", pop(&s));
                 }
                
                break;

            case 3:
                display(&s);
                break;

            case 4:
              
               
                    printf("Top element: %d\n", peep(&s));
                
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
