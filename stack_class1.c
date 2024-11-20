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
        printf("%d\n", s->item[s->top]);
        return s->item[s->top];
    }
}

int main() {
    stack s;
    s.top = -1;

    push(&s, 14);
    push(&s, 15);

    int l = pop(&s);
    printf("Popped element: %d\n", l);

    display(&s);

    return 0;
}
