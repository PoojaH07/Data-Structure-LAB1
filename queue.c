#include <stdio.h>
#include <stdbool.h>

#define MAX 10

void insert(int queue[], int *front, int *rear, int val) {
    if (*rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        if (*front == -1 && *rear == -1) {

            *front = *rear = 0;
        } else {

            (*rear)++;
        }
        queue[*rear] = val;
        printf("Inserted %d\n", val);
    }
}

void delet(int queue[], int *front, int *rear) {
    if (*front == -1 || *front > *rear) {
        printf("Queue is underflow\n");
    } else {
        int val = queue[*front];
        printf("Deleted %d\n", val);
        if (*front == *rear) {

            *front = *rear = -1;
        } else {

            (*front)++;
        }
    }
}

void display(int queue[], int front, int rear) {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("The queue are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int queue[MAX];
    int front = -1;
    int rear = -1;

    while (true) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        int option;
        printf("Choose an option: ");
        scanf("%d", &option);

        if (option == 1) {
            int val;
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(queue, &front, &rear, val);
        } else if (option == 2) {
            delet(queue, &front, &rear);
        } else if (option == 3) {
            display(queue, front, rear);
        } else if (option == 4) {
            printf("Exiting the program.\n");
            break; 
        } else {
            printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}