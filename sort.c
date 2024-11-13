#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
    printf("Memory allocation failed.\n");
    exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtBeginning(Node *head, int value)
{
    Node *newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

Node *concat(Node *head1, Node *head2)
{
    Node *temp = head1;
    while (temp->next != NULL)
    temp = temp->next;
    temp->next = head2;
    return head1;
}
Node *sort(Node *head)
{
    Node *temp, *current;
    int t;
    current = head;
    while (current != NULL)
    {
        temp = head;

        while (temp->next != NULL)

        {
        if (temp->data > temp->next->data)
            {
            t = temp->data;
            temp->data = temp->next->data;
            temp->next->data = t;
            }
        temp = temp->next;
        }
        current = current->next;
    }
    return head;
}

Node *reverse(Node *head)
{
    Node *prev = NULL, *temp, *next;
    temp = head;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    return head;
}
void displayLinkedLists(Node *head1, Node *head2)
{
    printf("Linked List 1: ");
    while (head1 != NULL)
    {
        printf("%d -> ", head1->data);
        head1 = head1->next;
        }
    printf("NULL\n");
    printf("Linked List 2: ");
    while (head2 != NULL)
    {
        printf("%d -> ", head2->data);
        head2 = head2->next;
    }
    printf("NULL\n");
}

int main()
{
Node *list1 = NULL;
Node *list2 = NULL;
list1 = insertAtBeginning(list1, 1);
list1 = insertAtBeginning(list1, 2);
list1 = insertAtBeginning(list1, 3);
list2 = insertAtBeginning(list2, 4);
list2 = insertAtBeginning(list2, 5);
list2 = insertAtBeginning(list2, 6);

displayLinkedLists(list1, list2);
printf("After Sorting:\n");
list1 = sort(list1);
list2 = sort(list2);

displayLinkedLists(list1, list2);

printf("After concatenation:\n");
list1 = concat(list1, list2);
displayLinkedLists(list1,NULL);

printf("After reversing:\n");
list1 = reverse(list1);
displayLinkedLists(list1, list2);
return 0;
}
