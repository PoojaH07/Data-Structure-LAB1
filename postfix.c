#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;


void push(char operator) {
    stack[++top] = operator;
}


char pop() {
    return stack[top--];
}


int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}


int isempty() {
    return top == -1;
}
int isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}


void infixtopostfix(char expression[], char output[]) {
    int j = 0;
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

       
        if (isOperand(ch)) {
            output[j++] = ch;
        }
        
        else if (ch == '(') {
            push(ch);
        }
        
        else if (ch == ')') {
            while (!isempty() && stack[top] != '(') {
                output[j++] = pop();
            }
            pop(); 
        } 
        
        else {
            while (!isempty() && precedence(stack[top]) >= precedence(ch)) {
                output[j++] = pop();
            }
            push(ch);
        }
    }

    
    while (!isempty()) {
        output[j++] = pop();
    }
    output[j] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid parenthesized infix expression: ");
    fgets(infix, sizeof(infix), stdin); 

    infixtopostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}