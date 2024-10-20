#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

typedef struct {
    Stack stack_in;
    Stack stack_out;
} MyQueue;

void initStack(Stack *stack) {
    stack->top = -1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++(stack->top)] = value;
    }
}

int pop(Stack *stack) {
    return stack->data[(stack->top)--];
}

MyQueue* myQueueCreate() {
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    initStack(&queue->stack_in);
    initStack(&queue->stack_out);
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    push(&obj->stack_in, x);
}

int myQueuePop(MyQueue* obj) {
    if (isEmpty(&obj->stack_out)) {
        while (!isEmpty(&obj->stack_in)) {
            push(&obj->stack_out, pop(&obj->stack_in));
        }
    }
    return pop(&obj->stack_out);
}

int myQueuePeek(MyQueue* obj) {
    if (isEmpty(&obj->stack_out)) {
        while (!isEmpty(&obj->stack_in)) {
            push(&obj->stack_out, pop(&obj->stack_in));
        }
    }
    return obj->stack_out.data[obj->stack_out.top];
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(&obj->stack_in) && isEmpty(&obj->stack_out);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}


