#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}


void insertLeft(struct Node** head, int target, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    while (temp != NULL) {
        if (temp->data == target) {

            if (temp->prev == NULL) {
                newNode->next = temp;
                temp->prev = newNode;
                *head = newNode;
                return;
            }

            newNode->prev = temp->prev;
            newNode->next = temp;
            temp->prev->next = newNode;
            temp->prev = newNode;
            return;
        }
        temp = temp->next;
    }

    printf("Node with value %d not found.\n", target);
}


void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;

    while (temp != NULL) {
        if (temp->data == value) {

            if (temp->prev == NULL) {
                *head = temp->next;
                if (*head != NULL) {
                    (*head)->prev = NULL;
                }
            } else {
                temp->prev->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }

    printf("Node with value %d not found.\n", value);
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;


    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    printf("Doubly Linked List after creation: \n");
    displayList(head);


    printf("\nInserting 25 to the left of node with value 30:\n");
    insertLeft(&head, 30, 25);
    displayList(head);


    printf("\nDeleting node with value 20:\n");
    deleteNode(&head, 20);
    displayList(head);

    return 0;
}
