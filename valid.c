#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100


typedef struct {
    char items[MAX];
    int top;
} Stack;


void initStack(Stack* s) {
    s->top = -1;
}


bool isFull(Stack* s) {
    return s->top == MAX - 1;
}


bool isEmpty(Stack* s) {
    return s->top == -1;
}


bool push(Stack* s, char item) {
    if (isFull(s)) return false;
    s->items[++(s->top)] = item;
    return true;
}


char pop(Stack* s) {
    if (isEmpty(s)) return '\0'; 
    return s->items[(s->top)--];
}


bool isValid(char* s) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; s[i] != '\0'; i++) {
        char current = s[i];

        switch (current) {
            case '(': 
            case '{':
            case '[':
                push(&stack, current);
                break;
            case ')': 
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

    return isEmpty(&stack); /

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
