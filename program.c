#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  

int stack[SIZE];  
int top = -1;           
void push(int value) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow! Unable to push %d\n", value);
    } 
    else {
        stack[++top] = value;  
        printf(" Pushed %d \n", value);
    }
}

void pop() {
    if (top < 0) {
        printf("Stack Underflow! Unable to pop.\n");
    } 
    else {
        int value = stack[top--]; 
        printf("Popped %d \n", value);
    }
}

void display() {
    if (top < 0) {
        printf("Stack is empty.\n");
    } 
    else {
        printf("Stack contents: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    

    display();

    pop();
    
    display();

    return 0;
}