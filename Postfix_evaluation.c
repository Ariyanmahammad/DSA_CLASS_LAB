#include <stdio.h>
#include <ctype.h>  // for isdigit()
#include <stdlib.h> // for atoi()

#define MAX 100

// Stack structure and functions
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char* exp) {
    Stack s;
    init(&s);
    int i = 0;

    while (exp[i] != '\0') {
        char ch = exp[i];

        // Step 4: If operand, push to stack
        if (isdigit(ch)) {
            push(&s, ch - '0');  // Converting char digit to integer
        }
        // Step 5: If operator, pop elements and apply operator
        else {
            int operand2 = pop(&s);
            int operand1 = pop(&s);

            switch (ch) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0)
                        push(&s, operand1 / operand2);
                    else {
                        printf("Division by zero error\n");
                        return -1;
                    }
                    break;
                default:
                    printf("Unknown operator %c\n", ch);
                    return -1;
            }
        }
        i++;
    }

    // Step 6: The final result is in the stack
    return pop(&s);
}

int main() {
    char exp[MAX];
    
    printf("Enter a postfix expression (single digits and operators): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);

    if (result != -1) {
        printf("The result of the postfix evaluation is: %d\n", result);
    }

    return 0;
}
