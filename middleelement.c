#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of the list
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
void insertAtEnd(struct Node** head, int data){
    struct Node* newNode=createNode(data);

    if(*head==NULL){
        *head=newNode;
        return;
    }

    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newNode;
}

void middleElement(struct Node* head){

    if(head==NULL){
        printf("no element in list\n");
    }
    struct Node* p=head, *temp=head;
    int size=0, n=0;

    while(p){
        size++;
        p=p->next;
    }
    free(p);
    p=NULL;

    n=(size/2);

    for(int i=0;i<=n;i++){
        if(i==n){
            printf("Middle element of LL is: %d",temp->data);
        }
        temp=temp->next;
    }
}

void displayList(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}


int main(){
    struct Node* head=NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);


    printf("List after creation:\n");
    displayList(head);

    middleElement(head);

    return 0;
}
