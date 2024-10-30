#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
    int data; 
    struct Node* next; 
}; 

struct Node* createNode(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  newNode->data = data; 
    newNode->next = NULL; 
    return newNode; 
} 
void insertAtFirst(struct Node** head, int data) { 
    struct Node* newNode = createNode(data); 
    newNode->next = *head; 
    *head = newNode;
}

void deleteFromFirst(struct Node** head) { 
    if (*head == NULL) { 
    printf("List is empty\n"); 
    return; 
    } 
    struct Node* temp = *head; 
    *head = temp->next; 
    free(temp);
} 

void deleteFromEnd(struct Node** head) { 
    if (*head == NULL) { 
    printf("List is empty\n"); 
    return; 
    } 
    struct Node* temp = *head; 
    if (temp->next == NULL) { 
    free(temp); 
    *head = NULL; 
    return; 
    } 
    while (temp->next->next != NULL) { 
    temp = temp->next; 
    } 
    free(temp->next); 
    temp->next = NULL; 
} 

void deleteAtPosition(struct Node** head, int position) {  if (*head == NULL) { 
    printf("List is empty\n"); 
    return; 
    } 
    struct Node* temp = *head; 
    if (position == 0) { 
    deleteFromFirst(head); 
    return; 
    } 
    for (int i = 0; temp != NULL && i < position - 1; i++) { 
    temp = temp->next;
    } 
    if (temp == NULL || temp->next == NULL) { 
    printf("Position out of range\n"); 
    return; 
    } 
    struct Node* next = temp->next->next; 
    free(temp->next); 
    temp->next = next; 
} 

void display(struct Node* head) { 
    struct Node* temp = head; 
    while (temp != NULL) { 
    printf("%d -> ", temp->data); 
    temp = temp->next; 
    } 
    printf("NULL\n"); 
} 

int main() { 
    struct Node* head = NULL; 
    insertAtFirst(&head, 10);
    insertAtFirst(&head, 20);
    insertAtFirst(&head, 30);
    insertAtFirst(&head, 40);
    insertAtFirst(&head, 50);
    printf("the elements of the linked list:\n"); 
    display(head); 
    
    deleteFromFirst(&head);
    printf("Linked list after deleting the first node:\n");
    display(head);
    
    deleteFromEnd(&head);
    printf("Linked list after deleting the last node:\n");
    display(head);
    
    deleteAtPosition(&head, 1);
    printf("Linked list after deleting the node at position 1:\n");
    display(head);
    
    return 0;
}
