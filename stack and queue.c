#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};


struct node* head = NULL;
struct node* front = NULL;
struct node* rear = NULL;


void push(int val) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}


void pop() {
    struct node *temp;
    if (head == NULL) {
        printf("Stack is empty!\n");
    } else {
        temp = head;
        printf("Popped element is: %d\n", head->data);
        head = head->next;
        free(temp);
    }
}


void printList() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void enqueue(int val) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;


    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {

        rear->next = newNode;
        rear = newNode;
    }
}


void dequeue() {
    struct node *temp;
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        temp = front;
        printf("Dequeued element is: %d\n", front->data);
        front = front->next;


        if (front == NULL) {
            rear = NULL;
        }
        free(temp);
    }
}

void printLst() {
    struct node* temp = front;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {

    push(10);
    push(20);
    push(30);
    printf("The Stack is: ");
    printList();

    pop();
    printf("After pop, the new stack is: ");
    printList();


    enqueue(40);
    enqueue(50);
    enqueue(60);
    printf("The Queue is: ");
    printLst();

    dequeue();
    printf("After dequeue, the new queue is: ");
    printLst();

    return 0;
}
