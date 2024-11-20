#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char x) {
    
        stack[++top] = x;
    
}


char pop() {
    
        return stack[top--];
    
}


int precedence(char x) {
    if (x == '+' || x == '-') {
        return 1;
    }
    if (x == '*' || x == '/') {
        return 2;
    }
    if (x == '^') {
        return 3;
    }
    return 0;
}


int isRightAssociative(char x) {
    if (x == '^') {
        return 1; // Right associative
    }
    return 0; // Left associative for +, -, *, /
}


void infixToPostfix(char *exp) {
    int i = 0, k = 0;
    char postfix[MAX];

    while (exp[i] != '\0') {
        
        if (isalnum(exp[i])) {
            postfix[k++] = exp[i];
        }
        
        else if (exp[i] == '(') {
            push(exp[i]);
        }
        
        else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); 
        }
        
        else {
            while (top != -1 && precedence(stack[top]) > precedence(exp[i])) {
                postfix[k++] = pop();
            }
            
            while (top != -1 && precedence(stack[top]) == precedence(exp[i]) && !isRightAssociative(exp[i])) {
                postfix[k++] = pop();
            }
            push(exp[i]);
        }
        i++;
    }

    
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; 

    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char exp[MAX];

    printf("Enter infix expression: ");
    scanf("%s", exp);

    infixToPostfix(exp);

    return 0;
}
