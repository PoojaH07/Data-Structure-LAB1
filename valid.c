#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Stack structure
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is full
bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an item onto the stack
bool push(Stack* s, char item) {
    if (isFull(s)) return false;
    s->items[++(s->top)] = item;
    return true;
}

// Function to pop an item from the stack
char pop(Stack* s) {
    if (isEmpty(s)) return '\0'; // Return null char if stack is empty
    return s->items[(s->top)--];
}

// Function to check if the string of brackets is valid
bool isValid(char* s) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; s[i] != '\0'; i++) {
        char current = s[i];

        switch (current) {
            case '(': // Push open brackets
            case '{':
            case '[':
                push(&stack, current);
                break;
            case ')': // Check for corresponding open brackets
                if (pop(&stack) != '(') return false;
                break;
            case '}':
                if (pop(&stack) != '{') return false;
                break;
            case ']':
                if (pop(&stack) != '[') return false;
                break;
        }
    }

    return isEmpty(&stack); // Valid if stack is empty at the end
}

int main() {
    char s[MAX];
    printf("Enter a string of brackets: ");
    scanf("%s", s);

    if (isValid(s)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }

    return 0;
}
